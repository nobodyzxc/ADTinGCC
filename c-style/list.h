/* compiler requirements
 *
 * gnu(typeof)
 *
 * c11(_Generic)
 *
 * */

#include "node.h"
#include <stdlib.h>
#include <string.h>
typedef struct List *List;

/* constructor */
List List_new();

/* destructor */
void List_delete();

/* access functions(macro) */
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
    (*(type*) back(self))

/* manipulation prcedure
 *
 *     if you want to cons or append a literal value ,
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
 *                      show different address)
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

/* if you cons or append a pointer
 * (most object are also pointers) ,
 * it would not malloc a new entity
 * But if your elt is an array , list will malloc it.
 * so will the other data types.
 */

#define cons(self , elt) \
    _cons(self , newElt(elt) , typename(elt))

#define append(self ,elt) \
    _append(self , newElt(elt) , typename(elt))

List pop(List self , int idx);

List map(List self , void (*fp)(Node node));

/* In most case , use macro above */
List _cons(List self , Object elt , const char* type);
List _append(List self , Object elt , const char* type);
