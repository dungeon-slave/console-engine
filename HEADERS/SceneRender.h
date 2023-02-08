#ifndef SCENERENDER_H
#define SCENERENDER_H

void renderScene(Tvec3 angle, float zoom, char screen[], TPObject head);
void Rendering(TPObject head);

void SphIntersection(Tvec3* n, float* minIt, Tvec3 ro, Tvec3 rd, Tvec3 pos, float size);
void BoxIntersection(Tvec3* n, float* minIt, Tvec3 ro, Tvec3 rd, Tvec3 pos, float size);

#endif