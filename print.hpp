// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================




#ifndef COOLLPRINT_H
#define COOLLPRINT_H


#include <iostream>
#include <cstring>

namespace COOLL {


  // core functions (internal use only)

  //////////////////////////////////////////////////////////////////
  template <typename X>
  void _printvar(const X a, bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename X, unsigned int N>
  void _printvar(X (&a)[N], bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "[]=" ;
    std::cout<<pres;
    std::cout << "{ " ;
    for(unsigned int i = 0; i<N ; i++) {
      std::cout << (a[i]) ;
      if (i != (N-1)) 
	std::cout << " ,";
    }
    std::cout << " } " ;
    std::cout << posts;
  }
  template <unsigned int N>
  void _printvar(const char (&a)[N], bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <unsigned int N>
  void _printvar(char (&a)[N], bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }

 
  template <typename D>
  void _printvar(const Matrix<D>& a, bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename A, typename D>
  void _printvar(const Mexpr<D,A>& exp, bool display, char *s, char* pres, char* posts)
  {
    Matrix<D> a = exp;
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }

  template <typename D>
  void _printvar(const LAvector<D>& a, bool display, char *s, char* pres, char* posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename A, typename D>
  void _printvar(const Vexpr<D,A>& exp, bool display, char *s, char* pres, char* posts)
  {
    LAvector<D> a = exp;
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }



  template <typename X>
  void _printarray(const X *const a,  bool display, char *s,int start, int end, char *ending)
  {
    int i;
    X temp;

    std::cout << s << "[" << start << " to " << end<<"]={";
    for(i = start; i<=end ; i++) {
      temp = a[i];
      std::cout << temp ;
      if (i != end) 
	cout << ",";
    }
    std::cout <<ending;
  }


  //////////////////////////////////////////////////////////////////

  /* "print"
   * each of these functions works for char, strings, ints, floats, doubles, 
   * and any other objects that overload the << operator
   */
#define print(var) _printvar(var,false,"","","")
#define printcr(var) _printvar(var,false,"","","\n")
#define printcrcr(var) _printvar(var,false,"","\n","\n")
#define printarray(var,start,end) _printarray(var,false,# var,start,end,"; \n")

  inline void  cr(void) { std::cout <<std::endl;}


  /* "disp"
   * These functions display the variable/expression and its value
   */
#define disp(var) _printvar(var,true,# var,"","; ")
#define dispcr(var) _printvar(var,true,# var,"","; \n")
#define dispcrcr(var) _printvar(var,true,# var,"\n","; \n")
#define disparray(var,start,end) _printarray(var,true,# var,start,end,"; \n")

	
  template <typename D>
  void _coollinfo(const LAvector<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]"<<", LAvectorID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
    std::cout <<  stream.str() <<std::endl;
  }

  template <typename D>
  void _coollinfo(const p3vector<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]";
    std::cout <<  stream.str() <<std::endl;
  }
  template <typename D>
  void _coollinfo(const Matrix<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.Nrows() << "x" << a.Ncols()<<"]"<<", MatrixID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
    std::cout <<  stream.str() <<std::endl;
  }


#define coollinfo(var) _coollinfo(var,std::string(# var))
  



};


#endif




