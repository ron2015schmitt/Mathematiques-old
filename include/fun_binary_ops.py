#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_binary_op_functor.hpp"
fn_functions = "fun_binary_op_functions.hpp"
fn_output = "fun_binary_ops_AUTO.h"

ops = ["+", "-", "*", "/"]
opnames = ["add", "subtract", "multiply", "divide"]
opcomments = ["Addition", "Subtraction", "Multiplication", "Division"]
optypeclasses = ["AddType", "SubType", "MultType", "DivType"]

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
    fun = fun.replace("##NAME##",opnames[count]);
    fun = fun.replace("##COMMENTNAME##",opcomments[count]);
    fun = fun.replace("##TYPECLASS##",optypeclasses[count]);
    contents += fun
    count += 1

# -----------------------------------------------------
# write to file
# -----------------------------------------------------


fn_output_str=fn_output.upper().split(".")[0]

prologue = """#ifndef MATHQ__"""+fn_output_str+"""_H
#define MATHQ__"""+fn_output_str+"""_H 1

// THIS FILE WAS *AUTO-GENERATED* BY PYTHON SCRIPT '"""+myname+"""'

namespace mathq { 
"""


epilogue = """}; // namespace mathq 
#endif // MATHQ__"""+fn_output_str+"""_H"""



contents = prologue + contents + epilogue

print(contents)
with open(fn_output, 'w') as file_output:
    file_output.write(contents);
