#ifndef VEC2_H
#define VEC2_H

typedef struct
{
	float x;
	float y;
} Tvec2;

Tvec2 vecplus (Tvec2 vector1, Tvec2 vector2);
Tvec2 vecmins (Tvec2 vector1, Tvec2 vector2);
Tvec2 vecmult (Tvec2 vector1, Tvec2 vector2);
Tvec2 vecdivd (Tvec2 vector1, Tvec2 vector2);


Tvec2 sclplus (Tvec2 vector, float value);
Tvec2 sclmins (Tvec2 vector, float value);
Tvec2 sclmult (Tvec2 vector, float value);
Tvec2 scldivd (Tvec2 vector, float value);

#endif
