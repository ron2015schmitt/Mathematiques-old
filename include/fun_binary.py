#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_binary_op_functor.hpp"
fn_functions = "fun_binary_functions.hpp"
fn_output = "fun_binary_AUTO.h"
namespace = "mathq"

ops = ["+", "-", "*", "/", "==", "!=", ">", ">=", "<", "<=", "&&", "||"]
opnames = ["add", "subtract", "multiply", "divide","equals","notequals","greater","greatereq","less","lesseq","and","or"]
opcomments = ["Addition", "Subtraction", "Multiplication", "Division","Equal to","Not equal to","Greater than","Greater than or equal to", "Less than","Less than or equal to", "And", "Or"]
optypeclasses = ["AddType", "SubType", "MultType", "DivType", "RelType", "RelType", "RelType", "RelType", "RelType", "RelType","AndType","OrType"]

contents = "";

# -----------------------------------------------------
# functors
# -----------------------------------------------------
contents += """


//********************************************************************
//--------------------------------------------------------------------
//                           Functors
//--------------------------------------------------------------------
//********************************************************************


"""
with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read();

contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);

count = 0;
for op in ops:
    opname = opnames[count]
    fun = contents0
    fun = fun.replace("##OP##",op);
    fun = fun.replace("##NAME##",opname);
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

contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);

count = 0;
for op in ops:
    fun = contents0
    fun = fun.replace("##OP##",op);
    fun = fun.replace("##FUNCTION##","operator"+op);
    fun = fun.replace("##NAME##",opnames[count]);
    fun = fun.replace("##COMMENTNAME##",opcomments[count]);
    fun = fun.replace("##TYPECLASS##",optypeclasses[count]);
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
