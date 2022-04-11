

<details>

  <summary>Table of Contents</summary>

1. [About](about/README.md)
2. [License](license/README.md)
3. [Release Notes](release-notes/README.md)
4. [Example code](examples/README.md)
5. [Installation](installation/README.md)
6. [Using Mathématiques](using-mathematiques/README.md)
7. [Coding Guide / Syntax](coding-guide/README.md)
8. [Benchmarks](benchmarks/README.md)
9. [Tests](test/README.md)
10. [New Feature Schedule](feature-schedule/README.md)
11. [Developer Guide](developer-guide/README.md)


</details>




# 8. Benchmarks



## Vector math benchmarks 

Here we compare _Mathematiques_ vs. a handcoded `C` array loops.

### mathq syntax 
```C++
Vector<double> x(N);
x = linspace<double>(0,1,N);
Vector<double> f(N);
start();
f = cos(2*pi + pi*sin(2*pi*x + pi/6));
stop();
```

### hand-coded `C` loop 
```C++
std::valarray<double> x(N);
for(int i=0; i<N; i++)
  x[i] = double(i)/double(N-1);
std::valarray<double> f(N);
start();
for(int i=0; i<N; i++)
     f[i] = cos(2*pi + pi*sin(2*pi*x[i] + pi/6));
stop();
```
### results

![benchmarks](../files/benchmark.png)


## dot product benchmarks
---------------------------------------------------------------------------
To be written...

| ⇦ <br />[7. Coding Guide / Syntax](coding-guide/README.md)  | [Table Of Contents](README.md)<br />8. Benchmarks<br /><img width=1000/> | ⇨ <br />[9. Tests](test/README.md)   |
| ----------- | ----------- | ----------- |
