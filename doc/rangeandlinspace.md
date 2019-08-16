
# The `**range**` and `**linspace**` functions in mātricks
This document was automatically generated from file **`rangeandlinspace.cpp`** (mātricks-v2.1-r21).

## Using the `**range**` Function
* For integers `start`, `end`, the `range<D>(start,end)` function returns a Vector<D> containing the numbers {`start`,`start`+1, `start`+2,... , `end`}
```C++
range<int>(1,8): {1,2,3,4,5,6,7,8}; 
range<double>(-3,3): {-3,-2,-1,0,1,2,3}; 
```
* Counting down is also supported
```C++
range<int>(10,0): {10,9,8,7,6,5,4,3,2,1,0}; 
```
* The range<D>(Nstart,Nend,Nstride) function returns a Vector<D> containging the whole numbers from start counting by stride


**EXAMPLE 1**: Assign `Vector`s of various types  using the **`range`** function
```C++
```
Vector<unsigned int> v1 (4);
```
```
v1 = range<unsigned int>(0,3);
```
v1: {0,1,2,3}; 
```
Vector<int> v2 (4);
```
```
v2 = range<int>(0,3);
```
v2: {0,1,2,3}; 
```
Vector<double> v3 (4);
```
```
v3 = range<double>(0,3);
```
v3: {0,1,2,3}; 
```


[Table of Contents](README.md)
