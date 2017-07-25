#include "node.h"
#include <stdlib.h>

struct Node{
    Object elt;
    Node next;
    const char* eltType;
};

Node _Node_new(Object elt , Node next , const char* type){
    Node node = malloc(sizeof(struct Node));
    node->elt = elt , node->next = next;
    node->eltType = type;
    return node;
}

Object getObj(Node node){
    return node->elt;
}

Node getNext(Node node){
    return node->next;
}

Node *getNextPtr(Node next){
    return &(next->next);
}

const char* getType(Node node){
    return node->eltType;
}
