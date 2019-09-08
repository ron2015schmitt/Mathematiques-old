
# Applying User-defined functions in mātricks
_This document was automatically generated from file_ **`vapply.cpp`** (mātricks-v2.14-r18).

As an example, consider the following user-defined function `pos`, which forces negative values to zero.  Mathematically this is x*u(x), where u(x) is the (_Heaviside_) unit step function. 

```C++
template <class D> 
D pos(D x) {
  return (x>=0) ? x : 0;
}
```

**Some expressions with results**: `pos` function
```C++

  pos(-5) = 0; 
  pos(5) = 5; 
```


### Applying User-defined functions via `op1`

* The simplest way to apply a user-defined function is to use the function `op1<D,funcname>(Vector<D> v)`.
* This form can be used in `Vector` expressions

**EXAMPLE 1**: Applying User-defined function `pos` via `op1`

```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<int> v2(range<int>(-2,2));
```

**Some expressions with results**: Applying User-defined function `pos` via `op1`
```C++
  op1<double,pos>(v1) = {0, 0, 0, 0, 0, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  op1<int,pos>(v2) = {0, 0, 0, 1, 2}; 
  2*v1 + op1<double,pos>( 2.3*sin(3.14159265358979323846*v1) ) = {-2, -1.6, -1.2, -0.8, -0.4, 0, 1.75191, 2.98743, 3.38743, 2.95191, 2}; 
```


### Applying User-defined binary functions via `op2`

* A similar function exists for binary user-defined functions: `op2<D,funcname>(Vector<D> v1, Vector<D> v2)`.
* This form can be used in `Vector` expressions as well.

**EXAMPLE 2**: Applying `stdlib` function `fmax` via `op2`
```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<double> v2(11,0.25);
```

**The result is**
```C++
  v1 = {-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  v2 = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25}; 
  op2<double,fmax>(v1,v2) = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.4, 0.6, 0.8, 1}; 
```

### Applying User-defined functions using the `valarray` inside
* Another technique is to use method `getValArray()` and `std::valarray.apply(func)`

**EXAMPLE 3**: Applying User-defined function `pos` via `valarray` access
```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<double> v2;
v2 = v1.getValArray().apply(pos);
```

**The result is**
```C++
  v1 = {-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  v2 = {0, 0, 0, 0, 0, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
```



### Creating new mātricks functions--Under the hood of mātricks

User-defined function can be bound into the `matricks` namespace as vector functions.

place the following code in your file:
```C++
namespace matricks { 

  template <class D> class Ap_pos {
  public:
    Ap_pos() { }

    static inline D apply(D a) { 
      return (a>=0) ? a : 0; 
    }

    static std::string debugtxt( const std::string& sa) {
      std::string sout = "pos(" + sa + ")";
      return sout;
    }

  };

  template <class D, class A> 
  inline VFuncOp<D,VorE<D,A>,Ap_pos<D> > 
  pos(const VorE<D,A>& a) {
    return  VFuncOp<D,VorE<D,A>,Ap_pos<D> >(a);
  }
}
```
**EXAMPLE 4**: Applying User-defined function `pos`
```C++
using namespace std;
Vector<double> v1(linspace<double>(-1,1,11) );
Vector<int> v2(range<int>(-2,2));
```

**Some expressions with results**: Applying User-defined bound-in function `pos` 
```C++
  pos(v1) = {0, 0, 0, 0, 0, 0, 0.2, 0.4, 0.6, 0.8, 1}; 
  pos(v2) = {0, 0, 0, 1, 2}; 
  2*v1 + pos( 2.3*sin(3.14159265358979323846*v1) ) = {-2, -1.6, -1.2, -0.8, -0.4, 0, 1.75191, 2.98743, 3.38743, 2.95191, 2}; 
```


[Table of Contents](README.md)
