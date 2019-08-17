
# The `linspace` function in mātricks
This document was automatically generated from file **`linspace.cpp`** (mātricks-v2.1-r46).

### Increasing Sequences
* The function `range<D>(start,end)` returns a Vector<D> containing the numbers `{start,start+1, start+2,..., end}`
```C++
range<int>(1,10):  {1,2,3,4,5,6,7,8,9,10}; 
range<double>(-3,3):  {-3,-2,-1,0,1,2,3}; 
```
### Decreasing Sequences
* Counting down is also supported
```C++
range<int>(10,0):  {10,9,8,7,6,5,4,3,2,1,0}; 
```
### Non-integer Sequences
* The start and end need not be integers 
```C++
range<double>(1.5,5.5):  {1.5,2.5,3.5,4.5,5.5}; 
range<double>(5.5,1.5):  {5.5,4.5,3.5,2.5,1.5}; 
```
### Arbitrary stride
* The function `range<D>(Nstart,Nend,Nstride)` returns a Vector<D> containing the numbers `{start,start+stride, start+2*stride,..., end}`
### The end point isn't always included
* The end point is only included when 
```C++
end == start + n * stride
```
where `n` is an integer
Below are two examples where the end point is not included
```C++
range<int>(0,5,2):  {0,2,4}; 
range<double>(1,3.5):  {1,2,3}; 
```
### Initializing `Vector`'s using `range`


**EXAMPLE 1**: Initialize `Vector`'s of various data types  using the *`range`* function
```C++
Vector<unsigned int> v1 ( range<unsigned int>(0,3) );
Vector<int> v2 ( range<int>(0,3) );
Vector<double> v3 ( range<double>(0,3));
```

**The result is**
```C++
  v1:  {0,1,2,3}; 
  v2:  {0,1,2,3}; 
  v3:  {0,1,2,3}; 
```


[Table of Contents](README.md)
