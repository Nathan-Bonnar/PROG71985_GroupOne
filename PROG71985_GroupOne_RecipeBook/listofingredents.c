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

void Removeingredent(PINGRDENTLISTNODE* list, INGREDENTS ingredent)
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

bool CompareIngredentlist(PINGRDENTLISTNODE* list, PINGRDENTLISTNODE list2)
{
	PINGRDENTLISTNODE current = *list;
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
	} while (current != NULL && current2 != NULL);
	return false;
}


void Displayingredent(PINGRDENTLISTNODE ingredentlist)
{
	PINGRDENTLISTNODE current = ingredentlist;
	if (current == NULL)
		return;
	fprintf(stdout, "Ingredents:\n");
	do
	{
		printIngredent(current->ingredent);
		current = current->next;
	} while (current != NULL);
}

void Disposeingredent(PINGRDENTLISTNODE* list)
{
	PINGRDENTLISTNODE current = *list;
	while (current != NULL) {
		 PINGRDENTLISTNODE tmp = current;
		
		current = current->next;
		free(tmp);
	}
}


void saveingredentstodisk(PINGRDENTLISTNODE list, FILE* fp)
{
	PINGRDENTLISTNODE current = list;
	while (current != NULL)
	{
		saveingredenttodisk(current->ingredent, fp);
		current = current->next;
	}
}


bool loadingredentsfromdisk(PINGRDENTLISTNODE * i,  FILE* fp)
{
	char Recipetitlebuffer[MAXSTRINGSIZE];
	char Recipeunitbuffer[MAXSTRINGSIZE];
	float Recipeamountbuffer;
	int ingredentsloop = 0;
	while (ingredentsloop == 0)
	{
		fgets(Recipetitlebuffer, MAXSTRINGSIZE, fp);
		Recipetitlebuffer[strcspn(Recipetitlebuffer, "\n")] = '\0';
		if (strncmp(Recipetitlebuffer, "NEWRECIPE", 9) == 0)
		{
			return true;
		}
		else if (strncmp(Recipetitlebuffer, "ENDOFFILE", 9) == 0)
		{
			return false;
		}
		fgets(Recipeunitbuffer, MAXSTRINGSIZE, fp);
		Recipeunitbuffer[strcspn(Recipeunitbuffer, "\n")] = '\0';
		int number_check = fscanf(fp, "%f\n", &Recipeamountbuffer);
		
		INGREDENTS ingredent =  CreateIngredent(Recipetitlebuffer, Recipeamountbuffer, Recipeunitbuffer);
		
		Addingredent(i, ingredent);

	}
}