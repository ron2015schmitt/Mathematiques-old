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




#ifndef MBOOLEXPR_H
#define MBOOLEXPR_H


#include <string>
#include <sstream>


namespace COOLL {







  /****************************************************************************
   * MboolBinOp Operator Expression Template 
   *
   * matrix/matrix binary operator expressions
   ****************************************************************************
   */
  template<class D, class A, class B, class OP>
  class MboolBinOp : public  Mexpr<bool,MboolBinOp<D,A,B,OP> > {

  private:
    const A& a_;
    const B& b_;

  public:
    MboolBinOp(const A& a, const B& b)
      : a_(a), b_(b)
    { 
    }
    inline const bool operator()(const unsigned int i) const {
      return OP::apply(a_(i), b_(i));
    }

    inline const bool operator()(const unsigned int r, const unsigned int c) const {
      return OP::apply(a_(r,c), b_(r,c));
    }

    inline unsigned int Nrows(void) const {
      if  (a_.Nrows() !=  b_.Nrows() ) {
	return badsize;
      } else {
	return a_.Nrows();
      }
    }

    inline unsigned int Ncols(void) const {
      if  (a_.Ncols() !=  b_.Ncols() ) {
	return badsize;
      } else {
	return a_.Ncols();
      }
    }


    inline unsigned int size(void) const {
      if ( (Nrows()==badsize) || (Ncols()==badsize) )
	return badsize;
      else
	return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return (a_.mustcopy(maddr)) || (b_.mustcopy(maddr));
    }
 
    inline static METypes metype(void)  {
      return ME_MBoolBinOp;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.metype() != ME_Matrix) 
	sa = "(" + sa + ")";
      std::string sb = b_.debugtxt();
      if (b_.metype() != ME_Matrix) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      a_.outputglossary();
      b_.outputglossary();
    }



  };







  /****************************************************************************
   * BoolMatOpScal Operator Template 
   *
   * matrix/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class BoolMatOpScal : public Mexpr<bool,BoolMatOpScal<D,A,OP> > {

  private:
    const A& a_;
    D val_;

  public:
    BoolMatOpScal(const A& a, const D b)
      : a_(a), val_(b)
    { }

    inline const bool operator()(const unsigned int i) const {
      return OP::apply(a_(i), val_);
    }

    inline const bool operator()(const unsigned int r, const unsigned int c) const {
      return OP::apply(a_(r,c), val_);
    }

    inline unsigned int Nrows(void) const {
      return a_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return a_.Ncols();
    }

    inline unsigned int size(void) const {
      return a_.size();
    }


    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }

    inline METypes metype(void) const {
      return ME_BoolMatOpScal;
    }

    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      if (a_.metype() != ME_Matrix) 
	sa = "(" + sa + ")";
      std::ostringstream stream;
      stream << val_;
      std::string sb = stream.str();
      return OP::debugtxt(sa,sb);
    }


    void outputglossary(void) const {
      a_.outputglossary();
    }



  };





  /****************************************************************************
   * BoolScalOpMat Operator Template 
   *
   * scalar/matrix binary operators
   ****************************************************************************
   */


  template<class D, class B, class OP>
  class BoolScalOpMat : public Mexpr<bool,BoolScalOpMat<D,B,OP> > {

  private:
    D val_;
    const B& b_;

  public:
    BoolScalOpMat(const D a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const bool operator()(const unsigned int i) const {
      return OP::apply(val_, b_(i));
    }

    inline const bool operator()(const unsigned int r, const unsigned int c) const {
      return OP::apply(val_, b_(r,c));
    }

    inline unsigned int Nrows(void) const {
      return b_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return b_.Ncols();
    }

    inline unsigned int size(void) const {
      return b_.size();
    }


    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }

    inline METypes metype(void) const {
      return ME_BoolScalOpMat;
    }

    std::string debugtxt(void) const {
      std::ostringstream stream;
      stream << val_;
      std::string sa = stream.str();
      std::string sb = b_.debugtxt();
      if (b_.metype() != ME_Matrix) 
	sb = "(" + sb + ")";
      return OP::debugtxt(sa,sb);
    }

    void outputglossary(void) const {
      b_.outputglossary();
    }


  };




  /****************************************************************************
   * MboolFuncOp Operator Template 
   *
   * unary operators and unary function overloading
   ****************************************************************************
   */

  template<class D, class A, class FUNC>
  class MboolFuncOp  : public  Mexpr<bool,MboolFuncOp<D,A,FUNC> >{
  
  private:
    const A& a_;
  
  public:
    MboolFuncOp(const A& a) : a_(a) { }

    inline const bool operator()(const unsigned int i) const {
      return FUNC::apply(a_(i));
    }

    inline const bool operator()(const unsigned int r, const unsigned int c) const {
      return FUNC::apply(a_(r,c));
    }

    inline unsigned int Nrows(void) const {
      return a_.Nrows();
    }

    inline unsigned int Ncols(void) const {
      return a_.Ncols();
    }

    inline unsigned int size(void) const {
      return a_.size();
    }

    inline METypes metype(void) const {
      return ME_MBoolFuncOp;
    }

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }


    std::string debugtxt(void) const {
      std::string sa = a_.debugtxt();
      return FUNC::debugtxt(sa);
    }

    void outputglossary(void) const {
      a_.outputglossary();
    }



  };










};

#endif
