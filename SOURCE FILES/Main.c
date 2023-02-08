//DEFINE PART

//INCLUDE PART
	#include <stdio.h>
	
	#include "Objects.h"
	#include "SceneRender.h"
	#include "SceneCustomizer.h"

void Actions()
{
	printf("1.Start rendering\n"
		"2.Customize scene \n"
		"3.Close program \n"
		" Choose action: ");
}

main()
{
	unsigned int act;
	TPObject head = NULL;

	do
	{
		Actions();
		scanf_s("%u", &act); printf("\n");
		switch (act)
		{
		case 1:
			Rendering(head);
			break;
		case 2:
			customizeScene(&head);
			break;
		case 3:
			break;
		default:
			printf("Invalid choice.\n\n");
			break;
		}
	} while (act != 3);
}