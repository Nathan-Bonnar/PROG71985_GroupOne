#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include"Recipe.h"
#include "stdlib.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list Implimentation
//
//Adds a recipe to a list
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
//compares a two recipes
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
//This function finds a recipe by taking in the list of recipes, the name of the recipe that the user wants to find, and updates the address of a preexiting recipe
bool FindRecipe(PLISTNODE* list, char* recipetitle, RECIPE* found)
{
	PLISTNODE current = *list;
	if (current == NULL)
	{
		return false;
	}

	do
	{
	if(findrecipewithtitle(&current->recipe, recipetitle))
	{
		*found = current->recipe;
		return true;
	}
	current = current->next;
	} while (current != NULL);

	return false;
}

//removes a recipe from a list of them
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

//displays a list of recipes 
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
//disposes all recipes 
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

bool loadRecipeFromdisk(PLISTNODE* r, char* filename)
{
	char newrecipebuffer[MAXSTRINGSIZE];
	char recipetitlebuffer[MAXSTRINGSIZE];
	char recipemealtypebuffer[MAXSTRINGSIZE];
	int loopvariable = 0;
	MEALTYPE whatmeal = { 0 };
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR READING FILE\n");
		return false;
	}	
	else
	{
		fgets(newrecipebuffer, MAXSTRINGSIZE, fp);
		newrecipebuffer[strcspn(newrecipebuffer, "\n")] = '\0';
		if (strncmp(newrecipebuffer, "NEWRECIPE", 9)!= 0)
		{
			fprintf(stderr, "ERROR READING FILE");
			return false;
		}

		while (loopvariable == 0)
		{
			PINGRDENTLISTNODE i = { 0 };
			fgets(recipetitlebuffer, MAXSTRINGSIZE, fp);
			recipetitlebuffer[strcspn(recipetitlebuffer, "\n")] = '\0';
			if (strncmp(recipetitlebuffer,"ENDOFFILE",9) == 0)
			{
				return false;
			}
			fgets(recipemealtypebuffer, MAXSTRINGSIZE, fp);
			recipemealtypebuffer[strcspn(recipemealtypebuffer, "\n")] = '\0';
			if (strncmp(recipemealtypebuffer, "BREAKFAST", 9) == 0)
			{
				whatmeal = BREAKFAST;
			}
			else if (strncmp(recipemealtypebuffer, "LUNCH", 5) == 0)
			{
				whatmeal = LUNCH;
			}
			else if (strncmp(recipemealtypebuffer, "DINNER", 6) == 0)
			{
				whatmeal = DINNER;
			}

			bool ingredentstest = loadingredentsfromdisk(&i, fp);

			RECIPE recipe = CreateRecipe(i, recipetitlebuffer, whatmeal);

			Add(r, recipe);
			
			if (ingredentstest == false)
			{
				return true;
			}
		}
	}


}

bool saverecipestodisk(PLISTNODE r, char * filename)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR WRITING TO FILE\n");
		return false;
	}

	PLISTNODE current = r;
	while (current != NULL)
	{
		fprintf(fp, "NEWRECIPE\n");
		SaveRecipetodisk(fp, current->recipe);
		current = current->next;
	}
	fprintf(fp, "ENDOFFILE\n");
	return true;
}

void RecipeRangeDisplayer(int starting, int ending, PLISTNODE recipelist) {

	PLISTNODE current = recipelist;
	RECIPE temprecipe = { 0 };
	int RecipeNumber = 1; 
	if (current == NULL)
		return;

	do {
		if (starting > RecipeNumber || RecipeNumber > ending) {
			current = current->next;
		}
		else {
			temprecipe = current->recipe; 
			PrintRecipe(temprecipe);
			current = current->next;
		}

		RecipeNumber++;
	} while (current != NULL);



	return; 
}

int getcurrentcount(PLISTNODE recipelist)
{
	PLISTNODE current = recipelist;
	int amount_of_recipes = 0;
	if (current == NULL)
	{
		return;
	}

	do
	{
		amount_of_recipes++;
		current = current->next;

	} while (current!=NULL);

	return amount_of_recipes;
}


void RandomRecipeDisplayer(PLISTNODE recipelist) {

	PLISTNODE current = recipelist;
	int totalRecipes = getcurrentcount(recipelist);
	if (totalRecipes == 0) {
		pintf("No recipes available.\n");
		return;
	}
	
	int randomNumber = rand() % totalRecipes;
	for (int i = 0; i < randomNumber; i++) {
		current = current->next;
	}

	RECIPE temprecipe = current->recipe;
	PrintRecipe(temprecipe);

	return;
}
