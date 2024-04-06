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

bool CompareRecipelist  (PLISTNODE lhsrecipe, PLISTNODE rhsrecipe)
{
	PLISTNODE current1 = lhsrecipe;
	PLISTNODE current2 = rhsrecipe;
	if (current1 == NULL || current2 == NULL)
	{
		return false;
	}
	if (CompareRecipe(current1->recipe, current2->recipe))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FindRecipe(PLISTNODE* list, char* recipetitle, RECIPE* found)
{
	PLISTNODE current = *list;
	if (current == NULL)
	{
		return false;
	}

	do
	{
	if(findrecipewithtitle(current->recipe, recipetitle))
	{
		*found = current->recipe;
		return true;
	}
	current = current->next;
	} while (current != NULL);

	return false;
}


bool Remove(PLISTNODE* list, RECIPE r)
{
	PLISTNODE current = *list;
	if (current != NULL && CompareRecipe(current->recipe, r))
	{
		*list = current->next;
		Disposeingredent(&current->recipe.ingredents);
		free(current);
		return true;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareRecipe(current->recipe, r))
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return false;
	else
	{
		prev->next = current->next;
		Disposeingredent(&current->recipe.ingredents);
		free(current);
		return true;
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