#include"list.h"
#include"Recipe.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list Implimentation
//
void Add(PLISTNODE* list, RECIPE r)
{

PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
if (newNode == NULL) 
{
	fprintf(stderr, "error allocaing memory\n");
	exit(1);
}
else
{
	newNode->recipe = CopyRecipe(r);
	newNode->next = *list;
	*list = newNode;
}

}

void Remove(PLISTNODE* list, RECIPE r)
{
	PLISTNODE current = *list;
	if (current != NULL && CompareRecipe(current->recipe, r))
	{
		*list = current->next;
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareRecipe(current->recipe, r))
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
void Display(PLISTNODE list)
{
	PLISTNODE current = list;
	if (current == NULL)
		return;

	do 
	{
		PrintRecipe(current->recipe);
		current = current->next;
	} while (current != NULL);
}

void Dispose(PLISTNODE* list) 
{
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DisposeRecipe(current->recipe);
		current = current->next;
		free(tmp);
	}
}