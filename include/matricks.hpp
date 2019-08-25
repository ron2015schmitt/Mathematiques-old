

// Including this file provides full vector/matrix functionality


#ifndef MATRICKS_H
#define MATRICKS_H

#ifdef MEBUG
#define MATRICKS_DEBUG 1
#endif


#include "matricks_version.hpp"
#include "util.hpp"
#include "matrickscommon.hpp"
#include "print.hpp"

#include "applicative.hpp"
#include "mathapp.hpp"
#include "boolapp.hpp"
#include "complexapp.hpp"
#include "verror.hpp"
#include "merror.hpp"
#include "vectordef.hpp"
#include "matrixdef.hpp"

#include "md.hpp"

#include "vexpr.hpp"
#include "vboolexpr.hpp"
#include "vcomplexexpr.hpp"
#include "mexpr.hpp"
#include "mboolexpr.hpp"
#include "mcomplexexpr.hpp"
#include "mvexpr.hpp"
#include "voperators.hpp"
#include "vmathops.hpp"
#include "vboolops.hpp"
#include "vcomplexops.hpp"
#include "moperators.hpp"
#include "mmathops.hpp"
#include "mboolops.hpp"
#include "mcomplexops.hpp"
#include "mvoperators.hpp"
#include "mvcomplexops.hpp"
#include "p3vector.hpp"

#include "matricksio.hpp"
#include "matricksutil.hpp"


#endif
