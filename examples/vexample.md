
# Basic Vector Operations in mātricks 
# Basic Vector Operations in mātricks 

Declaration of vectors v1, v2, v3 

```C++

const int N = 4;

Vector<double> v1(N,"v1");

Vector<double> v2(N,"v2");

Vector<double> v3(N,"v3");

```


initialize each element of v1 

```C++

v1[0] = 1.0;

v1[1] = 2.0;

v1[2] = 3.0;

v1[3] = 4.0;

```

> v1={1,2,3,4}; 


initialize v2 using range function 

```C++

v2 = range<double>(5,8);

> v2={5,6,7,8}; 


initialize v2 using range function 

```C++

v2 = range<double>(4,1);

```

> v2={4,3,2,1}; 


initialize v2 using range 

```C++

v2 = range<double>(400,100,-100);

```

> v2={400,300,200,100}; 


initialize v2 using linspace 

```C++

v2 = linspace<double>(100,400,4);

```

> v2={100,200,300,400}; 


initialize v2 using linspace 

```C++

v2 = linspace<double>(6,3,4);

```

> v2={6,5,4,3}; 


initialize v2 from C-array (careful, no bounds checking!) 

> v2={1.234,101.3,0,-23.4}; 

initialize v2 from std::vector

> v2={-1,-2,-3,-4}; 

initialize v2 from std::valarray
v2={-11,-12,-13,-14}; 

initialize v2 using range<
v2={100,200,300,400}; 

addition of vectors
 v3 = v1 + v2 = {101,202,303,404}

vector subtraction
 v3 = v2 - v1 = {99,198,297,396}

vector (element-wise) multiplication
 v3 = v1 * v2 = {100,400,900,1600}

vector (element-wise) division
 v3 = v2 / v1 = {100,100,100,100}

vector + scalar
 v3 = v2 / v1 = {100,100,100,100}

complicated example#1
 v3 =  3*(v1+v2) + 1000 = {1303,1606,1909,2212}

complicated example#2
 v3 =  -200 + 100*v1 = {-100,0,100,200}

intitialize elements of v2 to the same value
v2 = 1 = {1,1,1,1}
dot product
10
dot product
61
maximum
5
minimum
-100
sum
10
norm
5.47723
vector of integers
{20,19,18,17}
vector of unsigned integers
{5,6,7,8}
converting integer vector to single precision vector and adding a constant
{20.5,19.5,18.5,17.5}
converting double precision vector to extended precision vector and addign a constant
{1.000000000000000001,2.000000000000000001,3.000000000000000001,4.000000000000000001}

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
