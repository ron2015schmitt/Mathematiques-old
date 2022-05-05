

## Introduction

<br>

## Size of complex numbers
The size of a complex number is simply _twice_ the size of the underlying arithmetic type:


```C++
CHAR_BIT = 8 bits

CHAR_BIT*sizeof(int) = 32 bits
CHAR_BIT*sizeof(complex<int>) = 64 bits

CHAR_BIT*sizeof(double) = 64 bits
CHAR_BIT*sizeof(complex<double>) = 128 bits

CHAR_BIT*sizeof(long double) = 128 bits
CHAR_BIT*sizeof(complex<long double>) = 256 bits

```
The symbol [```CHAR_BIT```](https://en.cppreference.com/w/cpp/header/climits) yields the number of bits per byte, and the C++ function [```sizeof()```](https://en.cppreference.com/w/cpp/language/sizeof) yields the size in _bytes_ of the argument, which can be a type, variable, or expression.


<br>

## Operators and functions
### Arithmetic Operators
Complex numbers in C++ support the 4 standard arithmetic operators.

For details refer to [Arithmetic Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic).


| operator | operation | 
| :---: | :---: | 
| ```+``` | addition | 
| ```-``` | subtraction | 
| ```*``` | multiplication | 
| ```/``` | division | 

```C++
complex(1.0,1.0) + complex(2.0,4.0) => (3,5)
complex(1.0,1.0) - complex(2.0,4.0) => (-1,-3)
complex(1.0,1.0) * complex(2.0,4.0) => (-2,6)
complex(1.0,1.0) / complex(2.0,4.0) => (0.3,-0.1)
```

<br>

### Exponentiation and the ```pow``` function
C++ does not have an exponentiation operator.  Instead it provides the [```std::pow```](https://en.cppreference.com/w/cpp/numeric/complex/div) function
```C++
pow(complex(1.0,1.0), complex(2.0,4.0)) => (-0.084961,0.0158558)
```

<br>

### Relational Operators
Complex numbers are not an ordered set.  Therefore, there is no concept of greater than or less than.

For details refer [Comparison Operators](https://en.cppreference.com/w/c/language/operator_comparison).


| operator | operation | 
| :---: | :---: | 
| `==` | equal to | 
| `!=` | not equal to | 

Examples:

```C++

complex(1.0,1.0) == complex(1.0,1.0) => 1
complex(1.0,1.0) != complex(1.0,1.0) => 0

complex(1.0,1.0) == complex(2.0,4.0) => 0
complex(1.0,1.0) != complex(2.0,4.0) => 1
```

<br>

### Mathematical functions from the C++ [``std::complex`` header](https://en.cppreference.com/w/cpp/numeric/complex)
#### C++ ``std`` library common functions

The following are [common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math) implemented in the C++ `std` library

| function | name | 
| :---: | :---: | 
| `abs` | [absolute value](https://en.cppreference.com/w/cpp/numeric/complex/abs) | 
| `ceil` | [ceiling function](https://en.cppreference.com/w/cpp/numeric/complex/ceil) | 
| `floor` | [floor function](https://en.cppreference.com/w/cpp/numeric/complex/floor) | 
| `trunc` | [truncate function](https://en.cppreference.com/w/cpp/numeric/complex/trunc) | 
| `round` | [round function](https://en.cppreference.com/w/cpp/numeric/complex/round) | 


*Trig Functions*

| function | name | 
| :---: | :---: | 
| `sin` | [sine](https://en.cppreference.com/w/cpp/numeric/complex/sin) | 
| `cos` | [cosine](https://en.cppreference.com/w/cpp/numeric/complex/cos) | 
| `tan` | [tangent](https://en.cppreference.com/w/cpp/numeric/complex/tan) | 


*Inverse Trig Functions*

| function | name | 
| :---: | :---: | 
| `asin` | [arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asin) | 
| `acos` | [arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acos) | 
| `atan` | [arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atan) | 


*Hyperbolic Trig Functions*

| function | name | 
| :---: | :---: | 
| `sinh` | [Hyperbolic sine](https://en.cppreference.com/w/cpp/numeric/complex/sinh) | 
| `cosh` | [Hyperbolic cosine](https://en.cppreference.com/w/cpp/numeric/complex/cosh) | 
| `tanh` | [Hyperbolic tangent](https://en.cppreference.com/w/cpp/numeric/complex/tanh) | 


*Inverse Hyperbolic Trig Functions*

| function | name | 
| :---: | :---: | 
| `asinh` | [Hyperbolic arc sine](https://en.cppreference.com/w/cpp/numeric/complex/asinh) | 
| `acosh` | [Hyperbolic arc cosine](https://en.cppreference.com/w/cpp/numeric/complex/acosh) | 
| `atanh` | [Hyperbolic arc tangent](https://en.cppreference.com/w/cpp/numeric/complex/atanh) | 


*Exponentiation*

| function | name | 
| :---: | :---: | 
| `pow(x, y)` | [x<sup>y</sup>](https://en.cppreference.com/w/cpp/numeric/complex/pow) | 
| `sqrt` | [Square Root](https://en.cppreference.com/w/cpp/numeric/complex/sqrt) | 


*Exponentials*

| function | name | 
| :---: | :---: | 
| `exp` | [e<sup>x</sup>](https://en.cppreference.com/w/cpp/numeric/complex/exp) | 


*Logarithms*

| function | name | 
| :---: | :---: | 
| `log` | [Natural Logarithm, ln(x) = log<sub>e</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log) | 
| `log10` | [base 10 logarithm, log<sub>10</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log10) | 
| `log2` | [base 2 logarithm, log<sub>2</sub>(x)](https://en.cppreference.com/w/cpp/numeric/complex/log2) | 



| function | description | 
| :---: | :---: | 
| `sgn(x)` | [signum function](https://en.wikipedia.org/wiki/Sign_function), return type has same type as x | 
| `zero(x)` | return a zero with the same type as x | 
| `sqr(x)` | x<sup>2</sup> | 
| `cube(x)` | x<sup>3</sup> | 



<br>

## More on types
### Type information
#### typeid
The function [`std::typeid`](https://en.cppreference.com/w/cpp/language/typeid) returns an object of type [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) (defined in the header `<typeinfo>`). 
This gives the type for any varable. However, the names are garbled compiler strings that are not pretty. 

Examples:

```C++
int n = 3;
typeid(n).name() -> "i"
string s = "hello";
typeid(s).name() -> "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"
```
#### getTypeName
The function `mathq::display::getTypeName` returns a string that gives the actual human-readable type name. It works for most [fundamental types](https://en.cppreference.com/w/cpp/language/types) and all classes defined in 
Examples:

```C++
int n = 3;
getTypeName(n) -> "int"
string s = "hello";
getTypeName(s) -> "std::string"
```

<br>

### Mixed-typed math and auto-promotion

C++ automatically converts number types depending on context.
This is referred to as [implicit conversion](https://en.cppreference.com/w/c/language/conversion).
For example, when adding an integer and a floating point number, the integer is first converted to a floating point type before the addition takes place.
As another example, when adding two integers (or floating point types) of different sizes, the smaller size is first converted to the larger size. This porces is referred to as _promotion_.
Examples:

```C++
short n1 = 3;
int n2 = 100;
n1 * n2 -> int 300

float x1 = 3;
double x2 = 0.1415;
x1 + x2 -> double 3.1415

int8_t y1 = 25;
double y2 = 0.25;
y1 / y2 + y2 -> double 100.25
```

<br>

### Type Conversion
There are various ways to cast one type to another in C++.  
Here we demonstrate [explicit conversion](https://en.cppreference.com/w/cpp/language/explicit_cast), which has two forms for the syntax: `(type) expression` or  `type(expression)` 


Converting a floating point type to an integer:

```C++
int n1 = (int)3.14;
n1 -> 3
int n2 = int(3.14);
n2 -> 3
```
Forcing floating point division by converting the numerator to a `float`

```C++
double x = (21 + 1) / 7;
x -> 3
double y = float(21 + 1) / 7;
y -> 3.14286
```
