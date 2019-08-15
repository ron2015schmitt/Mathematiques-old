
#include <iostream>
#include <string>

// Utilities for redering .md markdown for github

  
#define matricks_preamble()  printf("This document was automatically generated from file **`%s`** (%s-%s).\n\n",__FILE__, "mātricks", vers_matricks)
#define matricks_toc() std::cout << std::endl<<"[Table of Contents](README.md)"<< std::endl;
#define header1(str)  std::cout << "# " << str << std::endl
#define header2(str)  std::cout << "## " << str << std::endl
#define header3(str)  std::cout << "### " << str << std::endl
#define text(str)  std::cout << str << std::endl

#define codestart(lang) std::cout << std::string("```") << std::string(lang) << std::endl
#define codemulti(...)  printf("%s;\n",  #__VA_ARGS__); __VA_ARGS__
#define codeend() printf("```\n")
#define code(...)  codestart();codemulti(__VA_ARGS__);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultmulti(...)  printf("  ");dispcr(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define result(...)  resultstart();resultmulti(__VA_ARGS__);resultend()

#define example(n,str) std::cout << "**EXAMPLE" << std::setw(2) << n << "**: " << str << std::endl
