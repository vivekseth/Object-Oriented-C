#include "Sub_Object.h"

//--Implementations
//----Constructor/Destructor
Sub_Object * new_Sub_Object(int x, int y, int z) {
	Sub_Object * o = malloc(sizeof(Sub_Object));
	o->prop = malloc(sizeof(Sub_Properties));
	o->methods = malloc(sizeof(Sub_Methods));
	init_Sub_Object(o, x, y, z);
	return o;
}
void delete_Sub_Object(Sub_Object * o) {
	uninit_Sub_Properties(o->prop);
	free(o->prop);
	o->prop = 0;

	init_Sub_Methods(o->methods);
	free(o->methods);
	o->methods = 0;

	free(o);
	o = 0;
}
void init_Sub_Object(Sub_Object * o, int x, int y, int z) {
	o->super = (Object*) o;
	init_Sub_Properties(o->prop, x, y, z);
	init_Sub_Methods(o->methods);
}
//----Properties
void init_Sub_Properties(Sub_Properties * p, int x, int y, int z) {
	init_Properties((Properties *)p, x, y);
	p->z = z;
}
void uninit_Sub_Properties(Sub_Properties * p) {
	uninit_Properties((Properties *)p);
	p->z = 0;
}
//----Methods
void init_Sub_Methods(Sub_Methods * m) {
	init_Methods((Methods *)m);
	m->print = print;
	m->delete = delete_Sub_Object;
}
void uninit_Sub_Methods(Sub_Methods * m) {
	uninit_Methods((Methods *)m);
	m->print = 0;
	m->delete = 0;
}
//----Other
void print(Sub_Object * so) {
	int a = so->super->prop->x;
	int * b = so->super->prop->y;
	int c = so->prop->z;
	printf("%d, %d, %d\n", a, *b, c);
}
