#include <stdlib.h>
#include <stdio.h>
#include "Object.h"
#include "Sub_Object.h"

int main(int argc, char const *argv[])
{
	Sub_Object * so = new_Sub_Object(123, 456, 789);
	so->methods->print(so);
	__call(so, print);
	__call(so, delete);
	return 0;
}





/*
																				   |
# Explanation of current method #
objects are stored as structs with pointers to:
	1. a struct that holds its properties
	2. a struct that holds its methods

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


// #define __call(o, m) o->methods->m(o)
// #define __call_args(o, m, ...) o->methods->m(o, __VA_ARGS__)

// //////// OBJECT
// //--Object Structure
// struct Object;
// struct Properties;
// struct Methods;

// typedef struct Object Object;
// typedef struct Properties Properties;
// typedef struct Methods Methods;

// struct Properties {
// 	int x;
// 	int * y;
// };
// struct Methods {
// 	void 			(*init_Properties) 		(Properties * p, int x, int y);
// 	Object *		(*new_Object) 			(int x, int y);
// 	void 			(*uninit_Properties)	(Properties * p);
// 	void 			(*delete_Object) 		(Object * o);
// 	void 			(*init_Methods) 		(Methods * m);
// 	void 			(*uninit_Methods)		(Methods * m);
// };
// struct Object {
// 	Properties * prop;
// 	Methods * methods;
// };

// //--Methods
// Object * new_Object(int x, int y);
// void delete_Object(Object * o);
// void init_Object(Object * o, int x, int y);

// void init_Properties(Properties * p, int x, int y);
// void uninit_Properties(Properties * p);

// void init_Methods(Methods * m);
// void uninit_Methods(Methods * m);

// //--Implementations
// //----Constructor/Destructor
// Object * new_Object(int x, int y) {
// 	Object * o = malloc(sizeof(Object));
// 	o->prop = malloc(sizeof(Properties));
// 	o->methods = malloc(sizeof(Methods));
// 	init_Object(o, x, y);
// 	return o;
// }
// void init_Object(Object * o, int x, int y) {
// 	init_Properties(o->prop, x, y);
// 	init_Methods(o->methods);
// }
// void delete_Object(Object * o) {
// 	o->methods->uninit_Properties(o->prop);
// 	free(o->prop);
// 	o->prop = 0;
	
// 	o->methods->uninit_Methods(o->methods);
// 	free(o->methods);
// 	o->methods = 0;
	
// 	free(o);
// 	o = 0;
// }
// //----Properties
// void init_Properties(Properties * p, int x, int y) {
// 	p->x = x;
// 	p->y = malloc(sizeof(int));
// 	*(p->y) = y;
// }
// void uninit_Properties(Properties * p) {
// 	p->x = 0;
// 	free(p->y);
// 	p->y = 0;
// }
// //----Methods
// void init_Methods(Methods * m) {
// 	m->init_Properties = init_Properties;
// 	m->new_Object = new_Object;
// 	m->uninit_Properties = uninit_Properties;
// 	m->delete_Object = delete_Object;
// 	m->init_Methods = init_Methods;
// 	m->uninit_Methods = uninit_Methods;
// }
// void uninit_Methods(Methods * m) {
// 	m->init_Properties = 0;
// 	m->new_Object = 0;
// 	m->uninit_Properties = 0;
// 	m->delete_Object = 0;
// 	m->init_Methods = 0;
// }



// //////// SUB OBJECT
// //--Object Structure
// struct Sub_Object;
// struct Sub_Properties;
// struct Sub_Methods;

// typedef struct Sub_Object Sub_Object;
// typedef struct Sub_Properties Sub_Properties;
// typedef struct Sub_Methods Sub_Methods;

// struct Sub_Properties{
// 	Properties super;
// 	int z;
// };
// struct Sub_Methods {
// 	Methods super;
// 	void 	(*print)	(Sub_Object * so);
// 	void 	(*delete) 	(Sub_Object * o);
// };
// struct Sub_Object {
// 	Sub_Properties * prop;
// 	Sub_Methods * methods;
// 	Object * super; //this is just for convenience. 
// };

// //--Methods
// Sub_Object * new_Sub_Object(int x, int y, int z);
// void delete_Sub_Object(Sub_Object * o);
// void init_Sub_Object(Sub_Object * o, int x, int y, int z);

// void init_Sub_Properties(Sub_Properties * p, int x, int y, int z);
// void uninit_Sub_Properties(Sub_Properties * p);
// void init_Sub_Methods(Sub_Methods * m);
// void uninit_Sub_Methods(Sub_Methods * m);
// void print(Sub_Object * so);
// void init(Object * o, int x, int y);

//--Implementations
//----Constructor/Destructor
// Sub_Object * new_Sub_Object(int x, int y, int z) {
// 	Sub_Object * o = malloc(sizeof(Sub_Object));
// 	o->prop = malloc(sizeof(Sub_Properties));
// 	o->methods = malloc(sizeof(Sub_Methods));
// 	init_Sub_Object(o, x, y, z);
// 	return o;
// }
// void delete_Sub_Object(Sub_Object * o) {
// 	uninit_Sub_Properties(o->prop);
// 	free(o->prop);
// 	o->prop = 0;

// 	init_Sub_Methods(o->methods);
// 	free(o->methods);
// 	o->methods = 0;

// 	free(o);
// 	o = 0;
// }
// void init_Sub_Object(Sub_Object * o, int x, int y, int z) {
// 	o->super = (Object*) o;
// 	init_Sub_Properties(o->prop, x, y, z);
// 	init_Sub_Methods(o->methods);
// }
// //----Properties
// void init_Sub_Properties(Sub_Properties * p, int x, int y, int z) {
// 	init_Properties((Properties *)p, x, y);
// 	p->z = z;
// }
// void uninit_Sub_Properties(Sub_Properties * p) {
// 	uninit_Properties((Properties *)p);
// 	p->z = 0;
// }
// //----Methods
// void init_Sub_Methods(Sub_Methods * m) {
// 	init_Methods((Methods *)m);
// 	m->print = print;
// 	m->delete = delete_Sub_Object;
// }
// void uninit_Sub_Methods(Sub_Methods * m) {
// 	uninit_Methods((Methods *)m);
// 	m->print = 0;
// 	m->delete = 0;
// }
// //----Other
// void print(Sub_Object * so) {
// 	int a = so->super->prop->x;
// 	int * b = so->super->prop->y;
// 	int c = so->prop->z;
// 	printf("%d, %d, %d\n", a, *b, c);
// }


