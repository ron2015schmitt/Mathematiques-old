
#ifndef MATRICKS_PRINT_H
#define MATRICKS_PRINT_H


#include <iostream>
#include <cstring>

namespace Matricks {


  // core functions (internal use only)

  //////////////////////////////////////////////////////////////////
  template <typename X>
  void _printvar(const X a, bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename X, size_type N>
  void _printvar(X (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "[]=" ;
    std::cout<<pres;
    std::cout << "{ " ;
    for(size_type i = 0; i<N ; i++) {
      std::cout << (a[i]) ;
      if (i != (N-1)) 
	std::cout << " ,";
    }
    std::cout << " } " ;
    std::cout << posts;
  }
  template <size_type N>
  void _printvar(const char (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <size_type N>
  void _printvar(char (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }

 
  template <typename D>
  void _printvar(const Matrix<D>& a, bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename A, typename D>
  void _printvar(const Mexpr<D,A>& exp, bool display, char const *s, char const *pres, char const *posts)
  {
    Matrix<D> a = exp;
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }

  template <typename D>
  void _printvar(const Vector<D>& a, bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename A, typename D>
  void _printvar(const Vexpr<D,A>& exp, bool display, char const *s, char const *pres, char const *posts)
  {
    Vector<D> a = exp;
    if (display)
      std::cout << s << "=" ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }



  template <typename X>
  void _printarray(const X *const a,  bool display, char const *s,int start, int end, char const *ending)
  {
    int i;
    X temp;

    std::cout << s << "[" << start << " to " << end<<"]={";
    for(i = start; i<=end ; i++) {
      temp = a[i];
      std::cout << temp ;
      if (i != end) 
	std::cout << ",";
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
  void _matricksinfo(const Vector<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]"<<", VectorID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
    std::cout <<  stream.str() <<std::endl;
  }

  template <typename D>
  void _matricksinfo(const p3vector<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.size() <<"]";
    std::cout <<  stream.str() <<std::endl;
  }
  template <typename D>
  void _matricksinfo(const Matrix<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "': "<< a.fullclassname()  << "[size=" << a.Nrows() << "x" << a.Ncols()<<"]"<<", MatrixID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
    std::cout <<  stream.str() <<std::endl;
  }


#define matricksinfo(var) _matricksinfo(var,std::string(# var))
  



};


#endif




