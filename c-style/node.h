#include "adt.h"

typedef struct Node *Node;

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

/* function:getType
 * return the type of node's elt
 * strings of type def is in adt.h
 * */

const char* getType(Node node);

/* some macro to check type of elt in node
 * */

#define isBool(node) \
    strstr(getType(node) , "bool")

#define isChar(node) \
    strstr(getType(node) , "char")

#define isInt(node) \
    strstr(getType(node) , "int")

/* long long is also a long */
#define isLong(node) \
    strstr(getType(node) , "long")

/* but long is not a long long */
#define isLongLong(node) \
    strstr(getType(node) , "long long")

#define isUnsigned(node) \
    strstr(getType(node) , "unsigned")

#define isFloat(node) \
    strstr(getType(node) , "float")

#define isDouble(node) \
    strstr(getType(node) , "double")

#define isPointer(node) \
    strstr(getType(node) , "*")

#define isArray(node) \
    strstr(getType(node) , "[]")

/* macro usage:
 *
 * Node_new: get a new initialized node
 *
 * */
#define Node_new(elt , next) \
    _Node_new(elt , next , typename(elt) , sizeof(elt))


/* get the element of the node without typecast */
Object getObj(Node self);

/* get next node */
Node getNext(Node self);

/* get address of node's member pointer stored next node */
Node* getNextPtr(Node self);

/* get size of node's elt */
size_t getSize(Node self);

Node _Node_new(Object elt , Node next ,
        const char* type , size_t size);
