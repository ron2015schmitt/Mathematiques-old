

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

| ⇦ <br />[10. New Feature Schedule](feature-schedule.md)  | [Table Of Contents](README.md)<br />11. Developer Guide<br /><img width=1000/> | ⇨ <br />   |
| ----------- | ----------- | ----------- |
