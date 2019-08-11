#include <stddef.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <freehdl/fire-types.h>

static void *fire_xmalloc (size_t s)
{
  static char msg[] = "virtual memory exhausted\n";
  void *mem = malloc (s);
  if (mem == NULL)
    {
      write (2, msg, sizeof(msg)-1);
      exit (1);
    }
  return mem;
}

IR_String::IR_String (const IR_Character *chars, int l)
{
  rep = (strrep *) fire_xmalloc (sizeof(strrep)+sizeof(IR_Character)*l);
  rep->len = l;
  rep->ref_count = 1;
  memcpy (rep->chars, chars, sizeof(IR_Character)*l);
  rep->chars[l] = '\0';
}

IR_String::IR_String (const char *chars)
{
  int l = strlen (chars);
  rep = (strrep *) fire_xmalloc (sizeof(strrep)+sizeof(IR_Character)*l);
  rep->len = l;
  rep->ref_count = 1;
  memcpy (rep->chars, chars, sizeof(IR_Character)*l);
  rep->chars[l] = '\0';
}

IR_String::IR_String (const IR_String &str)
{
  rep = str.rep;
  rep->ref_count++;
}

IR_String::~IR_String ()
{
  if(--rep->ref_count == 0)
    free (rep);
}

IR_String &
IR_String::operator= (const IR_String &str)
{
  str.rep->ref_count++;
  if (--rep->ref_count == 0)
    free (rep);
  rep = str.rep;
  return *this;
}

char *
IR_String::to_chars ()
{
  for (int i = 0; i < rep->len; i++)
    if (rep->chars[i] == '\0')
      abort ();
  return (char *)rep->chars;
}

std::ostream&
operator<< (std::ostream& o, IR_String& str)
{
  return o << str.to_chars();
}

void
fire_print_bool (void *mem)
{
  printf ("%s", (*(bool *)mem)? "true":"false");
}

void
fire_print_int (void *mem)
{
  printf ("%d", *(int *)mem);
}

void
fire_print_string (void *mem)
{
  printf ("\"%s\"", *(char **)mem);
}

void
fire_print_IR_String (void *mem)
{
  printf ("\"%s\"", (*(IR_String *)mem).to_chars());
}
