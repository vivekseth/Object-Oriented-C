//Object Implementation
#include "Object.h"

//--Implementations
//----Constructor/Destructor
Object * new_Object(int x, int y) {
	Object * o = malloc(sizeof(Object));
	o->prop = malloc(sizeof(Properties));
	o->methods = malloc(sizeof(Methods));
	init_Object(o, x, y);
	return o;
}
void init_Object(Object * o, int x, int y) {
	init_Properties(o->prop, x, y);
	init_Methods(o->methods);
}
void delete_Object(Object * o) {
	o->methods->uninit_Properties(o->prop);
	free(o->prop);
	o->prop = 0;
	
	o->methods->uninit_Methods(o->methods);
	free(o->methods);
	o->methods = 0;
	
	free(o);
	o = 0;
}
//----Properties
void init_Properties(Properties * p, int x, int y) {
	p->x = x;
	p->y = malloc(sizeof(int));
	*(p->y) = y;
}
void uninit_Properties(Properties * p) {
	p->x = 0;
	free(p->y);
	p->y = 0;
}
//----Methods
void init_Methods(Methods * m) {
	m->init_Properties = init_Properties;
	m->new_Object = new_Object;
	m->uninit_Properties = uninit_Properties;
	m->delete_Object = delete_Object;
	m->init_Methods = init_Methods;
	m->uninit_Methods = uninit_Methods;
}
void uninit_Methods(Methods * m) {
	m->init_Properties = 0;
	m->new_Object = 0;
	m->uninit_Properties = 0;
	m->delete_Object = 0;
	m->init_Methods = 0;
}
