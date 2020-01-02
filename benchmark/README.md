# Benckmarks


# vector math benchmarks vs. a handcoded for loop. (-O3 optimization):
![benchmarks](files/benchmark.png)

where the second code comparision is hand-coded loop 
```C++
std::valarray<double> x(N);
for(int i=0; i<N; i++)
  x[i] = double(i)/double(N-1);
std::valarray<double> f(N);
start_timer();
for(int i=0; i<N; i++)
     f[i] = cos(2*pi + pi*sin(2*pi*x[i] + pi/6));
stop_timer();
```

vs mathq syntax 
```C++
Vector<double> x(N);
x = linspace<double>(0,1,N);
Vector<double> f(N);
start();
f = cos(2*pi + pi*sin(2*pi*x + pi/6));
stop();
```

# dot product benchmarks

---------------------------------------------------------------------------
