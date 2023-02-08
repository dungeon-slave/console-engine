#ifndef ROTATION_H
#define ROTATION_H

typedef Tvec3(*TRotation)(Tvec3, double);
	Tvec3 rotateX(Tvec3 vector, double angle);
	Tvec3 rotateY(Tvec3 vector, double angle);
	Tvec3 rotateZ(Tvec3 vector, double angle);

#endif