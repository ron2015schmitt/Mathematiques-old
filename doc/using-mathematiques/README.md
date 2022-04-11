

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




# 6. Using Mathématiques


Now that you have completed installation, to use the Mathématiques library you need to 

1. Include the library file `include/mathq.h` in your source code
```C++
#include "mathq.h"
```
2. Include the `include/` subdirectory during compilation using the `-I` option

3. Include the `lib/` subdirectory during linking using the `-L` option

4. Include the option `-lmathq` during linking

## EXAMPLE Makefile

An example makefile, `example/Makefile`, is created during [configuration](configuration) for your convenience.

*AFTER CONFIGURATION*, copy this makefile to YOUR source code directory (or cut and paste into an existing makefile).

Here is an example of a [typical Makefile](doc/sample/Makefile).

## EXAMPLE Code File

An example of a C++ source file can be found at [examples/example.cpp](examples/example.cpp).

Compile the code and run the code using the Makefile
```bash
make example
./example
```

| ⇦ <br />[5. Installation](installation/README.md)  | [Table Of Contents](README.md)<br />6. Using Mathématiques<br /><img width=1000/> | ⇨ <br />[7. Coding Guide / Syntax](coding-guide/README.md)   |
| ----------- | ----------- | ----------- |