// START-OF-NOTICE
// Copyright 2003, Columbia University
// Authors: Ron Schmitt
//
//
// This file is part of the Columbia Object Oriented 
// Linear-algebra Library (COOLL).
//
// You should have received a copy of the License Agreement for the
// COOLL along with the software;  see the file LICENSE.  
// If not, contact
// Department of Applied Physics and Applied Mathematics
// Columbia Univeristy 
// New York, NY 10027
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
// END-OF-NOTICE
//===========================================================================




#ifndef VBOOLEXPR_H
#define VBOOLEXPR_H


#include <string>
#include <sstream>


namespace COOLL {







  /****************************************************************************
   * VBoolBinOp Operator Expression Template 
   *
   * vector/vector binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class VBoolBinOp : public  Vexpr<bool,VBoolBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    VBoolBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }

    inline const bool operator[](const unsigned int i) const {  
      return OP::apply(a_[i], b_[i]); 
    }

    inline unsigned int size(void) const {
      if ( a_.size() != b_.size() ) {
	return badsize;
      } else {
	return a_.size();
      }
    }

    inline VETypes vetype(void) const {
      return VE_VBoolBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_LAvector) 
	sa = "(" + sa + ")";
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_LAvector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return (a_.mustcopy(vaddr)) && (b_.mustcopy(vaddr));
    }



  };







  /****************************************************************************
   * BoolVecOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class BoolVecOpScal : public Vexpr<bool,BoolVecOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;

  public:
    BoolVecOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const bool operator[](const unsigned int i) const { 
      return OP::apply(a_[i], val_); 
    }

    inline unsigned int size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolVecOpScal;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.vetype() != VE_LAvector) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }



  };





  /****************************************************************************
   * BoolScalOpVec Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class BoolScalOpVec : public Vexpr<bool,BoolScalOpVec<D,B,OP> > {

  private:
    D val_;
    const B& b_;

  public:
    BoolScalOpVec(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const bool operator[](const unsigned int i) const { 
      return OP::apply(val_,b_[i]); 
    }

    inline unsigned int size(void) const {
      return b_.size();
    }

    inline VETypes vetype(void) const {
      return VE_BoolScalOpVec;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.debugtxt();
      if (b_.vetype() != VE_LAvector) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return b_.mustcopy(vaddr);
    }


  };




  /****************************************************************************
   * VBoolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class VBoolFuncOp  : public  Vexpr<bool,VBoolFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    VBoolFuncOp(const A& a) : a_(a) { }


    inline const bool operator[](const unsigned int i) const
    { return FUNC::apply(a_[i]); }

    inline unsigned int size(void) const {
      return a_.size();
    }

    inline VETypes vetype(void) const {
      return VE_VBoolFuncOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }

    bool mustcopy(const void *vaddr) const {
      return a_.mustcopy(vaddr);
    }


  };










};

#endif
