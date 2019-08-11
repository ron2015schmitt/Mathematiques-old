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




#ifndef MCOMPLEXEXPR_H
#define MCOMPLEXEXPR_H 1


#include <string>
#include <sstream>
#include <complex>

namespace COOLL {








  /****************************************************************************
   * CMatOpScal Operator Template 
   *
   * vector/scalar binary operators
   ****************************************************************************
   */


  template<class D, class A, class OP>
  class CMatOpScal : public Mexpr<std::complex<D>,CMatOpScal<D,A,OP> > {

  private:
    const A& a_;
    const D& val_;

  public:
    CMatOpScal(const A& a, const D& b)
      : a_(a), val_(b)
    { }

    inline const std::complex<D> operator()(const unsigned int i) const { 
      return OP::apply(a_(i), val_); 
    }

   inline const std::complex<D> operator()(const unsigned int r, const unsigned int c) const {
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

    inline METypes metype(void) const {
      return ME_CMatOpScal;
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

    bool mustcopy(const void *maddr) const {
      return a_.mustcopy(maddr);
    }



  };





  /****************************************************************************
   * CScalOpMat Operator Template 
   *
   * scalar/vector binary operators
   ****************************************************************************
   */

  
  template<class D, class B, class OP>
  class CScalOpMat : public Mexpr<std::complex<D>,CScalOpMat<D,B,OP> > {

  private:
    const D& val_;
    const B& b_;

  public:
    CScalOpMat(const D& a, const B& b)
      :  val_(a), b_(b)
    { }

    inline const std::complex<D> operator()(const unsigned int i) const { 
      return OP::apply(val_,b_(i)); 
    }

   inline const std::complex<D> operator()(const unsigned int r, const unsigned int c) const {
      return OP::apply(val_,b_(r,c));
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

    inline METypes metype(void) const {
      return ME_CScalOpMat;
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

    bool mustcopy(const void *maddr) const {
      return b_.mustcopy(maddr);
    }



  };



};

#endif 
