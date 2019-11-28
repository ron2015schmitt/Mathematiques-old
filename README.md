# mātricks v2.29-r15

This is an experimential branch comparing two different methods for implemeneting addition between two vectors of type `Vector<Vector<double>>`.

1. recursion ？⸺ compiles but get core dump "bad alloc" error
1. deep indexing ✓ ⸺ got this working 

## Test code

The test code is in file `sandbox/recurseadd.cpp`
```c++
    Vector<Vector<double>> v1(N1);
    Vector<Vector<double>> v2(N1);
    Vector<Vector<double>> v3(N1);
    Vector<Vector<double>> v4(N1);
    for (int i = 0; i < N1; i++) {
      v1[i].resize(N2);
      v1[i][0] = 1.1;
      v1[i][1] = 2.2;
      v1[i][2] = 3.3;
      v2[i].resize(N2);
      v2[i][0] = 10;
      v2[i][1] = 20;
      v2[i][2] = 30;
      v3[i].resize(N2);
      v4[i].resize(N2);
    }

  // Recursive add
   v3.equals1( add1(v1,v2) );
      
      // deep indexing
   v4.equals2( add2(v1,v2) );

```

## functions

The are the add functions, in `functions.h`

**add1** -- recursive add
```c++
  template <class D1, class D2, class A, class B> 
    inline auto add1(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
    {
      return  TER_Binary<typename AddType<D1,D2>::Type,TensorR<D1,A>,TensorR<D2,B>,Fun_Add_New<D1,D2> >(a,b);
    }
```

and 

**add2** -- deep indexing add
```c++
    template <class D1, class D2, class A, class B> 
    inline auto add2(const TensorR<D1,A>& a, const TensorR<D2,B>& b)
    {
      using namespace display;
      // mout<< a << createStyle(BOLD).apply("+") << b << std::endl;
      return  TER_Binary<
	typename AddType<D1,D2>::Type,
	TensorR<D1,A>,
	TensorR<D2,B>,
	Fun_Add_New<
	  typename NumberType<D1>::Type,
	  typename NumberType<D2>::Type
	>
      >(a,b);
    }

```



## Recursion

* In this method we let the compiler just compile recursive expression templates
* This compiles, but whenever the code passes an expression template as a return value (from functor `.apply()` or expression template operator `[n]`, it core dumps a `what()? bad_alloc`.  I implementeed a copy constructor for the expression but still got the error.  Perhaps also need a copy `equals` method?

In `vector.h`  **equals1** 
```c++
  // FOR EXPERIMENTING
  template <class A, class D2>  Vector<D,NN,M>& equals1(const TensorR<D2,A>& x) {  
    if constexpr(M<2) {
	for (index_type i = 0; i < size(); i++) {
	  mout << "equals1: i="<<i << std::endl;
	  (*this)[i] = x[i];
	}
    } else {
	for (index_type i = 0; i < size(); i++) {
	  mout << "equals1: i="<<i << std::endl;
	  (*this)[i] = x[i];
	}
    }
    return *this;
  }

  }
  ```
  
  
  
  ## Deep indexing


* In this method we calculate the total number of elements in the entire structure and using a method `deepsize()`
* Access these elements by utilizing method `.dat(n)` in `Vector`:
```c++
  MyNumberType& dat(const index_type n) {
    using namespace::display;
    //    mout << createStyle(BOLD).apply("operator["+num2string(n)+"] #1")<<std::endl;
    if constexpr(M < 2) {
      int k = n;
      if (k < 0) {
	  k += size();
      }
      return data_[k];
    } else {
      const int Ndeep = this->eldeepsize();
      const int j = n / Ndeep;
      const int k = n % Ndeep;
      return data_[j][k];
    }
  }
```

* when caculating an expression, loop over the entire deepsize inside the `=` operator.

In `vector.h` **equals2** 
```c++
  template <class A, class D2>  Vector<D,NN,M>& equals2(const TensorR<D2,A>& x) {  
    if constexpr(M<2) {
      for (index_type i = 0; i < size(); i++)  (*this)[i] = x[i];   
    } else {
      for (index_type i = 0; i < deepsize(); i++)  (*this).dat(i) = x.dat(i);       }
    return *this;
  }
  ```


