#define CDR(f , ...) __VA_ARGS__

#define CAR(f , ...) f

#define CONS(e , ...) e , ##__VA_ARGS__

#define SNOC(e , ...) \
    SNOCCDR(e , CONS(H , ## __VA_ARGS__))


#define SNOCCDR(last , ...) CDR(__VA_ARGS__, last)

#define SNOCEND(...) \
    SNOCCDR(END , CONS(H ,  ## __VA_ARGS__))


SNOCEND()
SNOCEND(1)
SNOCEND(1 , 2)
SNOCEND(1 , 2 , 3)

#define t(...) CDR(__VA_ARGS__ , H)
t()
