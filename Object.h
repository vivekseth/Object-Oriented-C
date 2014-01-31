#include <stdlib.h>
#include <stdio.h>

#define __call(o, m) o->methods->m(o)
#define __call_args(o, m, ...) o->methods->m(o, __VA_ARGS__)
//#define __call_cast(o, s, m) o->super->methods->m((s*)o)

//Object
//--Structure
struct Object;
struct Properties;
struct Methods;

typedef struct Object Object;
typedef struct Properties Properties;
typedef struct Methods Methods;

struct Object {
	Properties * prop;
	Methods * methods;
};
struct Properties {
	char * _;
};
struct Methods {
	void 	(*delete)	(Object * o);
	//can be overridden
	char* 	(*toString)			(void * o);
};

//--Methods
//----Constructor/Desctructor
Object * new_Object();
void delete_Object(Object * o);
void init_Object(Object * o);
void uninit_Object(Object * o);
//----init properties
void init_Properties(Properties * p);
void uninit_Properties(Properties * p);
//----init methods
void init_Methods(Methods * m);
void uninit_Methods(Methods * m);
//----method declarations
char* toString_Object(void * o);
