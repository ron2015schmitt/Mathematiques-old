
# python-like access: negative indices, slices, lists in mātricks
_This document was automatically generated from file_ **`vslices.cpp`** (mātricks-v2.7-r8).

## Element access
### Positive and negative indices
Similar to python, mātricks allows negative indices

`v[-1] == v[N-1]` == end element

`v[-2] == v[N-2]` == penultimate element

`v[-N] == v[0]`   == first element



**EXAMPLE 1**: Positive and negative indices
```C++
Vector<double> v( range<double>(0,10) );
const int N = v.size();
```

**Some expressions with results**
```C++
  v:  ; 
  N:  11; 
  v[0]:  0; 
  v[1]:  1; 
  v[N-1]:  10; 
  v[-1]:  10; 
  v[-2]:  9; 
  v[-N]:  0; 
```



**EXAMPLE 2**: Reverse a vector in place.
```C++
Vector<double> v( range<double>(0,10) );
```

**The result is**
```C++
  v:  ; 
```

```C++
for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]);
```

**The result is**
```C++
  v:  ; 
```

### Access vector elements using a `Vector` or a C++11 `initializer_list` of indices

* The list can be smaller than or greater than or equal to the length to the vector!
* The list can have repeated indices and indices can be in any order!


**EXAMPLE 3**: Access via a C++11 initializer_list
```C++
Vector<double> v( linspace<double>(0,1,11) );
v:  ; 
Vector<index_type> vi( range<index_type>(0,10,2) );
vi:  ; 
```

**The result is**
```C++
  v:  ; 
  vi:  ; 
  v[vi]:  {0,0.2,0.4,0.6,0.8,1}; 
  v[{0,4}]:  {0,0.4}; 
  v[{4,0,1,4}]:  {0.4,0,0.1,0.4}; 
  v[{0,-1}]:  {0,1}; 
  v[{2,2,2,2,2,2,-2,-2,-2,-2,-2,-2}]:  {0.2,0.2,0.2,0.2,0.2,0.2,0.9,0.9,0.9,0.9,0.9,0.9}; 
```

## Slices
### The [start,end] slice


**EXAMPLE 4**: slice `v[start,end]`
```C++
Vector<double> v( range<double>(0,10) );
```

**Some expressions with results**
```C++
  v[seq(2,6)]:  {2,3,4,5,6}; 
```


[Table of Contents](README.md)
