#pragma once
#include<stdio.h>
#include "Recipe.h"
#include<stdlib.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list interface
typedef struct list {
	RECIPE recipe; 
	struct listnode* next;
}LISTNODE, *PLISTNODE;

void Add(PLISTNODE*, RECIPE r);

void Remove(PLISTNODE*, RECIPE r);

void Display(PLISTNODE, RECIPE r);

void Dispose(PLISTNODE*, RECIPE r);