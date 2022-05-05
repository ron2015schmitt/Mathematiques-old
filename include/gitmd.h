#ifndef MD_H
#define MD_H




// Utilities for rendering .md markdown for github

namespace md {

#define markdown_preamble()  printf("_This document was generated from the_ C++ _file_ `%s` _using functions and macros in the namespaces_ `mathq::display` _and_ `mathq::md` _in headers_ `\"mathq.h\"` _and_ `\"gitmd.h\"`_respectively._ ",__FILE__);

#define mathq_preamble_old()  printf("_This document was automatically generated from file_ **`%s`** (%s-%s).\n\n",__FILE__, "Mathématiques", vers_mathq)


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
  
#define mathq_toc() mout << std::endl<<"[Table of Contents](README.md)"<< std::endl;

#define mdtitle(str)   mout << "# " << str << " in Mathématiques" << std::endl; write_mdtitle_file(__FILE__,str);
 
#define mdtitle0(str)   mout << "# " << str << std::endl; write_mdtitle_file(__FILE__,str);


#define vspace() mout << "\n<br>\n" << std::endl
#define header1(str)  mout << "# " << str << std::endl
#define header2(str)  mout << "## " << str << std::endl
#define header3(str)  mout << "### " << str << std::endl
#define header4(str)  mout << "#### " << str << std::endl
#define text(str)  mout << str << std::endl

#define codestart(lang) mout << std::string("```") << std::string(lang) << std::endl
#define codemulti(...)  printf("%s;\n",  stringify(__VA_ARGS__)); __VA_ARGS__
#define codemultiwcomment(str,...)  printf("%s; // %s\n",  stringify(__VA_ARGS__),str); __VA_ARGS__

#define codemultiNoteC11Array(...)  printf("%s; // C++11 list\n",  stringify(__VA_ARGS__)); __VA_ARGS__

#define codeend() printf("```\n")
#define code(...)  codestart();codemulti(__VA_ARGS__);codeend()

#define resultstart() printf("**The result is**\n```C++\n")
#define resultstart2(str) printf("**Some expressions with results**%s\n```C++\n",str)
#define resultstart3(str) printf("**Results**%s\n```C++\n", str)
#define resultmulti(...)  printf("  ");disp(__VA_ARGS__)
#define resultend() printf("```\n\n")
#define result(...)  resultstart();resultmulti(__VA_ARGS__);resultend()

#define example(n,str) mout << "**EXAMPLE" << std::setw(2) << n << "**: " << str << std::endl

};

#endif
