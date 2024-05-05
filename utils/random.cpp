#include <cstdlib>
#include <ctime>
#include "random.h"

int generateNumberOnInterval(int a, int b)
{
  int number = 0;

  unsigned seed = time(0);
  srand(seed);

  number = a + (rand() % b);

  return number;
}