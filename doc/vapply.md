
# Applying User-defined functions in mātricks
_This document was automatically generated from file_ **`vapply.cpp`** (mātricks-v2.1-r86).

As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. 

```C++
 template <class D> 
D pos(D x) {
  return (x>=0) ? x : 0;
}
```

**Some expressions with results**: `pos` function
```C++
  pos(-5):  0; 
  pos(5):  5; 
```


### Applying User-defined functions using `op1`

* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.
* This form can be used in `Vector` expressions
**EXAMPLE 1**: Applying User-defined function `pos` using `op1`
```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<int> v2(range<int>(-1,0,1));
```

**The result is**
```C++
  op1<double,pos>(v1):  {0,0,0,0,0,0,0.2,0.4,0.6,0.8,1}; 
  op1<int,pos>(v2):  {0,0}; 
  2*v1 + op1<double,pos>( 2.3*sin(3.14159265358979323846*v1) ):  {-2,-1.6,-1.2,-0.8,-0.4,0,1.75191,2.98743,3.38743,2.95191,2}; 
```

### Applying User-defined functions using the `valarray` inside
Since 
```C++
struct X {static double increment (double x) {return (x+1);}};
Vector<double> v1({1,2,3,4} );
Vector<double> v2;
v2 = v1.getValArray().apply(X::increment);
```
**The result is**
```C++
  v1:  {1,2,3,4}; 
  v2:  {2,3,4,5}; 
  sin(v1):  {0.841471,0.909297,0.14112,-0.756802}; 
```



[Table of Contents](README.md)
