//DEFINE PART
	#define _CRT_SECURE_NO_WARNINGS

//INCLUDE PART
	#include <stdio.h>
	#include <conio.h>

	#include "vec2.h"
	#include "Objects.h"
	#include "VecFunctions.h"
	#include "Bodies.h"
    #include "Constants.h"
	#include "Rotation.h"

void SphIntersection(Tvec3* n, float* minIt, Tvec3 ro, Tvec3 rd, Tvec3 pos, float size)
{
	Tvec2 intersect;

	intersect = sphere(VecPlus(ro, pos), rd, size);
	if (intersect.x > 0)
	{
		*n = VecMins(ro, VecPlus(pos, SclMult(rd, intersect.x)));
		*n = norm(*n);
		*minIt = intersect.x;
	}
}

void BoxIntersection(Tvec3* n, float* minIt, Tvec3 ro, Tvec3 rd, Tvec3 pos, float size)
{
	Tvec2 intersect;
	Tvec3 boxN = Initialize(0, 0, 0);

	intersect = box(VecPlus(ro, pos), rd, size, &boxN);
	if (intersect.x > 0 && intersect.x < *minIt)
	{
		*n = boxN;
		*minIt = intersect.x;
	}
}


void renderScene(Tvec3 angle, float zoom, char screen[], TPObject head)
{
	TPObject temp = NULL;

	int   color;
	char  pixel;
	float diffuse;

	Tvec2 uv;
	Tvec3 ro;
	Tvec3 rd;

	Tvec2 intersection;	
	Tvec3 light;		
	Tvec3 n;

	light = norm(Initialize(-0.5f, 0.5f, -1.0f));

	for (size_t i = 0; i < WINDOW_WIDTH; i++)
	{
		for (size_t j = 0; j < WINDOW_HEIGHT; j++)
		{
			uv.x = (float)i / WINDOW_WIDTH * 2.0f - 1.0f;
			uv.y = (float)j / WINDOW_HEIGHT * 2.0f - 1.0f;
			uv.x *= charAspect * windowAspect;

			rd = norm(Initialize(1.0f, uv.x, uv.y));


			ro = Initialize(-2.0f + zoom, 0.0f, 0.0f);

			//Rotation
				ro = rotateX(ro, angle.x);
				rd = rotateX(rd, angle.x);
				ro = rotateY(ro, angle.y);
				rd = rotateY(rd, angle.y);
				ro = rotateZ(ro, angle.z);
				rd = rotateZ(rd, angle.z);

			diffuse = 1;

			for (int k = 0; k < 5; k++)
			{
				float minIt = 99999;
				n = Initialize(0, 0, 0);
				float albedo = 1;

				temp = head;
				while (temp != NULL)
				{
					if (temp->Data.Type == 1)
					{
						SphIntersection(&n, &minIt, ro, rd, temp->Data.Pos, temp->Data.Size);
					}

					if (temp->Data.Type == 2)
					{
						BoxIntersection(&n, &minIt, ro, rd, temp->Data.Pos, temp->Data.Size);
					}

					temp = temp->next;
				}

				Tvec3 p = Initialize(0, 0, -1);
				p = norm(p);
				intersection.x = plane(ro, rd, p, 1);
				if (intersection.x > 0 && intersection.x < minIt)
				{
					minIt = intersection.x;
					n = p;
					albedo = 0.5;
				}

				if (minIt < 99999)
				{
					diffuse *= (dot(n, light) * 0.5f + 0.5f) * albedo;
					ro = VecPlus(ro, SclMult(rd, (minIt - 0.01f)));
					rd = reflect(rd, n);
				}
				else break;
			}

			color = (int)(diffuse * 20);
			color = clamp(color, 0, gradientSize - 1);
			pixel = gradient[color];

			screen[i + j * WINDOW_WIDTH] = pixel;
		}
	}

	printf("%s", screen);
}


void Rendering(TPObject head)
{
	char screen[WINDOW_WIDTH * WINDOW_HEIGHT + 1] = "/0";
	Tvec3 angle = Initialize(0.0f, 0.0f, 0.0f);
	float zoom = 0.0f;
	char key = 0;

	renderScene(angle, zoom, screen, head);
	while (key != 27)
	{
		key = _getch();

		switch (key)
		{
 			case -28:
			case 'a':
			{
				angle.z -= 0.03f;
				renderScene(angle, zoom, screen, head);
				break;
			}
			case -94:
			case 'd':
			{
				angle.z += 0.03f;
				renderScene(angle, zoom, screen, head);
				break;
			}

			case -87:
			case 'q':
			{
				angle.y -= 0.03f;
				renderScene(angle, zoom, screen, head);
				break;
			}
			case -29:
			case 'e':
			{
				angle.y += 0.03f;
				renderScene(angle, zoom, screen, head);
				break;
			}

			case -26:
			case 'w':
			{
				angle.x += 0.03f;
				renderScene(angle, zoom, screen,head);
				break;
			}
			case -21: 
			case 's':
			{
				angle.x -= 0.03f;
				renderScene(angle, zoom, screen, head);
				break;
			}

			case '+':
			{
				zoom += 0.05f;
				renderScene(angle, zoom, screen, head);
				break;
			}
			case '-':
			{
				zoom -= 0.05f;
				renderScene(angle, zoom, screen, head);
				break;
			}
		}
	}
}