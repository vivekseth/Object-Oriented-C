#include <stdlib.h>
#include <stdio.h>
#include "Object.h"
#include "Person.h"

int main(int argc, char const *argv[])
{
	Object * obj = new_Object();
	char *str = __call(obj, toString);
	printf("%s\n", str);
	__call(obj, delete);
	
	Person * psn = new_Person("Vivek");
	__call(psn, print);
	Object * o = (Object *) psn;
	printf("%s\n", __call(o, toString));
	__call(psn, delete);
	return 0;
}

/*




A subclass's prop struct _containts_ the struct of its super class. 
A subclass's method struct _containts_ the struct of its super class. 

This allows for casting. 

`int a = ((Object*)so)->prop->x;` 	//harder to read, very clear.
`int a = so->super->prop->x;` 		//easier to read, more ambiguous.

One can access the members of the super class by casting to its superclass.
> I have added a built in pre-casted pointer to its superclass just for the 
> sake of convenience. But it is always possible to cast directly to the right 
> class needed. 

When an object is created, its _new_ function is called. _new_ functions are 
responsible for allocating all object memory. _delete_ functions are responsible
for deallocating all object memory. These functions are unique to an object. 
Unfortunately in my current implementation, this repetitve code must be inserted


*/

