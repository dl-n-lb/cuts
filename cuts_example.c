#include <stdio.h>
#define CUTS_IMPLEMENTATION
#include "cuts.h"

int fact(int t) {
  assert(t >= 0);
  if (t < 2) return 1;
  if (t == 2) return t;
  return t  * fact(t-1);
}

char *return_a() {
  return "a";
}

int main(int argc, char **argv) {
  char *val = "a";
  char *valb = "a";

  float f = 10.2;
  float g = f;

  CUTS_ASSERT_EQ(return_a(), "a");
  CUTS_ASSERT_EQ(fact(4), 24);
  CUTS_ASSERT_EQ(f, g);
  
  return 0;
}
