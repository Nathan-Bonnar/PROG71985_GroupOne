#pragma once
#include<stdio.h>
#include "Recipe.h"
#include<stdlib.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list interface
typedef struct listnode {
	RECIPE recipe; 
	struct listnode* next;
}LISTNODE, *PLISTNODE;

void Add(PLISTNODE* list, RECIPE r);

bool Remove(PLISTNODE* list, RECIPE r);

bool saverecipestodisk(PLISTNODE r, char* filename);

void Display(PLISTNODE list);

void Dispose(PLISTNODE* list);

bool FindRecipe(PLISTNODE* list, char* recipetitle, RECIPE* found);


bool loadRecipeFromdisk(PLISTNODE* r, char* filename);