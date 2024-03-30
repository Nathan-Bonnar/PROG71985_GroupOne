//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Implimentation
#include"Recipe.h"
#pragma warning(disable : 4996)
#define MAXSTRINGSIZE 100
RECIPE CreateRecipe(struct PINGRDENTLISTNODE* ingredentslist, char * userstring, int diffiuculy)
{
	RECIPE recipe = { 0 };
	recipe.ingredents = ingredentslist;
	strncpy(recipe.Title, userstring, MAXSTRINGSIZE);
	recipe.difficulty = diffiuculy;
	return recipe;
}

RECIPE CopyRecipe(RECIPE OriginalRecipe)
{
	RECIPE recipe = CreateRecipe(OriginalRecipe.ingredents, OriginalRecipe.Title, OriginalRecipe.difficulty);
	return recipe;
}

bool CompareRecipe(RECIPE lhs, RECIPE rhs)
{
	if (!(CompareIngredentlist(lhs.ingredents, rhs.ingredents)))
	{
		return false;
	}
	else
	{
		return true;
	}

}

void PrintRecipe(RECIPE r)
{
	printf("Title:%s\n", r.Title);
	printf("Difficulty:");
	if (r.difficulty == EASY)
	{
		printf("EASY\n");
	}
	else if (r.difficulty == MEDIUM)
	{
		printf("MEDIUM\n");
	}
	else if (r.difficulty == HARD)
	{
		printf("HARD\n");
	}
	
	Displayingredent(r.ingredents);
}

void DisposeRecipe(RECIPE r)
{
	Disposeingredent(r.ingredents);
}