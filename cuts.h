#ifndef CUTS_H_
#define CUTS_H_

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define _Stringify(x) #x
#define Stringify(x) _Stringify(x)

void cuts_assert_eq_int(int expr, int val, char *expr_expr, char *val_expr, char *file, int line);
void cuts_assert_eq_string(char *expr, char *val, char *expr_expr, char *val_expr, char *file, int line);

#define CUTS_ASSERT(expr, file, line, reason)						\
  if((expr) != true) {									\
    fprintf(stderr, "%s:%d: cuts test failure because:\n\t%s\n", file, line, reason);	\
    exit(1);										\
  }

#define CUTS_ASSERT_EQ(expr, val)		\
  _Generic((val),				\
	   int: cuts_assert_eq_int,		\
	   char *: cuts_assert_eq_string,	\
	   default: cuts_assert_eq_int		\
	   )((expr), (val), Stringify(expr), Stringify(val), __FILE__, __LINE__)

#endif // CUTS_H_
#ifdef CUTS_IMPLEMENTATION

void cuts_assert_eq_int(int expr, int val, char *expr_expr, char *val_expr, char *file, int line) {
  
  char reason[256];
  snprintf(reason, 256, "%d != %d", expr, val);
  CUTS_ASSERT(expr == val, file, line, reason);
  printf("Test passed... %s == %s\n", expr_expr, val_expr);
}


void cuts_assert_eq_string(char *expr, char *val, char *expr_expr, char *val_expr, char *file, int line) {
  char reason[256];
  snprintf(reason, 256, "%s != %s", expr, val);
  CUTS_ASSERT(strcmp(expr, val) == 0, file, line, reason);
  printf("Test passed... %s == %s\n", expr_expr, val_expr);
}

#endif
