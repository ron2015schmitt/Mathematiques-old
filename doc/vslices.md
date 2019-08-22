
# python-like access: negative indices & slices in mātricks
_This document was automatically generated from file_ **`vslices.cpp`** (mātricks-v2.7-r16).

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
  v:  {0,1,2,3,4,5,6,7,8,9,10}; 
  N:  11; 
  v[0]:  0; 
  v[1]:  1; 
  v[N-1]:  10; 
  v[-1]:  10; 
  v[-2]:  9; 
  v[-N]:  0; 
  v[{0,-1}]:  {0,10}; 
  v[{2,2,-2,-2}]:  {2,2,9,9}; 
```



**EXAMPLE 2**: Reverse a vector in place.
```C++
Vector<double> v( range<double>(0,10) );
```

**The result is**
```C++
  v:  {0,1,2,3,4,5,6,7,8,9,10}; 
```

```C++
for (int i = 0; i < v.size()/2; i++) std::swap(v[i],v[-i-1]);
```

**The result is**
```C++
  v:  {10,9,8,7,6,5,4,3,2,1,0}; 
```

## Slices via the `slc` function
### The [start,end] slice


**EXAMPLE 3**: slice `v[slc(start,end)]`
```C++
Vector<double> v( range<double>(0,10) );
```

**Some expressions with results**
```C++
  v[slc(2,6)]:  {2,3,4,5,6}; 
```


[Table of Contents](README.md)
