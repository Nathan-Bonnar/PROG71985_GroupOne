#pragma once
#include"listofingredents.h"
#include"ingredients.h"
#define MAXAMOUNTOFINGREDENTS 20
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
// //Change difficulty to meal type
typedef enum difficulty {EASY , MEDIUM , HARD}DIFFICULTY;
typedef struct recipe {
	
	struct PINGRDENTLISTNODE* ingredents;
	//STEPS steps;
	char Title[MAXSTRINGSIZE];
	DIFFICULTY difficulty;

}RECIPE, *PRECIPE;


RECIPE CreateRecipe(struct PINGRDENTLISTNODE* ingredentslist, char* userstring, int diffiuculy);

RECIPE CopyRecipe(RECIPE OriginalRecipe);

bool CompareRecipe(RECIPE lhs, RECIPE rhs);

void DisposeRecipe(RECIPE r);

void PrintRecipe(RECIPE r);