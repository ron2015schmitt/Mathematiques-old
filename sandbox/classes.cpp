#define MATHQ_DEBUG 1
#include "mathq.h"

#include <vector>
#include <string>


class ClassA {
private:
  int value_;
public:
  ClassA() : value_(-1) {
  }

  ClassA(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassA";
  }

  friend std::ostream& operator<<(std::ostream &stream, const ClassA& that) {
    using namespace display;
    
    stream << that.value_;
    return stream;
  }
};



class ClassB {
private:
  int value_;
public:
  // has no effect
  explicit ClassB() : value_(-2) {
  }

  // prevents ClassB b = intval;
  explicit ClassB(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassB";
  }

  friend std::ostream& operator<<(std::ostream &stream, const ClassB& that) {
    using namespace display;
    
    stream << that.value_;
    return stream;
  }
};



class ClassC {
private:
  int value_;
public:
  // has no effect
  explicit ClassC() : value_(-3) {
  }

  explicit ClassC(int value) : value_(value) {
  }

  std::string classname() const {
    return "ClassC";
  }

  ClassC& operator=(const int& n) {
    value_ = n;
    return *this;
  }
  
  friend std::ostream& operator<<(std::ostream &stream, const ClassC& that) {
    using namespace display;
    
    stream << that.value_;
    return stream;
  }
};


class ClassD {
private:
  int value_;
public:
  // has no effect
  explicit ClassD() : value_(-4) {
  }


  std::string classname() const {
    return "ClassD";
  }

  
  friend std::ostream& operator<<(std::ostream &stream, const ClassD& that) {
    using namespace display;
    
    stream << that.value_;
    return stream;
  }
};



  int main(int argc, char *argv[])
  {


  
    const double pi = M_PI;
    std::string myname = argv[0];
    using namespace mathq;
    using namespace display;
    using namespace std;
  
    Style bold = createStyle(BOLD);
  
    // force color even if piped to more,less or a file
    Terminal::setColorOverride(true);
    Terminal::setOverrideValue(true);

    cr();
    cr();
    mout << StyledString::get(HORLINE);
    mout << "running: " <<bold.apply(myname) << std::endl;
    print_mathq_info();
  

    {
      ClassA a;
      tdisp(a);
      tdisp(ClassA());
      tdisp(*(new ClassA()));
    } 

    cr();
    {
      ClassA a(8);
      tdisp(a);
      tdisp(ClassA(8));
      tdisp(*(new ClassA(8)));
    }
    
    cr();
    {
      ClassA a = 100;
      tdisp(a);
    }

    cr();
    {
      ClassA a {101};// works
      tdisp(a);
    }  

    cr();
    {
      ClassA a = {102};  // also works!
      tdisp(a);
    }

    cr();
    {
      ClassB b;
      tdisp(b);
      tdisp(ClassB());
      tdisp(*(new ClassB()));
    }
    cr();
    {
      ClassB b(9);
      tdisp(b);
    }
    cr();
    {
      // error: conversion from ‘int’ to non-scalar type ‘MyClass’ requested
      //ClassB b = 9; 
    }
    cr();
    {
      ClassB b {6};  // works !
      tdisp(b);
    } 


    cr();
    {
      ClassC c;
      tdisp(c);
      tdisp(ClassC());
      tdisp(*(new ClassC()));
    }
    cr();
    {
      ClassC c(10);
      tdisp(c);
      c = 23;
      tdisp(c);      
    }
    cr();
    {
      // still doesn't work. = use the constructor
      //ClassC c = 11; 
      //tdisp(c);
    }

    cr();
    {
      ClassD d;
      tdisp(d);
    }

    cr();
    {
      // doesn't work
      //ClassD d {22};
      //tdisp(d);
    }

  
    cr();
    mout << "done: " << bold.apply(myname) << std::endl;
    mout << StyledString::get(HORLINE);
    cr();
    return 0;
  }
