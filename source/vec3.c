//INCLUDE PART
	#include "vec3.h"

Tvec3 VecPlus(Tvec3 vector1, Tvec3 vector2)
{
	vector1.x += vector2.x;
	vector1.y += vector2.y;
	vector1.z += vector2.z;

	return vector1;
}

Tvec3 VecMins(Tvec3 vector1, Tvec3 vector2)
{
	vector1.x -= vector2.x;
	vector1.y -= vector2.y;
	vector1.z -= vector2.z;

	return vector1;
}

Tvec3 VecMult(Tvec3 vector1, Tvec3 vector2)
{
	vector1.x *= vector2.x;
	vector1.y *= vector2.y;
	vector1.z *= vector2.z;

	return vector1;
}

Tvec3 VecDivd(Tvec3 vector1, Tvec3 vector2)
{
	vector1.x /= vector2.x;
	vector1.y /= vector2.y;
	vector1.z /= vector2.z;

	return vector1;
}


Tvec3 SclPlus(Tvec3 vector, float value)
{
	vector.x += value;
	vector.y += value;
	vector.z += value;

	return vector;
}

Tvec3 SclMins(Tvec3 vector, float value)
{
	vector.x -= value;
	vector.y -= value;
	vector.z -= value;

	return vector;
}

Tvec3 SclMult(Tvec3 vector, float value)
{
	vector.x *= value;
	vector.y *= value;
	vector.z *= value;

	return vector;
}

Tvec3 SclDivd(Tvec3 vector, float value)
{
	vector.x /= value;
	vector.y /= value;
	vector.z /= value;

	return vector;
}

