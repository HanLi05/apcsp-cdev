#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}

// add your areaOfCircle functon here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
  float area = M_PI*radius*radius;
  return area;
}

int main(int argc, char* argv[]) 
{
  float lower;
  float upper;
  char input[256];

  if (argc == 3) {
      if (!(sscanf(argv[1], "%f", &lower) == 1 && lower > 0)) {
        printf("What is your lower bound?\n");
        while (1) {
          fgets(input, 256, stdin);
          if (sscanf(input, "%f", &lower) == 1 && lower > 0) break;
          printf("Not a valid number - try again!\n");
        }
      }
      if (!(sscanf(argv[2], "%f", &upper) == 1 && upper > lower)) {
        printf("What is your upper bound?\n");
        while (1) {
          fgets(input, 256, stdin);
          if (sscanf(input, "%f", &upper) == 1 && upper > lower) break;
          printf("Not a valid number - try again!\n");
        }
      }
  }

  if (argc == 1) {
    printf("What is your lower bound?\n");
    while (1) {
      fgets(input, 256, stdin);
      if (sscanf(input, "%f", &lower) == 1 && lower > 0) break;
      printf("Not a valid number - try again!\n");
    }

    printf("What is your upper bound?\n");
    while (1) {
      fgets(input, 256, stdin);
      if (sscanf(input, "%f", &upper) == 1 && upper > lower) break;
      printf("Not a valid number - try again!\n");
    }
  }

  for (float i = lower; i <= upper; i = i+1) {
    printf("%f\n", areaOfCircle(i));
  }

  // for testing only - do not change
  //getTestInput(argc, argv, &start, &reps);
}
