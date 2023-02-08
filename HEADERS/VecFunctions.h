#ifndef VEC_FUNCTIONS_H
#define VEC_FUNCTIONS_H

Tvec3 Initialize(float const, float const, float const);

Tvec3 norm(Tvec3);

Tvec3 Abs(Tvec3);

Tvec3 reflect(Tvec3 rd, Tvec3 n);

Tvec3 inverse(Tvec3 vector);

Tvec3 Sign(Tvec3 const v);

Tvec3 Step(Tvec3 edge, Tvec3 v);

int   clamp(int, int, int);

float length(double, double, double);

float dot(Tvec3 const, Tvec3 const);

float sign(float a);

float step(float edge, float x);

float plane(Tvec3 ro, Tvec3 rd, Tvec3 p, float w);

#endif