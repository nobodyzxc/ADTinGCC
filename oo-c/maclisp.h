#ifndef MACLSIP_H
#define MACLSIP_H

#define CDR(h , ...) __VA_ARGS__

#define CAR(h , ...) h

#define CONS(e , ...) e , ## __VA_ARGS__

#define SNOC(e , ...) \
    SNOCCDR(e , CONS(H , ## __VA_ARGS__))

#define SNOCCDR(last , ...) CDR(__VA_ARGS__, last)

#define SNOCEND(...) \
    SNOCCDR(END , CONS(H ,  ## __VA_ARGS__))

#endif
