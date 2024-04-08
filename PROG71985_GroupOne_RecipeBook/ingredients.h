#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define MAXSTRINGSIZE 100
#define MAXAMOUNTOFINGREDENTS 20
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//ingredients inplimentation
typedef struct ingredents {

	char ingrdentName[MAXSTRINGSIZE];
	float ingredentAmount;
	char ingredentUnit[MAXSTRINGSIZE];


}INGREDENTS, PINGREDENTS;

INGREDENTS CreateIngredent(char* ingredentName, float ingredentAmount, char* ingredentUnit);

void printIngredents(INGREDENTS i[MAXAMOUNTOFINGREDENTS]);

bool saveingredenttodisk(INGREDENTS i, FILE* fp);

void printIngredent(INGREDENTS i);

INGREDENTS CopyIngredent(INGREDENTS source);

bool compareIngredents(INGREDENTS lhs[MAXAMOUNTOFINGREDENTS], INGREDENTS rhs[MAXAMOUNTOFINGREDENTS]);

bool compareIngredent(INGREDENTS lhs, INGREDENTS rhs);
