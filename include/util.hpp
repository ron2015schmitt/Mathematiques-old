#ifndef MATRICKS__UTIL_H
#define MATRICKS__UTIL_H


#define CPP11 (__cplusplus >= 201100L)
#define CPP14 (__cplusplus >= 201400L)
#define CPP17 (__cplusplus >= 201700L)


#if CPP11 == 1
#define CARRAY(...) __VA_ARGS__
#else
#define CARRAY(...)  (const double[]) __VA_ARGS__
#endif



#endif
