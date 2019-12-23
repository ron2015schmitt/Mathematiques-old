#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_unary_functor.hpp"
fn_functions = "fun_unary_functions.hpp"
fn_output = "fun_unary_AUTO.h"
namespace = "mathq"

ops = ["+", "-", "!"]
opnames = ["pos", "neg", "not"]
optypeIN = ["D", "D", "D"]
optypeOUT = ["D", "D", "D"]


funcs = ["std::exp"]
funcnames = ["exp"]
functypeIN = ["D"]
functypeOUT = ["D"]





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
for op in ops:
    opname = opnames[count]
    fun = contents0
    fun = fun.replace("##FUNCTION##",op);
    fun = fun.replace("##NAME##",opname);
    contents += fun
    count += 1



contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);
    
count = 0;
for func in funcs:
    fun = contents0
    fun = fun.replace("##FUNCTION##",func);
    fun = fun.replace("##NAME##",funcnames[count]);
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
    fun = fun.replace("##FUNCTION##","operator"+op);
    fun = fun.replace("##NAME##",opnames[count]);
    fun = fun.replace("##COMMENTNAME##",opnames[count]);
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+opnames[count]);
    fun = fun.replace("##DIN##",optypeIN[count]);
    fun = fun.replace("##DOUT##",optypeOUT[count]);
    contents += fun
    count += 1

count = 0;
for func in funcs:
    fun = contents0
    fun = fun.replace("##FUNCTION##",funcnames[count]);
    fun = fun.replace("##NAME##",funcnames[count]);
    fun = fun.replace("##COMMENTNAME##",funcnames[count]);
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+funcnames[count]);
    fun = fun.replace("##DIN##",functypeIN[count]);
    fun = fun.replace("##DOUT##",functypeOUT[count]);
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
