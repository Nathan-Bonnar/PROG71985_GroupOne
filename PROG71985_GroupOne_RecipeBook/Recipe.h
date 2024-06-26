#pragma once
#include"listofingredents.h"
#include"Steps.h"
#include"listofsteps.h"
#include"ingredients.h"
#define MAXAMOUNTOFINGREDENTS 20
//PROG71985 W24 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
// //Change difficulty to meal type
typedef enum mealtype{BREAKFAST, LUNCH, DINNER}MEALTYPE;
typedef struct recipe {
	
	struct PINGRDENTLISTNODE* ingredents;
	struct PSTEPSLISTNODE* steps;
	char Title[MAXSTRINGSIZE];
	MEALTYPE whatmeal;

}RECIPE, *PRECIPE;


RECIPE CreateRecipe(struct PINGRDENTLISTNODE* ingredentslist, struct PSTEPSLISTNODE* steps,  char* userstring, MEALTYPE mealtype);

RECIPE CopyRecipe(RECIPE OriginalRecipe);

bool CompareRecipe(RECIPE lhs, RECIPE rhs);

void DisposeRecipe(RECIPE r);

void PrintRecipe(RECIPE r);

bool findrecipewithtitle(RECIPE* testing, char* goal);

void SaveRecipetodisk(FILE* fp, RECIPE r);