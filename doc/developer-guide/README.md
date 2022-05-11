<h1 style='border: 2px solid; text-align: center'>Mathématiques v3.5.39</h1>

<details>

<summary>User Guide</summary>

# [User Guide](../README.md)<br>
1. [About](../about/README.md)<br>
2. [License](../license/README.md)<br>
3. [Release Notes](../release-notes/README.md)<br>
4. [Installation](../installation/README.md)<br>
5. [Makefile / Using Mathématiques](../using-mathematiques/README.md)<br>
6. [Code Examples](../examples/README.md)<br>
7. [Coding Guide / Syntax](../coding-guide/README.md)<br>
8. [Benchmarks](../benchmarks/README.md)<br>
9. [Tests](../test/README.md)<br>
10. [New Feature Plans](../feature-schedule/README.md)<br>
11. _Developer Guide_ <br>


</details>



# 11. Developer Guide


*in progress...*

## Topics to cover

1. ```configure```, ```deconfigure```, ```reconfigure```
3. Makefiles
4. Use of Python for metacoding
   1. use `python3` not `python` in code
   2. how to run
6. git tag versioning: ```files.matricks.vers```, ```reconfigure``` and ```make git```
7. multi-threading
8. directories:
   1. ```example```
   1. ```test``` (including metacode for test generation)
   1. ```benchmark```
   1. ```doc``` as well as scripts ```build``` and ```build1``` and ```toc```
   1. ```sandbox```

# Release Checklist

* Update `files/matricks.vers`
* `reconfigure`
* update README
* Update docs
* git push
* clone from github into a separate directory and verify all code compiles and works

# Online Documentation

When adding or removing chapters in the main TOC
+ edit the `CHAPTERS` variable in `doc/Makefile`
+ edit the `doc/toc.txt`


| ⇦ <br />[New Feature Plans](../feature-schedule/README.md)  | [User Guide](../README.md)<br />Developer Guide<br /><img width=1000/> | ⇨ <br />   |
| ------------ | :-------------------------------: | ------------ |

