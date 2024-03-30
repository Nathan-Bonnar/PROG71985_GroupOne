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

void Remove(PLISTNODE* list, RECIPE r);

void Display(PLISTNODE list);

void Dispose(PLISTNODE* list);