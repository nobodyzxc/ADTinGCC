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
MAP(append, LIT('a'), LIT('b'), LIT('c'))

#define List(...) \
    MAP(append , __VA_ARGS__)
List("a" , "b" , "c" ,  "d")


/* Test `MAP_LIST` with parentheses in the arguments: */
#define CALL_LIST(x) putchar x
//MAP_LIST(CALL_LIST, ('a'), ('b'), ('c'));
//MAP_LIST(CALL_LIST, ('a'), ('b'), ('c'), ('d'), ('a'), ('b'), ('c'), ('d'), ('a'), ('b'), ('c'), ('d'));
