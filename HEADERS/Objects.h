#ifndef OBJECTS_H
#define OBJECTS_H

#include "vec3.h"

typedef struct
{
	short Type;
	float Size;
	Tvec3 Pos;
}TData;

struct Object
{
	TData Data;
	struct Object* next;
};

typedef struct Object TObject;
typedef TObject* TPObject;


int addNode(TPObject* head, TData Object);
int delNode(TPObject* head, TPObject* pred, TData Object);
void addObject(TPObject* head);
void delObject(TPObject* head);
TData createObject();

#endif