/* mapping.cc - implement the mapping from lib/unit to file.

   Copyright (C) 2000, 2003 Marius Vollmer.

   V2CC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   V2CC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with V2CC; see the file COPYING.  If not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.
*/

// XXX - this whole thing needs serious performance improvements.  At
//       least a cache of previously unsucessful lookups should be
//       maintained.

// XXX - it also needs a much better way of handling errors.

#include "mapping.h"

#include <string>
#include <list>
#include <map>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

v2cc_mapper::v2cc_mapper ()
{
}

v2cc_mapper::~v2cc_mapper ()
{
}

#define me v2cc_mapper_impl

struct me : v2cc_mapper {

  me ();
  ~me ();

  char *find_design_file (const char *lib, const char *unit);

  void add_libdir (const char *libdir);
  void add_libdir (const string libdir);
  void add_default_libdirs ();

  list<string> libdirs;

  bool translate (string &res, string lib, string map, string ext);

  struct mapfile {

    struct rule {
      string pattern;
      string subst;
      bool has_subst;
    };

    list<rule> rules;

    bool parse (string file);
    bool translate (string &res, string str, string ext);

  private:
    bool next_token (string &buf, istream &on);
    bool match (string p, string s, map<string,string> &matches);
    bool match (string p, int pp, string s, int ss, 
		map<string,string> &matches);
    string subst (string t, map<string,string> &matches);
  };

  map<string,mapfile*> mapfiles;

  mapfile *get_mapfile (string);
  void remember (mapfile*, string);
};

me::me ()
{
}

me::~me ()
{
}

v2cc_mapper *
make_v2cc_mapper ()
{
  return new me;
}

void
me::add_libdir (const char *libdir)
{
  add_libdir (string (libdir));
}

void
me::add_libdir (const string libdir)
{
  libdirs.push_back (libdir);
}

void
me::add_default_libdirs ()
{
  const char *ext = getenv ("V2CC_LIBRARY_PATH");

  if (ext == NULL)
    ext = "*";

  for (const char *start = ext, *stop = start; *start; start = stop)
    {
      while (*stop && *stop != ':')
	stop++;

      if (*start == '*' && stop == start+1)
	add_libdir (DEFAULT_V2CC_LIBRARY_DIR);
      else
	add_libdir (string (start, stop-start));

      if (*stop)
	stop++;
    }
}

static char *
xstrdup (string &str)
{
  int len = str.length();
  char *mem = new char[len+1];
  str.copy (mem, len);
  mem[len] = '\0';
  return mem;
}

static bool
file_exists (const string &f)
{
  struct stat st;
  return (stat (f.c_str(), &st) == 0);
}

static bool
is_regular_file (const string &f)
{
  struct stat st;
  return (stat (f.c_str(), &st) == 0) && S_ISREG (st.st_mode);
}

static bool
is_directory (const string &f)
{
  struct stat st;
  return (stat (f.c_str(), &st) == 0) && S_ISDIR (st.st_mode);
}


// Stores list of translated library/unit to file name values
map<string, string> design_file_name_cache;

char *
me::find_design_file (const char *lib, const char *unit)
{
  // Query file name cache
  string key = ":" + string(lib) + ":" + string(unit);
  map<string, string>::iterator iter = design_file_name_cache.find(key);
  if (iter != design_file_name_cache.end()) {
    // cerr << (*iter).second << " exists (found in file name cache)\n";
    return xstrdup ((*iter).second);
  }

  for (list<string>::iterator i = libdirs.begin(); i != libdirs.end(); i++)
    {
      const string l = *i;
      // cerr << "looking into " << l << "\n";

      string lmap;
      if (is_regular_file (l))
	lmap = l;
      else if (is_directory (l))
	lmap = l + "/v2cc.libs";
      else
	continue;
      // cerr << "using lmap " << lmap << "\n";

      string flib;
      if (!translate (flib, lib, lmap, ""))
	continue;

      // cerr << lib << " translates to " << flib << "\n";

      string umap = flib + ".vhdl";
      if (file_exists (umap))
	{
	  // cerr << umap << " exists\n";
	  design_file_name_cache[key] = umap; // Add entry to cache
	  return xstrdup (umap);
	}

      umap = flib + ".v2cc";
      if (file_exists (umap))
	;
      else if (is_directory (flib))
	umap = flib + "/v2cc.units";
      else
	continue;
      // cerr << "using umap " << umap << "\n";

      string funit;
      if (!translate (funit, unit, umap, ".vhdl"))
	continue;

      design_file_name_cache[key] = funit; // Add entry to cache
      return xstrdup (funit);
    }

  // cerr << "not found\n";
  return NULL;
}

static string
directory_name (string file)
{
  int pos = file.rfind ('/');
  if (pos == -1)
    return ".";
  else
    return file.substr (0, pos);
}

static string
canonicalize (string ostr)
{
  string str = ostr;
  string::iterator p = str.begin();
  if (*p != '\\' && *p != '\'')
    while (p != str.end())
      {
	*p = tolower (*p);
	p++;
      }
  return str;
}

bool
me::translate (string &res, string str, string map, string ext)
{
  str = canonicalize (str);

  if (!file_exists (map))
    res = str + ext;
  else
    {
      mapfile *m = get_mapfile (map);
      if (m == NULL)
	{
	  m = new mapfile;
	  if (!m->parse (map))
	    {
	      delete m;
	      return false;
	    }
	  remember (m, map);
	}

      if (!m->translate (res, str, ext))
	return false;
    }

  if (res[0] != '/')
    res = directory_name (map) + "/" + res;

  return true;
}

/* Mapfile parser. */

