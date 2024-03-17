#pragma once
#include"ingredients.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
typedef enum difficulty {EASY , MEDIUM , HARD}DIFFICULTY;
typedef struct recipe {
	
	INGREDENT ingredents;
	//STEPS steps;
	char Title[MAXSTRINGSIZE];
	DIFFICULTY difficulty;

}RECIPE, *PRECIPE;


RECIPE CreateRecipe();

RECIPE CopyRecipe(RECIPE OriginalRecipe);