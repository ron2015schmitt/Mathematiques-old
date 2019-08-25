#define MATRICKS_DEBUG 2


#include "matricks.hpp"
using namespace matricks;

#include <iostream>
#include <string>
#include <algorithm>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  
  int Nex = 1;
  
  cr();
  mdtitle("python-like access: negative indices & slices");
  matricks_preamble();

  header2("Element access");

  header3("Positive and negative indices");
  text("Similar to python, mātricks allows negative indices");
  cr();
  text("`v[-1] == v[N-1]` == end element\n");
  text("`v[-2] == v[N-2]` == penultimate element\n");
  text("`v[-N] == v[0]`   == first element\n");
  {
    cr();
    cr();
    example(Nex++,"Positive and negative indices");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codemulti( const int N = v.size() );
    codeend();
    cr();
    
   
    resultstart2("");
    resultmulti( v );
    resultmulti( N );
    resultmulti( v[0] );
    resultmulti( v[1] );
    resultmulti( v[N-1] );
    resultmulti( v[-1] );
    resultmulti( v[-2] );
    resultmulti( v[-N] );
  #if CPP11 == 1
    resultmulti( v[{0,-1}] );
    resultmulti( v[{2,2,-2,-2}] );
  #endif
    resultend();
  }


  {
    cr();
    cr();
    example(Nex++,"Reverse a vector in place.");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codeend();
    cr();
    resultstart();
    resultmulti( v );
    resultend();
    codestart("C++");
    codemulti( for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]) );
    codeend();
    cr();
    resultstart();
    resultmulti( v );
    resultend();
  }




  
  header2("Slices via the `slc` function");

  header3("The `(start,end)` slice");
  text("* The form `v[slc(start,end)]` returns a `Vector` with every element from index=start to index=end, stepping by +1.\n");
  text("* Negative indices are permitted.\n");
  text("* Examples\n");
  text("  * `v[slc(0,-1)]` returns the entire vector\n");
  text("  * `v[slc(0,1)]` returns the first two elements\n");
  text("  * `v[slc(-2,-1)]` returns the last two elements\n");
  text("  *  if you can't count from the starting element to the ending element by +1, then an empty vector is returned.\n");
  {
    cr();
    cr();
    example(Nex++,"slice `v[slc(start,end)]`");
    codestart("C++");
    codemulti( Vector<double> v( range<double>(0,10) ) );
    codeend();
    cr();

    resultstart2("");
    resultmulti( v[slc(2,6)]);
    resultmulti( v[slc(0,-1)]);
    resultmulti( v[slc(0,1)]);
    resultmulti( v[slc(-2,-1)]);
    resultmulti( v[slc(1,0)]);
    resultmulti( v[slc(-1,0)]);
    resultend();
  }


  header3("The `(start,end,step)` slice");
  text("* The form `v[slc(start,end,step)]` returns a `Vector` with every element from index=start to index=end, stepping by step.\n");
  text("* Negative indices are permitted.\n");
  text("* Examples\n");
  text("  * `v[slc(-1,0,-1)]` returns the entire vector in reverse\n");
  text("  * `v[slc(0,-1,2)]` returns the even-index elements\n");
  text("  * `v[slc(1,-1,2)]` returns the odd-index elements\n");
  text("  *  if you can't count from the starting element to the ending element by step, then an empty vector is returned.\n");
  {
    cr();
    cr();
    example(Nex++,"slice `v[slc(start,end,step)]`");
    codestart("C++");
    codemulti( Vector<double> v0(0) );
    codemulti( Vector<double> v1(1,0. ));
    codemulti( Vector<double> v2( range<double>(0,1) ) );
    codemulti( Vector<double> v3( range<double>(0,2) ) );
    codemulti( Vector<double> v4( range<double>(0,3) ) );
    codemulti( Vector<double> v10( range<double>(0,10) ) );
    codeend();
    cr();
    
    resultstart2(": reverse vectors of various lengths using the same slice");
    resultmulti( v0[slc(-1,0,-1)]);
    resultmulti( v1[slc(-1,0,-1)]);
    resultmulti( v2[slc(-1,0,-1)]);
    resultmulti( v3[slc(-1,0,-1)]);
    resultmulti( v4[slc(-1,0,-1)]);
    resultmulti( v10[slc(-1,0,-1)]);
    resultend();

    resultstart2(": get even-index elements of various vectors using the same slice");
    resultmulti( v0[slc(0,-1,2)]);
    resultmulti( v1[slc(0,-1,2)]);
    resultmulti( v2[slc(0,-1,2)]);
    resultmulti( v3[slc(0,-1,2)]);
    resultmulti( v4[slc(0,-1,2)]);
    resultmulti( v10[slc(0,-1,2)]);
    resultend();

    resultstart2(": get odd-index elements of various vectors using the same slice");
    resultmulti( v0[slc(1,-1,2)]);
    resultmulti( v1[slc(1,-1,2)]);
    resultmulti( v2[slc(1,-1,2)]);
    resultmulti( v3[slc(1,-1,2)]);
    resultmulti( v4[slc(1,-1,2)]);
    resultmulti( v10[slc(1,-1,2)]);
    resultend();
}

  matricks_toc();


  return 0;
}
