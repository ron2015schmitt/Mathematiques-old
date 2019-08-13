
# Declaring and Assigning Vectors in mātricks 

## Declaring vectors 
Declare vector `v1`. 
```C++
const int N = 4;
Vector<double> v1(N);
```
**The result is**
```C++
  v1: {0,0,0,0}; 
```

When the name is not specified, the pool manager assigns one. 
```C++
Vector<double> x(N);
```
**The result is**
```C++
  x: {0,0,0,0}; 
```

## Assigning the values of a vector 
### Directly assigning the values of a vector 


**EXAMPLE 1**: Set each element of `v1` **individually** 
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

**EXAMPLE 2**: Assigning `v1` from a **C-style array** 
```C++
double temp[N] = {1.234, 101.3, 0, -23.4};
v1 = vcast<double>(temp,N);
```
**The result is**
```C++
  v1: {1.234,101.3,0,-23.4}; 
```

### Using the `range` Function 


**EXAMPLE 3**: Assign `v1` using the **`range`** function 
```C++
v1 = range<double>(5,8);
```

**The result is**
```C++
  v1: {5,6,7,8}; 
```



**EXAMPLE 4**: Assign `v1` using the **`range`** function 
```C++
v1 = range<double>(4,1);
```

**The result is**
```C++
  v1: {4,3,2,1}; 
```



**EXAMPLE 5**: Assign `v1` using the **`range`** function 
```C++
v1 = range<double>(400,100,-100);
```

**The result is**
```C++
  v1: {400,300,200,100}; 
```

### Using the **`linspace`** function 


**EXAMPLE 6**: Assign `v1` using the **`linspace`** function 
```C++
v1 = linspace<double>(100,400,4);
```

**The result is**
```C++
  v1: {100,200,300,400}; 
```



**EXAMPLE 7**: Assign `v1` using the **`linspace`** function 
```C++
v1 = linspace<double>(6,3,4);
```

**The result is**
```C++
  v1: {6,5,4,3}; 
```

Vector<double> v2(N,"v2");
Vector<double> v3(N,"vector3");

initialize v2 from std::vector

**The result is**
```C++
  v2: {-1,-2,-3,-4}; 
```


initialize v2 from std::valarray
v2: {-11,-12,-13,-14}; 

initialize v2 using range<
v2: {100,200,300,400}; 

addition of vectors
 v3 = v1 + v2 = {106,205,304,403}

vector subtraction
 v3 = v2 - v1 = {94,195,296,397}

vector (element-wise) multiplication
 v3 = v1 * v2 = {600,1000,1200,1200}

vector (element-wise) division
 v3 = v2 / v1 = {16.6667,40,75,133.333}

vector + scalar
 v3 = v2 / v1 = {16.6667,40,75,133.333}

complicated example#1
 v3 =  3*(v1+v2) + 1000 = {1318,1615,1912,2209}

complicated example#2
 v3 =  -200 + 100*v1 = {400,300,200,100}

intitialize elements of v2 to the same value
v2 = 1 = {1,1,1,1}
dot product
18
dot product
141
maximum
7
minimum
100
sum
18
norm
9.27362
vector of integers
{20,19,18,17}
vector of unsigned integers
{5,6,7,8}
converting integer vector to single precision vector and adding a constant
{20.5,19.5,18.5,17.5}
converting double precision vector to extended precision vector and addign a constant
{6.000000000000000001,5.000000000000000001,4.000000000000000001,3.000000000000000001}

resize v1: v1.resize(3). Note that all data that as in v1 is lost.
v1 = {0,0,0}

resize to zero to release the memory: v1.resize(0)
this can be used for efficient memory management when working with large vectors
v1 = {}

resize and set v1 froma vector expression
v1.resize() = 2*v2 = {2,2,2,2}

reinitialize v1
{-2,-1,0.1,0.5}

convert v1 to a C-style array of floats
*dat1={-2,-1,0.1,0.5}

round and convert v1 to a std::vector of ints
vstd2={-2,-1,0,1}

convert v1 to a std::valarray of doubles
val2={-2,-1,0.1,0.5}

accessing a range of elements using the seq(start,end)
v7.resize() = v1[seq(1,3)]={-1,0.1,0.5}

zero teh first two elements of v7
v7[seq(0,1)]=0; v7={0,0,0.5}

reverse the order of a vector
v1 = v1[seq(3,0)]={0.5,0.1,-1,-2}
The optional second parameter is the name that will be stored with the vector in the object pool.  This name can be any string that you like. 
There's the macro **`Vector_`** name the vector automatically
 
```C++
Vector_(double, y, N);
```
**The result is**
```C++
  y: {0,0,0,0}; 
```

There's the macro **`Vector2_`** name the vector automatically
 
```C++
RVector2_(double, z, N);
```
**The result is**
```C++
  z: {0,0,0,0}; 
```

