#pragma once
#include<stdio.h>
#include"Steps.h"
#include<stdlib.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list interface
typedef struct listofsteps {
	
	STEP step;
	struct  listofsteps* next;

} LISTOFSTEPSNODE, *PLISTOFSTEPSNODE;

void addstep(PLISTOFSTEPSNODE* list, STEP step);

bool CompareSteplist(PLISTOFSTEPSNODE* list, PLISTOFSTEPSNODE* list2);

void Removestep(PLISTOFSTEPSNODE* list, STEP step);

void Displaystep(PLISTOFSTEPSNODE list);

void Disposestep(PLISTOFSTEPSNODE* list);

void savestepstodisk(PLISTOFSTEPSNODE list, FILE* fp);

bool loadstepsfromdisk(PLISTOFSTEPSNODE* list, FILE* fp);