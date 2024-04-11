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
typedef struct step {


	char steptitle[MAXSTRINGSIZE];
	char instruction[MAXSTRINGSIZE];

}STEP, *PSTEP;

STEP Createstep(char * steptitle, char * instruction);

void printstep(STEP s);

bool savesteptodisk(STEP s, FILE* fp);

STEP Copystep(STEP source);

bool comparestep(STEP lhs, STEP rhs);
