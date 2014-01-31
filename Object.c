//Object Implementation
#include "Object.h"

//--Implementations
//----Constructor/Destructor
Object * new_Object() {
	Object * o = malloc(sizeof(Object));
	o->prop = malloc(sizeof(Properties));
	o->methods = malloc(sizeof(Methods));
	init_Object(o);
	return o;
}
void delete_Object(Object * o) {
	uninit_Object(o);
	free(o->prop);
	o->prop = 0;	
	free(o->methods);
	o->methods = 0;
	free(o);
	o = 0;
}
void init_Object(Object * o) {
	init_Properties(o->prop);
	init_Methods(o->methods);
}
void uninit_Object(Object * o) {
	uninit_Properties(o->prop);
	uninit_Methods(o->methods);
}
//----Properties
void init_Properties(Properties * p) {
}
void uninit_Properties(Properties * p) {
}
//----Methods
void init_Methods(Methods * m) {
	m->delete = delete_Object;
	m->toString = toString_Object;
}
void uninit_Methods(Methods * m) {
	m->delete = 0;
	m->toString = 0;
}
char* toString_Object(void * o) {
	return "(Object)";
}
