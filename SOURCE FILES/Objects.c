//DEFINE PART

//INCLUDE PART
	#include <stdio.h>
	#include <stdlib.h>
	
	#include "Objects.h"

TData createObject()
{
	printf("INPUT INFO ABOUT OBJECT\n\n");

	int type;
		do
		{
			printf("Types of objects: "
				"1 - Sphere, "
				"2 - Box\n\n"
				"Choose object\n Input: ");
			scanf_s("%u", &type); printf("\n");

			switch (type)
			{
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
				printf("UNCORRECT TYPE. REPEAT INPUT!\n\n");
				break;
			}
			}
		} while (!(type == 1 || type == 2));

	float size;
		printf(" Size: ");
		scanf_s("%f", &size); printf("\n");

	Tvec3 pos;
		printf("Input position\n");
		printf(" X: "); scanf_s("%f", &pos.x);
		printf(" Y: "); scanf_s("%f", &pos.y);
		printf(" Z: "); scanf_s("%f", &pos.z); printf("\n");

	TData Object;
		Object.Pos  = pos;
		Object.Size = size;
		Object.Type = type;

	return Object;
}


void addObject(TPObject* head)
{
	if (addNode(&(*head), createObject()))
	{
		printf("OBJECT SUCCESFULLY ADDED\n\n");
	}
	else
	{
		printf("ADD ERROR. OBJECT NOT ADDED!\n\n");
	}
}

void delObject(TPObject* head)
{
	if (*head != NULL)
	{
		if (delNode(&(*head), &(*head), createObject()))
		{
			printf("OBJECT SUCCESFULLY DELETED\n\n");
		}
		else
		{
			printf("DELETE ERROR. MAYBE INFO ABOUT OBJECT IS UNCORRECT!\n\n");
		}
	}
	else
	{
		printf("DELETE ERROR. LIST IS EMPTY!\n\n");
	}
}


int delNode(TPObject* head, TPObject* pred, TData Object)
{
	if (*head != NULL)
	{
		if (
			((*head)->Data.Type == Object.Type)
			&& ((*head)->Data.Size == Object.Size)

			&& ((*head)->Data.Pos.x == Object.Pos.x)
			&& ((*head)->Data.Pos.y == Object.Pos.y)
			&& ((*head)->Data.Pos.z == Object.Pos.z)
		   )
		{
			TPObject tmp = *head;

			if (*pred == *head)
			{
				*head = (*head)->next;
			}
			else
			{
				(*pred)->next = (*head)->next;
			}

			free(tmp);

			return 1;
		}
		else
		{
			delNode(&(*head)->next, &(*head), Object);
		}
	}

	return 0;
}

int addNode(TPObject* head, const TData Object)
{
	if (*head == NULL)
	{
		*head = malloc(sizeof(TObject));
		if (*head != NULL)
		{
			(*head)->Data = Object;
			(*head)->next = NULL;

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		addNode(&(*head)->next, Object);
	}

	return 1;
}