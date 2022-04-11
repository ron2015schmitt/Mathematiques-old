

<details>

  <summary>Table of Contents</summary>

1. [About](about.md)
2. [License](license.md)
3. [Release Notes](release-notes.md)
4. [Example code](examples.md)
5. [Installation](installation.md)
6. [Using Mathématiques](using-mathematiques.md)
7. [Coding Guide / Syntax](coding-guide.md)
8. [Benchmarks](benchmarks.md)
9. [Tests](test.md)
10. [New Feature Schedule](feature-schedule.md)
11. [Developer Guide](developer-guide.md)


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

| ⇦ <br />[7. Coding Guide / Syntax](coding-guide.md)  | [Table Of Contents](README.md)<br />8. Benchmarks<br /><img width=1000/> | ⇨ <br />[9. Tests](test.md)   |
| ----------- | ----------- | ----------- |
