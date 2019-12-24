#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_ternary_functor.hpp"
fn_functions = "fun_ternary_functions.hpp"
fn_output = "fun_ternary_AUTO.h"
namespace = "mathq"


funcs = [
["std::sph_legendre","sph_legendre", "MultType"],
["std::assoc_legendre","assoc_legendre", "MultType"],
["std::assoc_laguerre","assoc_laguerre", "MultType"],
["std::ellint_3","ellint_3", "MultType"],
["std::comp_ellint_3","comp_ellint_3", "MultType"]
]


contents = "";

# -----------------------------------------------------
# functors
# -----------------------------------------------------
contents += """


//********************************************************************
//--------------------------------------------------------------------
//                        Functors
//--------------------------------------------------------------------
//********************************************************************


"""


with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read();

contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);
    
count = 0;
for func in funcs:
    fun = contents0
    fun = fun.replace("##FUNCTION##",func[0]);
    fun = fun.replace("##NAME##",func[1]);
    contents += fun
    count += 1

    

# -----------------------------------------------------
# functions
# -----------------------------------------------------
contents += """


//********************************************************************
//--------------------------------------------------------------------
//                           Functions
//--------------------------------------------------------------------
//********************************************************************


"""
with open(fn_functions, 'r') as file_functions:
    contents0 = file_functions.read();

contents0 = contents0.replace("##MYFILENAME##",fn_functions);
contents0 = contents0.replace("##SCRIPTNAME##",myname);


count = 0;
for func in funcs:
    fun = contents0
    fun = fun.replace("##OP##",func[1]);
    fun = fun.replace("##FUNCTION##",func[1]);
    fun = fun.replace("##NAME##",func[1]);
    fun = fun.replace("##COMMENTNAME##",func[1]);
    fun = fun.replace("##TYPECLASS##",func[2]);
    contents += fun
    count += 1


    
# -----------------------------------------------------
# write to file
# -----------------------------------------------------


fn_output_str=fn_output.upper().split(".")[0]

NAMESPACE = namespace.upper()
defvar = NAMESPACE+"__"+fn_output_str+"_H"

prologue = """#ifndef """+defvar+"""
#define """+defvar+""" 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT '"""+myname+"""'

namespace """+namespace+""" { 
"""


epilogue = """}; // namespace mathq 
#endif // """+defvar



contents = prologue + contents + epilogue

print(contents)
with open(fn_output, 'w') as file_output:
    file_output.write(contents);
