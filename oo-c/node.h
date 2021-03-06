#ifndef NODE_H
#define NODE_H

#include "adt.h"

typedef struct Node *Node;

#define newNodeObj(node) \
    memcpy( \
            malloc(sizeof(getSize(node))) , \
            getObj(node) , \
            sizeof(getSize(node)) \
            )

/* macro usage:
 *
 * elt : if the element of the node is not an array
 *       use elt to get the element from node with typecast
 *
 * arr : if the element of the node is an array
 *       use arr to get the element from node with typecast
 *
 * you can use function:getType get the type of the node
 *
 * */

#define elt(type , node) \
    (*(type*)getObj(node))

#define arr(type , node) \
    ((type*)getObj(node))

/* cast Element and Array automatically
 * but it will lead ambiguity.
 * ex: obj(int , node)
 *         -> Is it an int Array or int Element ?
 * and it would give some warnings like
 *  warning: pointer/integer type mismatch in conditionalexpression
 * */

#define obj(type , node) \
    (isArray(node) ? arr(type , node) : elt(type , node))

/* function:getType
 * return the type of node's elt
 * strings of type def is in adt.h
 * */

const char* getType(Node node);

/* {{{ some macros to check type of elt in node */

#define isBool(node) \
    ((int)strstr(getType(node) , "bool"))

#define isChar(node) \
    (NULL != strstr(getType(node) , "char"))

#define isInt(node) \
    (NULL != strstr(getType(node) , "int"))

/* long long is also a long */
#define isLong(node) \
    (NULL != strstr(getType(node) , "long"))

/* but long is not a long long */
#define isLongLong(node) \
    (NULL != strstr(getType(node) , "long long"))

#define isUnsigned(node) \
    (NULL != strstr(getType(node) , "unsigned"))

#define isFloat(node) \
    (NULL != strstr(getType(node) , "float"))

#define isDouble(node) \
    (NULL != strstr(getType(node) , "double"))

#define isPointer(node) \
    (NULL != strstr(getType(node) , "*"))

#define isArray(node) \
    (NULL != strstr(getType(node) , "[]"))

/* }}} */

/* macro usage:
 *
 * Node_new: get a new initialized node
 *
 * */
#define Node_new(elt , next) \
    _Node_new(elt , next , typename(elt) , sizeof(elt))

Node Node_copy(Node inst , Node next);

/* get the element of the node without typecast */
Object getObj(Node self);

/* get next node */
Node getNext(Node self);

/* get address of node's member pointer stored next node */
Node* getPtrOfNext(Node self);

/* get size of node's elt */
size_t getSize(Node self);

Node _Node_new(Object elt , Node next ,
        const char* type , size_t size);

#endif

/* {{{ vim:fdm=marker:ts=2
 * }}} */
