#define EXPAND(...) __VA_ARGS__
#define DEFER(x) x EMPTY()
#define EMPTY()
#define TRUE(x,...) x
#define FALSE(x,...) __VA_ARGS__
#define OPEN(x) OPEN_I x
#define OPEN_I(...) __VA_ARGS__
#define CAR(x) CAR_I x
#define CDR(x) (CDR_I x)
#define CAR_I(x,...) x
#define CDR_I(x,...) __VA_ARGS__
#define CONS(x,y) (x,OPEN_I y)
#define RCONS(x,y) (OPEN_I y,x)
#define NIL ()
#define IS_EDIBLE(x) EXPAND(DEFER(IS_EDIBLE_I)(IS_EDIBLE_II x,FALSE))
#define IS_EDIBLE_I(x,y,...) y
#define IS_EDIBLE_II(...) ,TRUE,
#define SCONS(x,y) (x,IS_EDIBLE(y)(OPEN_I y,y))

CDR((1 , 2 , 3))
