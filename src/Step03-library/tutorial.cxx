//A simple program that computes the square root of a number
#include <stdio.h>
#include <math.h>
#include "tutorialConfig.h"
#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif

int main (int argc, char *argv[])
{
if (argc < 2) {
fprintf(stdout,"%s Version %d.%d\n", argv[0], tutorial_VERSION_MAJOR, tutorial_VERSION_MINOR);
fprintf(stdout, "Usage: %s number\n", argv[0]);
return 1;
}

double inputValue = atof(argv[1]);

#ifdef USE_MYMATH
  double outputValue = custommath::mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif

fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);
return 0;
}
