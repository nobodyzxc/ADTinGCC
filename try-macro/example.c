/*
 * Compile with `gcc -E example.c` to see the preprocessor output.
 */
#include "map.h"

/* Basic `MAP` usage: */
#define STRING(x) char const *x##_string = #x;
//MAP(STRING, foo, bar, baz)

/* Basic `MAP_LIST` usage: */
#define PARAM(x) int x
//void function(MAP_LIST(PARAM, foo, bar, baz));

/* Test `MAP` with parentheses in the arguments: */
#define CALL(x) putchar x;

#define CDR(f , ...) __VA_ARGS__
#define CAR(f , ...) f
#define CONS(e , ...) e , ##__VA_ARGS__
#define SNOC(e , ...) \
    SNOCCDR(e , CONS(H , ## __VA_ARGS__))
#define SNOCCDR(last , ...) CDR(__VA_ARGS__, last)
#define SNOCEND(...) \
    SNOCCDR(END , CONS(H ,  ## __VA_ARGS__))



#define List_END(...) \
    MAP(_cons , __VA_ARGS__)

#define List(...) List_END(SNOCEND(__VA_ARGS__))
List(5 , 4 , 3 , 2 , 1)
List(4 , 3 , 2 , 1)
List(3 , 2 , 1)
List(2 , 1)
List(1)
List()

/* Test `MAP_LIST` with parentheses in the arguments: */
#define CALL_LIST(x) putchar x
