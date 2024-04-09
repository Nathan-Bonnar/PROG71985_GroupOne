//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Implimentation
#include"Recipe.h"
#pragma warning(disable : 4996)
#define MAXSTRINGSIZE 100
RECIPE CreateRecipe(struct PINGRDENTLISTNODE* ingredentslist, char * userstring, MEALTYPE mtype)
{
	RECIPE recipe = { 0 };
	recipe.ingredents = ingredentslist;
	strncpy(recipe.Title, userstring, MAXSTRINGSIZE);
	recipe.whatmeal = mtype;
	return recipe;
}

RECIPE CopyRecipe(RECIPE OriginalRecipe)
{
	RECIPE recipe = CreateRecipe(OriginalRecipe.ingredents, OriginalRecipe.Title, OriginalRecipe.whatmeal);
	return recipe;
}

bool CompareRecipe(RECIPE lhs, RECIPE rhs)
{
	if (!(CompareIngredentlist(&lhs.ingredents, rhs.ingredents)))
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
	printf("MEAL TYPE:");
	if (r.whatmeal == BREAKFAST)
	{
		printf("BREAKFAST\n");
	}
	else if (r.whatmeal == LUNCH)
	{
		printf("LUNCH\n");
	}
	else if (r.whatmeal == DINNER)
	{
		printf("DINNER\n");
	}
	
	Displayingredent(r.ingredents);
}

void DisposeRecipe(RECIPE r)
{
	Disposeingredent(&r.ingredents);
}



bool findrecipewithtitle(RECIPE* testing, char* goal)
{
	if (strncmp(testing->Title, goal, MAXSTRINGSIZE) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SaveRecipetodisk(FILE* fp, RECIPE r)
{

	fprintf(fp, "%s\n", r.Title);
	if (r.whatmeal == BREAKFAST)
	{
		fprintf(fp, "BREAKFAST\n");
	}
	else if (r.whatmeal == LUNCH)
	{
		fprintf(fp , "LUNCH\n");
	}
	else if (r.whatmeal == DINNER)
	{
		fprintf(fp , "DINNER\n");
	}

	saveingredentstodisk(r.ingredents, fp);

}