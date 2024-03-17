#include"ingredients.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
INGREDENT CreateIngredent(char* ingredentNameInput, float ingredentAmountInput, char* ingredentUnitInput)
{
	INGREDENT i;
	strncpy(i.ingrdentName, ingredentNameInput, MAXSTRINGSIZE);
	strncpy(i.ingredentUnit, ingredentUnitInput, MAXSTRINGSIZE);
	i.ingredentAmount = ingredentAmountInput;
	return i;
}

void printIngredent(INGREDENT i)
{
	fprintf(stdout, "%s , %f , %s", i.ingrdentName, i.ingredentAmount, i.ingredentUnit);
}