#include <stdlib.h>
#include <stdio.h>

#define __call(o, m) o->methods->m(o)
#define __call_args(o, m, ...) o->methods->m(o, __VA_ARGS__)

//////// OBJECT
//--Object Structure
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
	int x;
	int * y;
};
struct Methods {
	void 			(*init_Properties) 		(Properties * p, int x, int y);
	Object *		(*new_Object) 			(int x, int y);
	void 			(*uninit_Properties)	(Properties * p);
	void 			(*delete_Object) 		(Object * o);
	void 			(*init_Methods) 		(Methods * m);
	void 			(*uninit_Methods)		(Methods * m);
};

//--Methods
Object * new_Object(int x, int y);
void delete_Object(Object * o);
void init_Object(Object * o, int x, int y);

void init_Properties(Properties * p, int x, int y);
void uninit_Properties(Properties * p);

void init_Methods(Methods * m);
void uninit_Methods(Methods * m);
