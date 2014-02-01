#include "Person.h"

//--Implementations
//----Constructor/Destructor
Person * new_Person(char * name) {
	Person * o = malloc(sizeof(Person));
	o->prop = malloc(sizeof(Person_Properties));
	o->methods = malloc(sizeof(Person_Methods));
	init_Person(o, name);
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
void init_Person(Person * o, char * name) {
	o->super = (Object*) o;
	init_Person_Properties(o->prop, name);
	init_Person_Methods(o->methods);
}
//----Properties
void init_Person_Properties(Person_Properties * p, char * name) {
	init_Properties((Properties *)p);
	p->name = name;
}
void uninit_Person_Properties(Person_Properties * p) {
	uninit_Properties((Properties *)p);
	//free(p->name);
	p->name = 0;
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
char* toString_Person(void * ptr) {
	Person * psn = (Person *)ptr;
	char * name = psn->prop->name;
	return name;
}
void print(void * ptr) {
	Person * psn = (Person *)ptr;
	Object * o = (Object *)psn;
	char * str = __call(o, toString);
	printf("%s\n", str);
}
