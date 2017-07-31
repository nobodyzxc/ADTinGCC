#include "list.h"
#include <assert.h>

#define implFunc(ADT , func) (ADT ## _ ## func)

#define bindFunc(ADT , func) \
    .func = implFunc(ADT , func)

#define assnk(TYPE , des , org) \
    memcpy((TYPE *)&des , &(TYPE){org} , sizeof(TYPE))

struct Node{
    ListElt elt;
    pNode next;
};

/* access functions */
int List_empty(pList this){
    return this->head == NULL;
}

ListElt List_front(pList this){
    return this->head->elt;
}

ListElt List_back(pList this){
    return this->tail->elt;
}

unsigned int List_length(pList this){
    return this->len;
}

/* manipulation prcedure */
void List_push_front(pList this , ListElt elt){
    assnk(unsigned int , this->len , this->len + 1);
    pNode node = malloc(sizeof(struct Node));
    node->elt = elt , node->next = this->head;
    assnk(pNode , this->head , node);
    if(!this->tail)
        assnk(pNode , this->tail , this->head);
}

void List_push_back(pList this , ListElt elt){
    assnk(unsigned int , this->len , this->len + 1);
    this->tail->next = malloc(sizeof(struct Node));
    assnk(pNode , this->tail , this->tail->next);
    this->tail->elt = elt , this->tail->next = NULL;
    if(!this->head)
        assnk(pNode , this->head , this->tail);
}

void List_pop_front(pList this){
    assert(this->len != 0);
    pNode del = this->head;
    assnk(pNode , this->head , this->head->next);
    if(this->head->next == NULL)
        assnk(pNode , this->tail , NULL);
    free(del);
    assnk(unsigned int , this->len , this->len - 1);
}

void List_pop_back(pList this){
    assert(this->len != 0);
    pNode del = this->head;
    assnk(pNode , this->head , this->head->next);
    if(this->head->next == NULL)
        assnk(pNode , this->tail , NULL);
    free(del);
    assnk(unsigned int , this->len , this->len - 1);
}

const static struct List klass = {
    .len = 0 ,
    .head = NULL ,
    .tail = NULL ,
    /* access functions */
    bindFunc(List , empty) ,
    bindFunc(List , front) ,
    bindFunc(List , back) ,
    bindFunc(List , length) ,
    /* manipulation prcedure */
    bindFunc(List , push_front) ,
    bindFunc(List , push_back) ,
    bindFunc(List , pop_front) ,
    bindFunc(List , pop_back) ,
};

pList List_init(pList this){
    return (pList)memcpy(this , &klass , sizeof(klass));
}

pList List_new(){
    return List_init(malloc(sizeof(klass)));
}
