/*****************************************************************************
00002  *   Copyright (C) 2004-2009 The PaGMO development team,                     *
00003  *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
00004  *   http://apps.sourceforge.net/mediawiki/pagmo                             *
00005  *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
00006  *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
00007  *   act@esa.int                                                             *
00008  *                                                                           *
00009  *   This program is free software; you can redistribute it and/or modify    *
00010  *   it under the terms of the GNU General Public License as published by    *
00011  *   the Free Software Foundation; either version 2 of the License, or       *
00012  *   (at your option) any later version.                                     *
00013  *                                                                           *
00014  *   This program is distributed in the hope that it will be useful,         *
00015  *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
00016  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
00017  *   GNU General Public License for more details.                            *
00018  *                                                                           *
00019  *   You should have received a copy of the GNU General Public License       *
00020  *   along with this program; if not, write to the                           *
00021  *   Free Software Foundation, Inc.,                                         *
00022  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
00023  *****************************************************************************/
00024 
00025 #include <string>
00026 
00027 #include "../exceptions.h"
00028 #include "../types.h"
00029 #include "base.h"
00030 #include "rosenbrock.h"
00031 
00032 namespace pagmo { namespace problem {
00033 
00035 
00042 rosenbrock::rosenbrock(unsigned int n):base(n)
00043 {
00044         // Set bounds.
00045         set_lb(-5.0);
00046         set_ub(10);
00047 }
00048 
00050 base_ptr rosenbrock::clone() const
00051 {
00052         return base_ptr(new rosenbrock(*this));
00053 }
00054 
00056 void rosenbrock::objfun_impl(fitness_vector &f, const decision_vector &x) const
00057 {
00058         const decision_vector::size_type n = x.size();
00059         f[0]=0;
00060         for (decision_vector::size_type i=0; i<n-1; ++i){
00061                 f[0] += 100 * (x[i]*x[i] -x[i+1])*(x[i]*x[i] -x[i+1]) + (x[i]-1)*(x[i]-1);
00062         }
00063 }
00064 
00065 std::string rosenbrock::get_name() const
00066 {
00067         return "Rosenbrock";
00068 }
00069 
00070 }}
