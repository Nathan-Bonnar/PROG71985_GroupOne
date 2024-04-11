//PROG71985 W24 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//User Input Interface
//Grabs different types of user input 
#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXSIZE 100
float float_Number_input(char* outputstring);
int int_Number_input(char* outputstring);
bool StringInput(char* output_string, char* input_string);
char Char_input(char* outputstring);