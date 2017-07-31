/* compiler requirements
 *
 * gnu(typeof)
 * https://gcc.gnu.org/onlinedocs/gcc-5.3.0/gcc/Typeof.html
 *
 * c11(_Generic)
 * http://en.cppreference.com/w/c/language/generic
 *
 * Recursive macro
 * https://github.com/swansontec/map-macro
 *
 * By the way , C has auto , too!
 * __auto_type a = 1; (GNU C)
 * */

#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "macmap.h"

typedef struct List *List;

/* constructor
 * you can call it by using new(List)
 * */

List List_new();

List List_copy(List inst);

/* powerful(?) List constructor */
#define List(...) \
    MAP(List_new() , _push_front , objArgs , __VA_ARGS__)

#define cdrL(inst) \
    pop(List_copy(inst) , 0)

/* destructor
 * you can call it by using delete(instantiate)
 * */
void List_delete(List self);

void ListRef_delete(List ref);

/* access functions(macros) */
int empty(List self);

/* get length of the list */
unsigned int length(List self);
/* macro:front get first obj with typecast */
#define front(type , self) \
    (*(type*) getObj(car(self)))

/* macro:back get last obj with typecast */
#define back(type , self) \
    (*(type*) getObj(rac(self)))

/* manipulation prcedure
 *
 *     if you want to cons or snoc a literal value ,
 *     you must use LIT* macro
 *     to assign literal (char , int type) to variable.
 *
 *     But "a literl char[]" do not need LIT* macro
 *     It's a char[]. it has its own address ,
 *     so user shouldn't use LIT* on it.
 *
 *     if you use LIT* on "string literal" ,
 *     its actaul type will be an array ,
 *     but getType will show [char*] ,
 *     (because two "same" compound literal
 *                  show different address)
 *
 *     if you apply elt(char * , ...)
 *     and try to print it as a string ,
 *     you will get a segmentation fault.
 *
 *     instead , you should apply arr(char , ...) on it.
 *     but it is confusing that apply arr on [char*] type.
 *
 *     so you should avoid use LIT* on "literal string"
 *
 *     if you cons or snoc a pointer
 *     (most object are also pointers) ,
 *     it will not malloc a new entity.
 *
 *     But if your obj is an array , list will malloc it.
 *     so will the other data types.
 */

#define push_front(self , elt) \
    _push_front(self , objArgs(elt))

#define push_back(self ,elt) \
    _push_back(self , objArgs(elt))

/* In most case , use macro above */
List _push_front(List self , Object elt ,
        const char* type , size_t size);

List _push_back(List self , Object elt ,
        const char* type , size_t size);

List pop(List self , int idx);

void List_clear(List self);

/* functional functions */

/* get first obj without typecast */
Node car(List self);
/* get last obj without typecast */
Node rac(List self);
/* get nth obj without typecast */
Object nth(int idx , List self);

List cons(Node inst , List self);

List snoc(Node inst , List self);

/* alloc a list without new node
 * use ListRef_delete to free memory */

List cdr(List self);

List map(void (*fp)(Node node) , List self);

Object foldl(void (*fp)(Node node , Object acc) , Object acc , List self);
#endif
