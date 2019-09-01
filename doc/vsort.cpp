#define MATRICKS_DEBUG 1


#include "matricks.h"

#include <iostream>
#include <string>

// used to demonstrate how to convert to C++ vectors
#include <vector>

#if CPP11 == 1
#include <initializer_list>
#endif



int main()
{
  using namespace matricks;
  using namespace std;
  using namespace display;
  using namespace md;

  int Nex = 1;
  
  cr();
  mdtitle("Methods `Vector.sort()`, `Vector.uniq()`, `Vector.quniq()`  ");
  matricks_preamble();
  header2("Sorting");
  text("* sorting is performed _in place_ via the `.sort()` method");
  cr();
  text("* the indices for the sort are returned in a `Vector<index_type>`");
  cr();
  
#if CPP11 == 1
  {
    cr();
    cr();
    example(Nex++," `Vector.sort()`");
    codestart("C++");
    codemulti( Vector<double> t( {23,-1,100,7}) );
    codemulti( Vector<double> y( {30,10,20,40} ) );
    codemulti( Vector<index_type> vindex );
    codemulti( vindex = t.sort() );
    codemulti( y = y[vindex] );
    codeend();
    cr();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultmulti(y);
    resultend();
  }
#endif

  header2("Removing duplicate elements");
  header3("The `.uniq()` method");
  text("* The `.uniq()` method operates _in place_, removing all duplicate values.");
  cr();
  text("* The indices for the unique elements are returned in a `Vector<index_type>`");
  cr();
  
#if CPP11 == 1
  {
    cr();
    cr();
    example(Nex++,"The `.uniq()` method");
    codestart("C++");
    codemulti( Vector<double> t( {23,-1,23,4,4,4,-1,3,3}) );
    codemulti( Vector<index_type> vindex );
    codemulti( vindex = t.uniq() );
    codeend();
    cr();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultend();
  }
#endif

  header3("The `.quniq()` method");
  text("* The `.quniq()` method operates _in place_, removing all _adjacent_ duplicate values.");
  cr();
  text("* The indices for the unique elements are returned in a `Vector<index_type>`");
  cr();
  
#if CPP11 == 1
  {
    cr();
    cr();
    example(Nex++,"The `.quniq()` method");
    codestart("C++");
    codemulti( Vector<double> t( {23,-1,23,4,4,4,-1,3,3}) );
    codemulti( Vector<index_type> vindex );
    codemulti( vindex = t.quniq() );
    codeend();
    cr();

    resultstart();
    resultmulti(t);
    resultmulti(vindex);
    resultend();
  }
#endif

  
  matricks_toc();


  return 0;
}
