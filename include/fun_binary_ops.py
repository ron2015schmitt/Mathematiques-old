#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_binary_op_functor.hpp"
fn_output = "fun_binary_functors.hpp"

ops = ["+", "-", "*", "/"]
opnames = ["add", "subtract", "multiply", "divide"]


with open(fn_functor, 'r') as file_functor:
    contents0 = file_functor.read();
contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);
contents = "";

count = 0;
for op in ops:
    opname = opnames[count]
    fun = contents0
    fun = fun.replace("##OP##",op);
    fun = fun.replace("##NAME##",opname);
    contents += fun
    count += 1



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
