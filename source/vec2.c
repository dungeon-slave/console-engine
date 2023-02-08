//INCLUDE PART
	#include "vec2.h"

Tvec2 vecplus(Tvec2 vector1, Tvec2 vector2)
{
	vector1.x += vector2.x;
	vector1.y += vector2.y;

	return vector1;
}

Tvec2 vecmins(Tvec2 vector1, Tvec2 vector2)
{
	vector1.x -= vector2.x;
	vector1.y -= vector2.y;

	return vector1;
}

Tvec2 vecmult(Tvec2 vector1, Tvec2 vector2)
{
	vector1.x *= vector2.x;
	vector1.y *= vector2.y;

	return vector1;
}

Tvec2 vecdivd(Tvec2 vector1, Tvec2 vector2)
{
	vector1.x /= vector2.x;
	vector1.y /= vector2.y;

	return vector1;
}


Tvec2 sclplus(Tvec2 vector, float value)
{
	vector.x += value;
	vector.y += value;

	return vector;
}

Tvec2 sclmins(Tvec2 vector, float value)
{
	vector.x -= value;
	vector.y -= value;

	return vector;
}

Tvec2 sclmult(Tvec2 vector, float value)
{
	vector.x *= value;
	vector.y *= value;

	return vector;
}

Tvec2 scldivd(Tvec2 vector, float value)
{
	vector.x /= value;
	vector.y /= value;

	return vector;
}