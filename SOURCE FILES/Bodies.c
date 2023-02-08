//INCLUDE PART
    #include <math.h>

    #include "vec2.h"
    #include "vec3.h"
    #include "VecFunctions.h"

Tvec2 sphere(Tvec3 ro, Tvec3 rd, float r)
{
    float b = dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    Tvec2 vector;

    if (h < 0.0)
    {
        vector.x = -1.0;
        vector.y = -1.0;

        return vector;
    }

    h = (float)sqrt(h);
    vector.x = -b - h;
    vector.y = -b + h;

    return vector;
}

Tvec2 box(Tvec3 ro, Tvec3 rd, float boxSize, Tvec3* outNormal)
{
    Tvec2 vector;
    Tvec3 m = Initialize(1.0f, 1.0f, 1.0f);
    m = VecDivd(m, rd);
    Tvec3 n = VecMult(m, ro);
    Tvec3 k = SclMult(Abs(m), boxSize);
    n = inverse(n);
    Tvec3 t1 = VecMins(n, k);
    Tvec3 t2 = VecPlus(n, k);
    float tN = fmax(fmax(t1.x, t1.y), t1.z);
    float tF = fmin(fmin(t2.x, t2.y), t2.z);
    if (tN > tF || tF < 0.0f) //No intersection
    {
        vector.x = -1.0f;
        vector.y = -1.0f;
        
        return vector;
    }
        
    Tvec3 yzx = Initialize(t1.y, t1.z, t1.x);
    Tvec3 zxy = Initialize(t1.z, t1.x, t1.y);
   
    rd = inverse(rd); rd = Sign(rd);
    *outNormal = VecMult(VecMult(rd, Step(yzx, t1)), Step(zxy, t1));

    vector.x = tN;
    vector.y = tF;
    return vector;
}