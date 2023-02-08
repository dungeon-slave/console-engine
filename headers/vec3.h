#ifndef VEC3_H
#define VEC3_H

typedef struct
{
	float x;
	float y;
	float z;
} Tvec3;

Tvec3 VecPlus (Tvec3 vector1, Tvec3 vector2);
Tvec3 VecMins (Tvec3 vector1, Tvec3 vector2);
Tvec3 VecMult (Tvec3 vector1, Tvec3 vector2);
Tvec3 VecDivd (Tvec3 vector1, Tvec3 vector2);  

Tvec3 SclPlus (Tvec3 vector, float value);
Tvec3 SclMins (Tvec3 vector, float value);
Tvec3 SclMult (Tvec3 vector, float value);
Tvec3 SclDivd (Tvec3 vector, float value);

#endif