
#include <iostream>
#include <string>

// Utilities for redering .md markdown for github

#define header1(...)  printf("# %s \n", __VA_ARGS__)
#define header2(...)  printf("## %s \n", __VA_ARGS__)
#define header3(...)  printf("### %s \n", __VA_ARGS__)
#define text(...)  printf("%s \n", __VA_ARGS__)

#define codestart(lang) std::cout << std::string("```") << std::string(lang) << std::string("\n")
#define codemulti(...)  printf("%s;\n",  #__VA_ARGS__); __VA_ARGS__
#define codeend() printf("```\n")
#define code(...)  codestart();codemulti(__VA_ARGS__);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultmulti(...)  printf("  ");dispcr(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define result(...)  resultstart();resultmulti(__VA_ARGS__);resultend()

#define example(n,...) sprintf(_str,"**EXAMPLE%2d**: ",n); text(std::strcat(_str,__VA_ARGS__))

