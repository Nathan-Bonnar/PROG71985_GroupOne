#include"ingredients.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
INGREDENTS CreateIngredent(char* ingredentNameInput, float ingredentAmountInput, char* ingredentUnitInput)
{
	INGREDENTS i = { 0 };
	strncpy(i.ingrdentName, ingredentNameInput, MAXSTRINGSIZE);
	strncpy(i.ingredentUnit, ingredentUnitInput, MAXSTRINGSIZE);
	i.ingredentAmount = ingredentAmountInput;
	return i;
}


void printIngredent(INGREDENTS i)
{
	fprintf(stdout, "%s , %f , %s\n", i.ingrdentName, i.ingredentAmount, i.ingredentUnit);
}

INGREDENTS CopyIngredent(INGREDENTS source)
{
	return CreateIngredent(source.ingrdentName, source.ingredentAmount, source.ingredentUnit);
}

bool compareIngredents(INGREDENTS lhs[MAXAMOUNTOFINGREDENTS], INGREDENTS rhs[MAXAMOUNTOFINGREDENTS])
{
	for (int i = 0; i < MAXAMOUNTOFINGREDENTS; i++)
	{
		if (compareIngredent(lhs[i], rhs[i]))
		{
			return true;
		}
	}
	return false;
}

bool compareIngredent(INGREDENTS lhs, INGREDENTS rhs)
{
	if ((strncmp(lhs.ingrdentName, rhs.ingrdentName, MAXSTRINGSIZE) == 0 && (strncmp(lhs.ingredentUnit, rhs.ingredentUnit, MAXSTRINGSIZE)) == 0 && (lhs.ingredentAmount == rhs.ingredentAmount)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool saveingredenttodisk(INGREDENTS i,FILE* fp)
{
	fprintf(fp, "%s\n", i.ingrdentName);
	fprintf(fp, "%s\n", i.ingredentUnit);
	fprintf(fp, "%f\n", i.ingredentAmount);
	return true;
}

//INGREDENTS LoadIngredentsFromdisk(FILE* fp)
//{
//	char namebuffer[MAXSTRINGSIZE] = { 0 };
//	fgets(namebuffer, MAXSTRINGSIZE, fp);
//}