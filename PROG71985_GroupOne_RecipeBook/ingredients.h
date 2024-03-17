#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define MAXSTRINGSIZE 100
#include<string.h>
#include<stdio.h>
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//ingredients inplimentation
typedef struct ingredents {

	char ingrdentName[MAXSTRINGSIZE];
	float ingredentAmount;
	char ingredentUnit[MAXSTRINGSIZE];


}INGREDENT, PINGREDENT;

INGREDENT CreateIngredent(char* ingredentName, float ingredentAmount, char* ingredentUnit);
void printIngredent(INGREDENT i);
