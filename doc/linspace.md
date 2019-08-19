
# The `linspace` function in mātricks
_This document was automatically generated from file_ **`linspace.cpp`** (mātricks-v2.2-r13).

* The function `linspace<D>(start,end,N)` returns a `Vector<D>` containing an equispaced sequence of `N` points, from `start` to `end`, spaced by `(start-end)/(N-1)`
* Note that `end` can be less than `start`, in which case the returned sequence is decreasing
```C++
linspace<double>(100,400,4):  {100,200,300,400}; 
linspace<unsigned int>(1,2,2):  {1,2}; 
linspace<double>(0,1,11):  {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1}; 
linspace<double>(1,0,11):  {1,0.9,0.8,0.7,0.6,0.5,0.4,0.3,0.2,0.1,0}; 
```

[Table of Contents](README.md)
