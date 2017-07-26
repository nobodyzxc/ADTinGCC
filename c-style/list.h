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
    MAP(List_new() , _cons , objArgs , __VA_ARGS__)

/* destructor
 * you can call it by using delete(instantiate)
 * */
void List_delete(List self);

/* access functions(macros) */
int empty(List self);
/* get first elt without typecast */
Object head(List self);
/* get last elt without typecast */
Object last(List self);
unsigned int length(List self);
/* macro:front get first elt with typecast */
#define front(type , self) \
    (*(type*) head(self))

/* macro:back get last elt with typecast */
#define back(type , self) \
    (*(type*) last(self))

/* manipulation prcedure
 *
 *     if you want to cons or snoc a literal value ,
 *     you must use LIT macro
 *     to assign literal (char , int type) to variable.
 *
 *     But "a literl char[]" do not need LIT macro
 *     It's a char[]. it has its own address ,
 *     so user shouldn't use LIT on it.
 *
 *     if you use LIT on "string literal" ,
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
 *     so you should avoid use LIT on "literal string"
 * */

/* if you cons or snoc a pointer
 * (most object are also pointers) ,
 * it will not malloc a new entity.
 *
 * But if your elt is an array , list will malloc it.
 * so will the other data types.
 */

#define cons(self , elt) \
    _cons(self , objArgs(elt))

#define snoc(self ,elt) \
    _snoc(self , objArgs(elt))

List pop(List self , int idx);

List map(List self , void (*fp)(Node node));

void List_clear(List self);

/* In most case , use macro above */
List _cons(List self , Object elt ,
        const char* type , size_t size);

List _snoc(List self , Object elt ,
        const char* type , size_t size);
