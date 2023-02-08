//INCLUDE PART
	#include <math.h>

	#include "vec3.h"

Tvec3 rotateX(Tvec3 position, double angle)
{
	Tvec3 vector = position;
	vector.z = position.z * cos(angle) - position.y * sin(angle);
	vector.y = position.z * sin(angle) + position.y * cos(angle);

	return vector;
}

Tvec3 rotateY(Tvec3 position, double angle)
{
	Tvec3 vector = position;
	vector.x = position.x * cos(angle) - position.z * sin(angle);
	vector.z = position.x * sin(angle) + position.z * cos(angle);

	return vector;
}

Tvec3 rotateZ(Tvec3 position, double angle)
{
	Tvec3 vector = position;
	vector.x = position.x * cos(angle) - position.y * sin(angle);
	vector.y = position.x * sin(angle) + position.y * cos(angle);

	return vector;
}