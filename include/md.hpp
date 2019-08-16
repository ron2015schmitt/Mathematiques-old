
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>


// Utilities for rendering .md markdown for github


#define matricks_preamble()  printf("This document was automatically generated from file **`%s`** (%s-%s).\n\n",__FILE__, "mātricks", vers_matricks)

inline void write_mdtitle_file (std::string fname, std::string title) {
  using namespace std;
  ofstream myfile;
  size_t N = fname.length();
  string basename = fname.substr(0,N-4);
  string outname = basename  +  ".link_md"; 
  myfile.open (outname);
  myfile << "1. ["+title+"]"+"("+basename+".md)"<<endl;
  myfile.close();
}
  
#define matricks_toc() std::cout << std::endl<<"[Table of Contents](README.md)"<< std::endl;

#define mdtitle(str)   std::cout << "# " << str << " in mātricks" << std::endl; write_mdtitle_file(__FILE__,str);
 

#define header1(str)  std::cout << "# " << str << std::endl
#define header2(str)  std::cout << "## " << str << std::endl
#define header3(str)  std::cout << "### " << str << std::endl
#define text(str)  std::cout << str << std::endl

#define codestart(lang) std::cout << std::string("```") << std::string(lang) << std::endl
#define codemulti(...)  printf("%s;\n",  #__VA_ARGS__); __VA_ARGS__
#define codemultiwcomment(str,...)  printf("%s; // %s\n",  #__VA_ARGS__,str); __VA_ARGS__
#define codeend() printf("```\n")
#define code(...)  codestart();codemulti(__VA_ARGS__);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultstart2(str) printf("**Some expressions with results**%s\n```C++\n",str)
#define resultmulti(...)  printf("  ");dispcr(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define result(...)  resultstart();resultmulti(__VA_ARGS__);resultend()

#define example(n,str) std::cout << "**EXAMPLE" << std::setw(2) << n << "**: " << str << std::endl
