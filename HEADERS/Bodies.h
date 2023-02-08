#ifndef BODY_H
#define BODY_H

Tvec2 sphere(Tvec3 ro, Tvec3 rd, float r);
Tvec2 box(Tvec3 ro, Tvec3 rd, float boxSize, Tvec3* outNormal);

#endif