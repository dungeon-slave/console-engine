//INCLUDE PART
    #include <math.h>
    #include "vec2.h"
    #include "vec3.h"

    Tvec3 Initialize(float const x, float const y, float const z)
    {
        Tvec3 vector;

        vector.x = x;
        vector.y = y;
        vector.z = z;

        return vector;
    }

    int clamp(int value, int min, int max) { return (int)(fmax(fmin(value, max), min)); }

float length(double x, double y, double z) { return (float)sqrt(x * x + y * y + z * z); }

Tvec3 norm(Tvec3 vector) { return vector = SclDivd(vector, length(vector.x, vector.y, vector.z)); }

Tvec3 Abs(Tvec3 vector) { return vector = Initialize(fabs(vector.x), fabs(vector.y), fabs(vector.z)); }

float dot(Tvec3 const a, Tvec3 const b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Tvec3 reflect(Tvec3 rd, Tvec3 n) { return VecMins(rd, SclMult(n, 2 * dot(n, rd))); }

Tvec3 inverse(Tvec3 vector) { return Initialize(-vector.x, -vector.y, -vector.z); }

    float sign(float a) { return (0 < a) - (a < 0); }

    float step(float edge, float x) { return x > edge; }

Tvec3 Sign(Tvec3 const v) { return Initialize(sign(v.x), sign(v.y), sign(v.z)); }

Tvec3 Step(Tvec3 const edge, Tvec3 v) { return Initialize(step(edge.x, v.x), step(edge.y, v.y), step(edge.z, v.z)); }

float plane(Tvec3 ro, Tvec3 rd, Tvec3 p, float w) { return -(dot(ro, p) + w) / dot(rd, p); }