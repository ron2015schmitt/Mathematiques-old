
# Declaring and Assigning Vectors in mātricks 
This document is automatically generated from file **`vdeclassign.cpp`**:
## Declaring vectors 
**EXAMPLE 1**: Declare vector `v1`. 
```C++
const size_type N = 4;
Vector<double> v1(N);
```
**The result is**
```C++
  v1: {0,0,0,0}; 
```

**EXAMPLE 2**: Declare `v2` and initialize to a constant 
```C++
Vector<double> v2(4, -1 );
```
**The result is**
```C++
  v2: {-1,-1,-1,-1}; 
```

**EXAMPLE 3**: Declare `v3` and initialize to a **C-style array** of values 
```C++
Vector<double> v3( 4, (const double[]) {10, 20, 30, 40} );
```
**The result is**
```C++
  v3: {10,20,30,40}; 
```

**EXAMPLE 4**: Declare `v4` and initialize directly (**__C++11__**) 
```C++
Vector<double> v4({10, 20, 30, 40});
list[0] = 10.000000
list[1] = 20.000000
list[2] = 30.000000
list[3] = 40.000000
```
**The result is**
```C++
  v4: {10,20,30,40}; 
```

## Assigning the values of a vector 
### Directly assigning the values of a vector 


**EXAMPLE 5**: Set each element of `v1` **individually** 
```C++
v1[0] = 1.0;
v1[1] = 2.0;
v1[2] = 3.0;
v1[3] = 4.0;
```

**The result is**
```C++
  v1: {1,2,3,4}; 
```

**EXAMPLE 6**: Assigning `v` from a **C-style array** 
```C++
v2 = Vector<double>( N, (const double[]) {10, 20, 30, 40});
```
**The result is**
```C++
  v2: {10,20,30,40}; 
```

### Using the `range` Function 


**EXAMPLE 7**: Assign `v1` using the **`range`** function 
```
v1 = range<double>(5,8);
```

**The result is**
```C++
  v1: {5,6,7,8}; 
```



**EXAMPLE 8**: Assign `v1` using the **`range`** function 
```
v1 = range<double>(4,1);
```

**The result is**
```C++
  v1: {4,3,2,1}; 
```



**EXAMPLE 9**: Assign `v1` using the **`range`** function 
```
v1 = range<double>(400,100,-100);
```

**The result is**
```C++
  v1: {400,300,200,100}; 
```

### Using the **`linspace`** function 


**EXAMPLE10**: Assign `v1` using the **`linspace`** function 
```
v1 = linspace<double>(100,400,4);
```

**The result is**
```C++
  v1: {100,200,300,400}; 
```



**EXAMPLE11**: Assign `v1` using the **`linspace`** function 
```
v1 = linspace<double>(6,3,4);
```

**The result is**
```C++
  v1: {6,5,4,3}; 
```

