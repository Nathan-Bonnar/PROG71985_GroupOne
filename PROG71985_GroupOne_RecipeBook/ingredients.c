#include"ingredients.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
INGREDENT CreateIngredent(char* ingredentName, float ingredentAmount, char* ingredentUnit)
{
	INGREDENT i;
	strncpy(i.ingrdentName, ingredentName, MAXSTRINGSIZE);
	strncpy(i.ingredentUnit, ingredentUnit, MAXSTRINGSIZE);
	i.ingredentAmount = ingredentAmount;
	return i;
}

void printIngredent(INGREDENT i)
{
	printf("%s , %f , %s", i.ingrdentName, i.ingredentAmount, i.ingredentUnit);
}