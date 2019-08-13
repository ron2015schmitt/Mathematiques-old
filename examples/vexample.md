
# Declaring and Assigning Vectors in mātricks 

## Declaring vectors 
Declare vectors `v1`, `v2`, `v3`. 
The optional second parameter is the name that will be stored with the vector in the object pool.  This name can be any string that you like. 
```C++
const int N = 4;
Vector<double> v1(N,"v1");
Vector<double> v2(N,"v2");
Vector<double> v3(N,"vector3");
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
**EXAMPLE 3**: Set `v1` from an array 
```C++
double temp[N] = {1.234, 101.3, 0, -23.4};
v1 = vcast<double>(temp,N);
```
**The result is**
```C++
  v1: {1.234,101.3,0,-23.4}; 
```

### Using the `range` Function 


**EXAMPLE 4**: Assign `v2` using the **`range`** function 
```C++
v2 = range<double>(5,8);
```

**The result is**
```C++
  v2: {5,6,7,8}; 
```



**EXAMPLE 5**: Assign `v2` using the **`range`** function 
```C++
v2 = range<double>(4,1);
```

**The result is**
```C++
  v2: {4,3,2,1}; 
```



**EXAMPLE 6**: Assign `v2` using the **`range`** function 
```C++
v2 = range<double>(400,100,-100);
```

**The result is**
```C++
  v2: {400,300,200,100}; 
```

### Using the **`linspace`** function 


**EXAMPLE 7**: Assign `v2` using the **`linspace`** function 
```C++
v2 = linspace<double>(100,400,4);
```

**The result is**
```C++
  v2: {100,200,300,400}; 
```



**EXAMPLE 8**: Assign `v2` using the **`linspace`** function 
```C++
v2 = linspace<double>(6,3,4);
```

**The result is**
```C++
  v2: {6,5,4,3}; 
```


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
 v3 = v1 + v2 = {101.234,301.3,300,376.6}

vector subtraction
 v3 = v2 - v1 = {98.766,98.7,300,423.4}

vector (element-wise) multiplication
 v3 = v1 * v2 = {123.4,20260,0,-9360}

vector (element-wise) division
 v3 = v2 / v1 = {81.0373,1.97433,inf,-17.094}

vector + scalar
 v3 = v2 / v1 = {81.0373,1.97433,inf,-17.094}

complicated example#1
 v3 =  3*(v1+v2) + 1000 = {1303.7,1903.9,1900,2129.8}

complicated example#2
 v3 =  -200 + 100*v1 = {-76.6,9930,-200,-2540}

intitialize elements of v2 to the same value
v2 = 1 = {1,1,1,1}
dot product
79.134
dot product
11049.2
maximum
102.3
minimum
-2540
sum
79.134
norm
103.975
vector of integers
{20,19,18,17}
vector of unsigned integers
{5,6,7,8}
converting integer vector to single precision vector and adding a constant
{20.5,19.5,18.5,17.5}
converting double precision vector to extended precision vector and addign a constant
{1.233999999999999987,101.2999999999999972,1e-18,-23.39999999999999858}

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
