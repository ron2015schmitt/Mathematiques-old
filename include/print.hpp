
#ifndef MATRICKS_PRINT_H
#define MATRICKS_PRINT_H


#include <iostream>
#include <cstring>

namespace matricks {


  // core functions (internal use only)

  //////////////////////////////////////////////////////////////////
  template <size_type N>
  void _printvar(const char (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s ;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <size_type N>
  void _printvar(char (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }

 
  template <typename D>
  void _printvar(const Matrix<D>& a, bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }
  template <typename A, typename D>
  void _printvar(const Mexpr<D,A>& exp, bool display, char const *s, char const *pres, char const *posts)
  {
    Matrix<D> a = exp;
    if (display)
      std::cout << s;
    std::cout<<pres;
    std::cout << a;
    std::cout << posts;
  }


  template <typename X>
  void _printvar(const X x, bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s;
    std::cout<<pres;
    std::cout << x;
    std::cout << posts;
  }

  template <typename X, size_type N>
  void _printvar(X (&a)[N], bool display, char const *s, char const *pres, char const *posts)
  {
    if (display)
      std::cout << s << "[]" ;
    std::cout<<pres;
    std::cout << "{ " ;
    for(index_type i = 0; i<N ; i++) {
      std::cout << (a[i]) ;
      if (i != (N-1)) 
	std::cout << " ,";
    }
    std::cout << " } " ;
    std::cout << posts;
  }

  template <typename D>
  void _printvar(const std::valarray<D>& va, bool display, char const *s, char const *pres, char const *posts)
  {
    const size_t N = va.size();
    if (display)
      std::cout << s << "[]" ;
    std::cout<<pres;
    std::cout << "{ " ;
    for(index_type i = 0; i<N ; i++) {
      std::cout << (va[i]) ;
      if (i != (N-1)) 
	std::cout << " ,";
    }
    std::cout << " } " ;
    std::cout << posts;
  }

  
  template <typename X>
  void _printarray(const X *const a,  bool display, char const *s,index_type start, index_type end, char const *pres, char const *posts)
  {
    index_type i;
    X temp;

    if (display) {
      std::cout << s << "[" << start << " to " << end<<"]";
    }
    std::cout << pres;
    std::cout << "{";
    for(i = start; i<=end ; i++) {
      temp = a[i];
      std::cout << temp ;
      if (i != end) 
	std::cout << ",";
    }
    std::cout << posts;
  }




  
  //////////////////////////////////////////////////////////////////

  /* "print"
   * each of these functions works for char, strings, ints, floats, doubles, 
   * and any other objects that overload the << operator
   */
#define print(var) _printvar(var,false,"","","")
#define printcr(var) _printvar(var,false,"","","\n")
#define printcrcr(var) _printvar(var,false,"","\n","\n")
#define printarray(var,start,end) _printarray(var,false,# var,start,end,"","; \n")

  inline void  cr(void) { std::cout <<std::endl;}


  /* "disp"
   * These functions display the variable/expression and its value
   */
#define disp(...) _printvar(__VA_ARGS__,true,stringify(__VA_ARGS__),":  ","; ")
#define dispcr(...) _printvar(__VA_ARGS__,true,stringify(__VA_ARGS__),":  ","; \n")
#define dispcrcr(...) _printvar(__VA_ARGS__,true,stringify(__VA_ARGS__),":\n","; \n")
#define disparray(var,start,end) _printarray(var,true,# var,start,end,":  ","; \n")

	
  template <typename D>
  void _matricksinfo(const Vector<D>& a, std::string varname)
  {
    std::ostringstream stream;
    stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.size() <<"]"<<", VectorID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
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
    stream <<"SUMMARY for '" << varname << "':  "<< a.fullclassname()  << "[size=" << a.Nrows() << "x" << a.Ncols()<<"]"<<", MatrixID=" << a.objectID()<<", "<< varname<<".name() = "<<'"' << a.name()<<'"';
    std::cout <<  stream.str() <<std::endl;
  }


#define matricksinfo(var) _matricksinfo(var,std::string(# var))
  

#ifdef MEBUG_LEVEL1
#define print1(...) printf(__VA_ARGS__)
#else
#define print1(...) {}
#endif
#ifdef MEBUG_LEVEL2
#define print2(...) printf(__VA_ARGS__)
#else
#define print2(...) {}
#endif
  


};


#endif




