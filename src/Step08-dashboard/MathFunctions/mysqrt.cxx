#include <stdio.h>
#include <cmath>
#include "MathFunctions.h"

// a hack square root calculation using simple operations
double mysqrt(double x) {
    #ifdef USE_MYMATH
       fprintf(stdout,"USE_MYMATH = %g\n", USE_MYMATH);
    #endif

    #ifdef HAVE_LOG
        fprintf(stdout,"HAVE_LOG = %g\n", HAVE_LOG);
    #endif

    #ifdef HAVE_EXP
        fprintf(stdout,"HAVE_EXP = %g\n", HAVE_EXP);
    #endif



  double result;
  result = x;
  if (x < 0) {
    fprintf(stdout, "complex numbers are not supported");
    result = 0;
  }
  else if (x == 0) {
    fprintf(stdout, "0 is a special case");
    result = 0;
    }
  else {
    try {
      result = exp( log( x )*0.5 );
      fprintf(stdout, "we have both log and exp so use them\n");
      }
    catch (...) {
      fprintf(stdout, "failed to use log and exp so use an iterative approach.");
      double delta;
      int i;
      for (i = 0; i < 10; ++i) {
        if (result <= 0) {
          result = 0.1;
        }
        delta = x - (result*result);
        result = result + 0.5*delta/result;
        fprintf(stdout,"Computing sqrt of %g to be %g\n", x, result);
      }
    }
  }
  return result;
}