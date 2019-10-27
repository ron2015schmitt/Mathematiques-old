# Refactor getTypeName

1. If class does not implement method "classname()", then just print typeid(x).name(), instead of producing a compile error.

   * one way to do this is to have every class that implements classname() inherit from an abstract class with virtual method
   * another way is to just directly test using type traits 

From (https://dev.krzaq.cc/post/checking-whether-a-class-has-a-member-function-with-a-given-signature/)
```C++
template<typename T>
struct has_size_method
{
private:
	typedef std::true_type yes;
	typedef std::false_type no;
 
	template<typename U> static auto test(int) -> decltype(std::declval<U>().size() == 1, yes());
 
	template<typename> static no test(...);
 
public:
 
	static constexpr bool value = std::is_same<decltype(test<T>(0)),yes>::value;
};
```

See also (https://gist.github.com/fenbf/d2cd670704b82e2ce7fd)