me::mapfile *
me::get_mapfile (string filename)
{
  return mapfiles[filename];
}

void
me::remember (mapfile *map, string filename)
{
  mapfiles[filename] = map;
}

static inline bool
is_whitespace (char c)
{
  return (c == ' ' || c == '\n' || c == '\t'
	  || c == '\f' || c == '\v');
}

static inline bool
is_comment (char c)
{
  return c == '#';
}

static inline bool
is_operator (char c)
{
  return c == ':' || c == ',' || c == '{' || c == '}';
}

static inline bool
is_symbolchar (char c)
{
  return !(is_whitespace (c) || is_operator (c) || is_comment (c));
}

bool
me::mapfile::next_token (string &buf, istream &in)
{
  int c;

  buf.erase ();

  // skip whitespace and comments

  while ((c = in.get()) != EOF)
    {
      if (c == '\\')
	break;
      if (is_comment (c))
	{
	  while ((c = in.get()) != EOF && c != '\n')
	    ;
	  continue;
	}

      if (!is_whitespace (c))
	break;
    }

  if (in.eof())
    return false;

  // read token, either a symbol or an operator

  buf.append (1, char(c));

  if (is_operator (c))
    return true;
  
  while ((c = in.get()) != EOF)
    {
      if (c == '\\')
	if ((c = in.get()) != EOF)
	  {
	    buf.append (1, char(c));
	    continue;
	  }
	else
	  break;
      
      if (!is_symbolchar (c))
	{
	  in.putback (c);
	  break;
	}

      buf.append (1, char(c));
    }

  return buf.length() > 0;
}

bool
me::mapfile::parse (string filename)
{
  string token (128, '\0');
  ifstream in(filename.c_str());

  if (!next_token (token, in) || token != "v2cc_mapfile")
    {
      cerr << filename << ": not a v2cc mapfile\n";
      return false;
    }
  
  if (!next_token (token, in) || token != "0")
    {
      cerr << filename << ": incompatible mapfile version " << token << "\n";
      return false;
    }

  while (next_token (token, in))
    {
      rule r;
      r.pattern = token;
      if (next_token (token, in) && token == ":")
	{
	  if (!next_token (token, in))
	    {
	      cerr << filename << ": missing substitution template\n";
	      return false;
	    }
	  r.subst = token;
	  r.has_subst = true;
	}
      else
	r.has_subst = false;
      rules.push_back (r);
    }

  return true;
}

bool
me::mapfile::translate (string &res, string str, string ext)
{
  for (list<rule>::iterator i = rules.begin(); i != rules.end(); i++)
    {
      map<string,string> matches;
      if (match (i->pattern, str, matches))
	{
	  if (i->has_subst)
	    res = subst (i->subst, matches);
	  else
	    res = str + ext;
	  return true;
	}
    }

  return false;
}

bool
me::mapfile::match (string p, string s, map<string,string> &matches)
{
  return match (p, 0, s, 0, matches);
}

bool
me::mapfile::match (string p, int pp, string s, int sp, 
		    map<string,string> &matches)
{
  // cerr << "trying " << p << " " << pp << ", " << s << ", " << sp << "\n";

  while (pp < p.length() && sp < s.length() && p[pp] != '<')
    {
      if (p[pp] != s[sp])
	{
	  // cerr << "no match " << p[pp] << " " << s[sp] << "\n";
	  return false;
	}
      pp++, sp++;
    }

  if (pp == p.length() || sp == s.length())
    {
      //cerr << "at end " << pp << "(" << p.length() << "), "
      //     << sp << "(" << s.length() << ")\n";
      return pp == p.length() && sp == s.length();
    }

  if (p[pp] == '<')
    {
      int ps = pp;
      while (++pp < p.length() && p[pp] != '>')
	;
      if (pp == p.length())
	{
	  cerr << "unbalanced angle brackets in pattern: " << p << "\n";
	  return false;
	}
      string name = p.substr(ps, pp+1-ps);
      
      if (pp+1 == p.length())      // matches everything till end
	{
	  //cerr << "found: " << name << " == " << s.substr(sp, s.length()-sp)
	  //     << "\n";
	  matches[name] = s.substr(sp, s.length()-sp);
	  return true;
	}

      ++pp;
      if (p[pp] == '<')
	{
	  cerr << "can't have two consecutive wildcards\n";
	  return false;
	}

      int ss = sp;
      while (sp < s.length ())
	{
	  while (sp < s.length() && s[sp] != p[pp])
	    sp++;
	  if (match (p, pp, s, sp, matches))
	    {
	      //cerr << "found: " << name << " == " << s.substr(ss, sp-ss)
	      //	   << "\n";
	      matches[name] = s.substr(ss, sp-ss);
	      return true;
	    }
	  sp++;
	}

      return false;
    }

  return true;
}

string
me::mapfile::subst (string t, map<string,string> &matches)
{
  string r = "";
  for (int tp = 0; tp < t.length();)
    {
      if (t[tp] == '<')
	{
	  int ts = tp;
	  while (tp < t.length() && t[tp] != '>')
	    tp++;
	  if (tp == t.length())
	    {
	      cerr << "unbalanced angle brackets: " << t << "\n";
	      return "";
	    }
	  string name = t.substr(ts, tp+1-ts);
	  map<string,string>::iterator m = matches.find (name);
	  if (m == matches.end())
	    {
	      cerr << "no such wildcard: " << name << "\n";
	      return "";
	    }
	  r = r + m->second;
	  tp++;
	}
      else
	{
	  int ts = tp;
	  while (tp < t.length() && t[tp] != '<')
	    tp++;
	  r += t.substr(ts, tp-ts);
	}
    }

  return r;
}
