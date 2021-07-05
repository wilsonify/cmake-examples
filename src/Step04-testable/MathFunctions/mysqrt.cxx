#include <stdio.h>
#include "MathFunctions.h"

// a hack square root calculation using simple operations
double mysqrt(double x) {
  double result;
  result = x;
  if (x < 0) {
    fprintf(stdout,"complex numbers are unsupported\n");
    result = 0;
  }
  else if (x == 0) {
    fprintf(stdout,"0 is a special case \n");
    result = 0;
  }
  else {
    double delta;
    int i;
    for (i = 0; i < 10; ++i) {
      if (result <= 0) {
        fprintf(stdout,"result must be positive");
        result = 0.1;
        }
      delta = x - (result*result);
      result = result + 0.5*delta/result;
      fprintf(stdout,"Computing sqrt of %g to be %g\n",x,result);
      }
    }
  return result;
}