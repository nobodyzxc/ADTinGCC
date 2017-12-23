#include <stdlib.h>
#include <string.h>

#define Elt(TYPE) TYPE *

#define new(TYPE) TYPE ## _new()
#define init(TYPE , this) TYPE ## _init(this)

#define newElt(TYPE , val) \
    memcpy(malloc(sizeof(TYPE)) , &(TYPE){val} , sizeof(TYPE))

#define List(var) List var ; init(List , &var)
typedef void *ListElt;
typedef struct Node *pNode;
typedef struct List List , *pList;

struct List{
    const unsigned int len;
    const pNode head , tail;
    /* access functions */
    int (*const empty)(pList this);
    ListElt (*const front)(pList this);
    ListElt (*const back)(pList this);
    unsigned int (*const length)(pList this);
    /* manipulation prcedure */
    void (*const push_front)(pList this , ListElt elt);
    void (*const push_back)(pList this , ListElt elt);
    void (*const pop_front)(pList this);
    void (*const pop_back)(pList this);
};

/* constructor */
pList List_new();
pList List_init(pList);
