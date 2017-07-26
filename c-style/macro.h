/*
 * Compile with `gcc -E example.c` to see the preprocessor output.
 */
#include "map.h"

#define CDR(h , ...) __VA_ARGS__
#define CAR(h , ...) h
#define CONS(e , ...) e , ##__VA_ARGS__
#define SNOC(e , ...) \
    SNOCCDR(e , CONS(H , ## __VA_ARGS__))
#define SNOCCDR(last , ...) CDR(__VA_ARGS__, last)
#define SNOCEND(...) \
    SNOCCDR(END , CONS(H ,  ## __VA_ARGS__))

#define List_END(...) \
    MAP(_cons , __VA_ARGS__)

#define List(...) List_END(SNOCEND(__VA_ARGS__))
