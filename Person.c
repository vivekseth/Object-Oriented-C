#include "Person.h"

//--Implementations
//----Constructor/Destructor
Person * new_Person() {
	Person * o = malloc(sizeof(Person));
	o->prop = malloc(sizeof(Person_Properties));
	o->methods = malloc(sizeof(Person_Methods));
	init_Person(o);
	return o;
}
void delete_Person(Person * o) {
	uninit_Person_Properties(o->prop);
	free(o->prop);
	o->prop = 0;

	init_Person_Methods(o->methods);
	free(o->methods);
	o->methods = 0;

	free(o);
	o = 0;
}
void init_Person(Person * o) {
	o->super = (Object*) o;
	init_Person_Properties(o->prop);
	init_Person_Methods(o->methods);
}
//----Properties
void init_Person_Properties(Person_Properties * p) {
	init_Properties((Properties *)p);
	//p->z = z;
}
void uninit_Person_Properties(Person_Properties * p) {
	uninit_Properties((Properties *)p);
	//p->z = 0;
}
//----Methods
void init_Person_Methods(Person_Methods * m) {
	init_Methods((Methods *)m);
	((Methods *)m)->toString = toString_Person;
	m->print = print;
	m->delete = delete_Person;
}
void uninit_Person_Methods(Person_Methods * m) {
	uninit_Methods((Methods *)m);
	m->print = 0;
	m->delete = 0;
}
//----Other
char* toString_Person(void * o) {
	return "(Person)";
}
void print(void * ptr) {
	Person * psn = (Person *)ptr;
	Object * o = (Object *)psn;
	char * str = __call(o, toString);
	printf("%s\n", str);
}
