#include"listofingredents.h"
#include"Recipe.h"
#include"ingredients.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list Implimentation
//
void Addingredent(PINGRDENTLISTNODE* list, INGREDENTS ingredent)
{

	PINGRDENTLISTNODE newNode = (PINGRDENTLISTNODE)malloc(sizeof(INGREDENTLISTNODE));
	if (newNode == NULL)
	{
		fprintf(stderr, "error allocaing memory\n");
		exit(1);
	}
	else
	{
		newNode->ingredent = CopyIngredent(ingredent);
		newNode->next = *list;
		
		*list = newNode;
	}

}

void Removeingredent( PINGRDENTLISTNODE* list, INGREDENTS ingredent)
{
	 PINGRDENTLISTNODE current = *list;
	if (current != NULL && compareIngredent(current->ingredent, ingredent))
	{
		*list = current->next;
		free(current);
		return;
	}

	 PINGRDENTLISTNODE prev = NULL;
	while (current != NULL && !compareIngredent(current->ingredent, ingredent))
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;
	else
	{
		prev->next = current->next;
		free(current);
	}
}

bool CompareIngredentlist(PINGRDENTLISTNODE list, PINGRDENTLISTNODE list2)
{
	PINGRDENTLISTNODE current = list;
	PINGRDENTLISTNODE current2 = list2;
	if (current == NULL || current2 == NULL)
	{
		return false;
	}
	do
	{
		if (compareIngredent(current->ingredent, current2->ingredent))
		{
			return true;
		}
		current = current->next;
		current2 = current2->next;
	} while (current != NULL || current2 != NULL);
}


void Displayingredent(PINGRDENTLISTNODE ingredentlist)
{
	PINGRDENTLISTNODE current = ingredentlist;
	if (current == NULL)
		return;

	do
	{
		printIngredent(current->ingredent);
		current = current->next;
	} while (current != NULL);
}

void Disposeingredent( PINGRDENTLISTNODE* list)
{
	 PINGRDENTLISTNODE current = *list;
	while (current != NULL) {
		 PINGRDENTLISTNODE tmp = current;
		
		current = current->next;
		free(tmp);
	}
}