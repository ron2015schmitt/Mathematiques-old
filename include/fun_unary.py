#!/usr/bin/python

import os
from string import Template

myname = os.path.basename(__file__)
fn_functor = "fun_unary_functor.hpp"
fn_functions = "fun_unary_functions.hpp"
fn_output = "fun_unary_AUTO.h"
namespace = "mathq"

ops = [
["+", "pos", "D", "D"],
["-", "neg", "D", "D"],
["!", "not", "D", "D"]
]


funcs = [
["std::sin", "sin", "D", "D"],
["std::cos", "cos", "D", "D"],
["std::tan", "tan", "D", "D"],
["std::asin", "asin", "D", "D"],
["std::acos", "acos", "D", "D"],
["std::atan", "atan", "D", "D"],
["std::sinh", "sinh", "D", "D"],
["std::cosh", "cosh", "D", "D"],
["std::tanh", "tanh", "D", "D"],
["std::asinh", "asinh", "D", "D"],
["std::acosh", "acosh", "D", "D"],
["std::atanh", "atanh", "D", "D"],
["std::sqrt", "sqrt", "D", "D"],
["std::cbrt", "cbrt", "D", "D"],
["mathq::sqr", "sqr", "D", "D"],
["mathq::cube", "cube", "D", "D"],
["std::exp", "exp", "D", "D"],
["std::exp2", "exp2", "D", "D"],
["std::expm1", "expm1", "D", "D"],
["std::log", "log", "D", "D"],
["std::log10", "log10", "D", "D"],
["std::log2", "log2", "D", "D"],
["std::log1p", "log1p", "D", "D"],
["std::logb", "logb", "D", "D"],
["mathq::sgn", "sgn", "D", "D"],
["std::ceil", "ceil", "D", "D"],
["std::floor", "floor", "D", "D"],
["std::round", "round", "D", "D"],
["std::trunc", "trunc", "D", "D"],
["std::erf", "erf", "D", "D"],
["std::erfc", "erfc", "D", "D"],
["std::tgamma", "tgamma", "D", "D"],
["std::lgamma", "lgamma", "D", "D"],
["std::expint", "expint", "D", "D"],
["std::riemann_zeta", "riemann_zeta", "D", "D"],
["std::comp_ellint_1", "comp_ellint_1", "D", "D"],
["std::comp_ellint_2", "comp_ellint_2", "D", "D"],
["mathq::zero", "zero", "D", "D"],
    ["std::ilogb", "ilogb", "D", "int"],
["mathq::Imaginary", "imaginary", "D", "mathq::Imaginary<D>"]
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
for op in ops:
    function = op[0]
    name = op[1]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function);
    fun = fun.replace("##NAME##",name);
    contents += fun
    count += 1



contents0 = contents0.replace("##MYFILENAME##",fn_functor);
contents0 = contents0.replace("##SCRIPTNAME##",myname);
    
count = 0;
for func in funcs:
    function = func[0]
    name = func[1]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function);
    fun = fun.replace("##NAME##",name);
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
    function = "operator"+op[0]
    name = op[1]
    typeIN = op[2]
    typeOUT = op[3]
    fun = contents0
    fun = fun.replace("##FUNCTION##",function);
    fun = fun.replace("##NAME##",name);
    fun = fun.replace("##COMMENTNAME##",name);
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+name);
    fun = fun.replace("##DIN##",typeIN);
    fun = fun.replace("##DOUT##",typeOUT);
    contents += fun
    count += 1

count = 0;
for func in funcs:
    function = func[0]
    name = func[1]
    typeIN = func[2]
    typeOUT = func[3]
    fun = contents0
    fun = fun.replace("##FUNCTION##",name);
    fun = fun.replace("##NAME##",name);
    fun = fun.replace("##COMMENTNAME##",name);
    fun = fun.replace("##FUNCTOR##","FUNCTOR_"+name);
    fun = fun.replace("##DIN##",typeIN);
    fun = fun.replace("##DOUT##",typeOUT);
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
