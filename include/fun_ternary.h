#ifndef MATHQ__FUN_TERNARY_H
#define MATHQ__FUN_TERNARY_H 1


namespace mathq {

  // uint uint double

  /* FUNCTOR_UNARY(std::sph_legendre,sph_legendre,D,E); */
  /* FUN_UNARY(sph_legendre,FUNCTOR_sph_legendre); */

  /* FUNCTOR_UNARY(std::assoc_legendre,assoc_legendre,D,E); */
  /* FUN_UNARY(assoc_legendre,FUNCTOR_assoc_legendre); */

  /* FUNCTOR_UNARY(std::assoc_laguerre,assoc_laguerre,D,E); */
  /* FUN_UNARY(assoc_laguerre,FUNCTOR_assoc_laguerre); */


  // ternary
  
  /* FUNCTOR_UNARY_W1(comp_ellint_3,comp_ellint_3,std,D,D,E,E,D); */
  /* FUN_UNARY_W1(comp_ellint_3,FUNCTOR_comp_ellint_3,D,D,E,E,D); */


};

#endif 
