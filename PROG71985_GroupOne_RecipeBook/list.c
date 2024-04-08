#include"list.h"
#include"Recipe.h"
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
	if(findrecipewithtitle(current->recipe, recipetitle))
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
	char recipedifficultybuffer[MAXSTRINGSIZE];
	int loopvariable = 0;
	DIFFICULTY howhard;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR WRITING TO FILE\n");
		return false;
	}	
	else
	{
		fgets(newrecipebuffer, MAXSTRINGSIZE, fp);
		newrecipebuffer[strcspn(newrecipebuffer, "\n")] = '\0';
		if (strncmp(newrecipebuffer, "NEWRECIPE", 9)!= 0)
		{
			fprintf(stderr, "ERROR READING FILE");
			exit(1);
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
			fgets(recipedifficultybuffer, MAXSTRINGSIZE, fp);
			recipedifficultybuffer[strcspn(recipedifficultybuffer, "\n")] = '\0';
			if (strncmp(recipedifficultybuffer, "EASY", 4))
			{
				howhard = EASY;
			}
			else if (strncmp(recipedifficultybuffer, "HARD", 4))
			{
				howhard = HARD;
			}
			else if (strncmp(recipedifficultybuffer, "MEDIUM", 6))
			{
				howhard = MEDIUM;
			}

			bool ingredentstest = loadingredentsfromdisk(&i, fp);

			RECIPE recipe = CreateRecipe(i, recipetitlebuffer, howhard);

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