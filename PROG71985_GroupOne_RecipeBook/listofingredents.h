#pragma once
#include<stdio.h>
#include "Recipe.h"
#include"ingredients.h"
#include<stdlib.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list interface
typedef struct listofingredentnode {
	
	INGREDENTS ingredent;
	struct listofingredentnode* next;

}INGREDENTLISTNODE, *PINGRDENTLISTNODE;

void Addingredent(PINGRDENTLISTNODE* list, INGREDENTS ingredent);

bool CompareIngredentlist(PINGRDENTLISTNODE* list, PINGRDENTLISTNODE list2);

void Removeingredent(PINGRDENTLISTNODE* list, INGREDENTS ingredent);

void Displayingredent(PINGRDENTLISTNODE list);

void Disposeingredent(PINGRDENTLISTNODE* list);

void saveingredentstodisk(PINGRDENTLISTNODE list, FILE* fp);

bool loadingredentsfromdisk(PINGRDENTLISTNODE* i, FILE* fp);