#include "Object.h"

//////// SUB OBJECT
//--Object Structure
struct Sub_Object;
struct Sub_Properties;
struct Sub_Methods;

typedef struct Sub_Object Sub_Object;
typedef struct Sub_Properties Sub_Properties;
typedef struct Sub_Methods Sub_Methods;

struct Sub_Object {
	Sub_Properties * prop;
	Sub_Methods * methods;
	Object * super; //this is just for convenience. 
};
struct Sub_Properties{
	Properties super;
	int z;
};
struct Sub_Methods {
	Methods super;
	void 	(*print)	(Sub_Object * so);
	void 	(*delete) 	(Sub_Object * o);
};

//--Methods
Sub_Object * new_Sub_Object(int x, int y, int z);
void delete_Sub_Object(Sub_Object * o);
void init_Sub_Object(Sub_Object * o, int x, int y, int z);

void init_Sub_Properties(Sub_Properties * p, int x, int y, int z);
void uninit_Sub_Properties(Sub_Properties * p);
void init_Sub_Methods(Sub_Methods * m);
void uninit_Sub_Methods(Sub_Methods * m);
void print(Sub_Object * so);
void init(Object * o, int x, int y);

