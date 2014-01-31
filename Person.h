#include "Object.h"

//////// SUB OBJECT
//--Object Structure
struct Person;
struct Person_Properties;
struct Person_Methods;

typedef struct Person Person;
typedef struct Person_Properties Person_Properties;
typedef struct Person_Methods Person_Methods;

struct Person {
	Person_Properties * prop;
	Person_Methods * methods;
	Object * super; //this is just for convenience. 
};
struct Person_Properties{
	Properties super;
	char * name;
};
struct Person_Methods {
	Methods super;
	void 	(*delete) 	(Person * o);
	//can be overridden
	void 	(*print)	(void * o);
};

//--Methods
Person * new_Person();
void delete_Person(Person * o);
void init_Person(Person * o);
void uninit_Person(Person * o);

void init_Person_Properties(Person_Properties * p);
void uninit_Person_Properties(Person_Properties * p);
void init_Person_Methods(Person_Methods * m);
void uninit_Person_Methods(Person_Methods * m);

//override
char* toString_Person(void * o);
void print(void * o);
