#include <stdlib.h>
#include <string.h>

#define Elt(TYPE) TYPE *

#define new(TYPE) TYPE ## _new()

#define newElt(TYPE , val) \
    memcpy(malloc(sizeof(TYPE)) , &(TYPE){val} , sizeof(TYPE))

typedef void *ListElt;
typedef struct List *List;
typedef struct Node *pNode;

struct List{
    const unsigned int len;
    const pNode head , tail;
    /* access functions */
    int (*const empty)(List self);
    ListElt (*const front)(List self);
    ListElt (*const back)(List self);
    unsigned int (*const length)(List self);
    /* manipulation prcedure */
    List (*const push_front)(List self , ListElt elt);
    List (*const push_back)(List self , ListElt elt);
    List (*const pop_front)(List self);
    List (*const pop_back)(List self);
    List (*const append)(List self , List lst);
};

/* constructor */
List List_new();
