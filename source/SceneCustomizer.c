//DEFINE PART

//INCLUDE PART
	#include <stdio.h>

	#include "Objects.h"

void SC_Actions()
{
	printf("1.Add object\n"
		   "2.Delete object\n"
		   "3.Show objects list\n"
		   "4.Exit\n"
		   " Choose action: ");
}

void showObjList(TPObject head)
{
	printf("LIST OF SCENE OBJECTS: \n\n");

	if (head != NULL)
	{
		do
		{
			printf("\tType: %d\t\tSize: %.2f\tPosX: %.2f\tPosY: %.2f\tPosZ: %.2f\n", 
					head->Data.Type, 
					head->Data.Size, 										
					head->Data.Pos.x, 
					head->Data.Pos.y, 
					head->Data.Pos.z);
			head = head->next;
		} while (head != NULL);
		printf("\n");
	}
	else
	{
		printf("THE LIST IS EMPTY!\n\n");
	}
}

TPObject customizeScene(TPObject* head)
{
	unsigned int act;

	do
	{
		SC_Actions();
		scanf_s("%u", &act); printf("\n");

		switch (act)
		{
			case 1:
			{
				addObject(&(*head));
				break;
			}
			case 2:
			{
				delObject(&(*head));
				break;
			}
			case 3:
			{
				showObjList(*head);
				break;
			}
			case 4:
			{
				break;
			}
			default:
			{
				printf("Invalid choice.\n\n");
			}
		}
	} while (act != 4);

	return *head;
}