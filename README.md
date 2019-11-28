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

# Addition functor

The functor is the same, `Fun_Add_New` in `functors.h`
```c++
  template <class D1, class D2> class Fun_Add_New {
  public:
    Fun_Add_New() { }
  
    static inline auto apply(const D1 a, const D2 b) {
      tdisp(a);
      tdisp(b);
      typename AddType<D1,D2>::Type v1 = a + b;   // this works fine
      tdisp(v1);
      return a+b;   // the return from here causes bad_alloc
    }
}
```

# Expression Template 

The expression template is the same, `` in `expresssions.h`
```c++
  template<class D, class A, class B, class OP, int M>
    class TER_Binary : public  TensorR<D,TER_Binary<D,A,B,OP,M> > {

  private:
    const A* a_;
    const B* b_;
    VectorofPtrs *vptrs;

  public:
    typedef typename NumberType<D>::Type MyNumberType;
    typedef D TypeD;
    typedef A TypeA;
    typedef B TypeB;
    TER_Binary()
      : a_(nullptr), b_(nullptr)
      {
	vptrs=nullptr;
      }

  TER_Binary(const A& a, const B& b)
    : a_(&a), b_(&b) {
      vptrs = new VectorofPtrs();
      vptrs->add(a.getAddresses());
      vptrs->add(b.getAddresses());
    }
  TER_Binary(const TER_Binary<D,A,B,OP,M>& e):a_(e.a_), b_(e.b_)  {
      vptrs = new VectorofPtrs();
      vptrs->add(a_->getAddresses());
      vptrs->add(b_->getAddresses());
    }

    ~TER_Binary() {
      delete vptrs;
    }

    //**********************************************************************
    //************************** DEEP ACCESS *******************************
    //**********************************************************************
    const MyNumberType dat(const index_type i) const {
      return OP::apply((*a_).dat(i), (*b_).dat(i));
    }

    //**********************************************************************
    //***************** Element ACCESS *************************************
    //**********************************************************************
    const D operator[](const index_type i) const {
      disp(i);
      tdisp((*a_)[i]);
      tdisp((*b_)[i]);
      return OP::apply((*a_)[i], (*b_)[i]);   // the return from here causes a bad_alloc
    }
    
    VectorofPtrs getAddresses(void) const {
      return *vptrs;
    }
    size_type size(void) const {
      return (*a_).size();
    }
    size_type ndims(void) const {
      return (*a_).ndims();
    }
    Dimensions dims(void) const {
      return (*a_).dims();
    }
    bool isExpression(void) const {
      return true;
    }
  size_type depth(void) const {
      return M;
    }
  size_type elsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_->elsize();
    }
  }
  size_type eldeepsize(void) const {
    if constexpr(M<2) {
      return 1;
    } else {
      return a_->eldeepsize();
    }
  }
    size_type deepsize(void) const {
      if constexpr(M<2) {
	  return this->size();
	} else {
	return (this->size())*(this->eldeepsize());
      }
    }
  };

```


## Method 1: Recursion 

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
  
  
  
  ## Method 2: Deep indexing


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


