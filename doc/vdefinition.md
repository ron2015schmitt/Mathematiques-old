
# Vector definition in mātricks
_This document was automatically generated from file_ **`vdefinition.cpp`** (mātricks-v2.7-r1).

### A `matricks::Vector` wraps a `std::valarray`
* This bears repeating: a `matricks::Vector` wraps a `std::valarray`
* In the example below
  * `valias` is referenced to the valarray inside `vec`.

**EXAMPLE 1**: Getting the `valarray` wrapped by a `Vector`.

```C++
using namespace std;
Vector<double> vec( {0,1,2,3} ); // C++11 list
valarray<double>& valias = vec.getValArray();
vec[1] = -1;
valias[2] = -2;
```

**The result is**
```C++
  vec:  {0,-1,-2,3}; 
  valias[]:  { 0 ,-1 ,-2 ,3 } ; 
```

### Setting and getting the wrapped `valarray`
* In the example below
  * valarray `vaptr` points to a new valarray
  * `vec` is constructed with zero size
  * `vec` is set to wrap `vaptr`
  * `valias` is referenced to the valarray inside `vec`.

**EXAMPLE 2**: Setting and getting the wrapped `valarray`

```C++
using namespace std;
valarray<double>* vaptr = new valarray<double>(4);
Vector<double> vec(0);
vec.setValArray(vaptr);
valarray<double>& valias = vec.getValArray();
(*vaptr)[0] = 99;
vec[1] = 1;
valias[2] = 2;
```

**The result is**
```C++
  *vaptr[]:  { 99 ,1 ,2 ,0 } ; 
  vec:  {99,1,2,0}; 
  valias[]:  { 99 ,1 ,2 ,0 } ; 
```

  * The above code is correct in that it does not delete the object pointed to by `vaptr`.  After calling method `setValArray`, the `Vector` takes ownership and will delete the valarray in its destrcutor.

[Table of Contents](README.md)
