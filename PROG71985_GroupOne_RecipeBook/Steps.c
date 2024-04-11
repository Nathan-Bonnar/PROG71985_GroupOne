#include"Steps.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//Recipe Interface
STEP Createstep(char* steptitle, char* instruction)
{
	STEP s = { 0 };
	strncpy(s.steptitle, steptitle, MAXSTRINGSIZE);
	strncpy(s.instruction, instruction, MAXSTRINGSIZE);
	return s;
}


void printstep(STEP s)
{
	fprintf(stdout, "%s , %s\n", s.steptitle, s.instruction);
	return;
}

STEP Copystep(STEP source)
{
	return Createstep(source.steptitle, source.instruction);
}


bool comparestep(STEP lhs, STEP rhs)
{
	if ((strncmp(lhs.steptitle, rhs.steptitle, MAXSTRINGSIZE) == 0 && (strncmp(lhs.instruction, rhs.instruction, MAXSTRINGSIZE)) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool savesteptodisk(STEP s, FILE* fp)
{
	fprintf(fp, "%s\n", s.steptitle);
	fprintf(fp, "%s\n", s.instruction);
	return true;
}
