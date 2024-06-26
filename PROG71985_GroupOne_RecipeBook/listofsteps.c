#define _CRT_SECURE_NO_WARNINGS
#include"listofsteps.h"
#include"Steps.h"
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// list Implimentation
//
void addstep(PLISTOFSTEPSNODE* list, STEP step)
{

	PLISTOFSTEPSNODE newNode = (PLISTOFSTEPSNODE)malloc(sizeof(LISTOFSTEPSNODE));
	if (newNode == NULL)
	{
		fprintf(stderr, "error allocaing memory\n");
		exit(1);
	}
	else
	{
		newNode->step = Copystep(step);
		newNode->next = *list;
		*list = newNode;
	}

}

void Removestep(PLISTOFSTEPSNODE* list, STEP step)
{
	PLISTOFSTEPSNODE current = *list;
	if (current != NULL && comparestep(current->step, step))
	{
		*list = current->next;
		free(current);
		return;
	}

	PLISTOFSTEPSNODE prev = NULL;
	while (current != NULL && !comparestep(current->step, step))
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;
	else
	{
		prev->next = current->next;
		free(current);
	}
}

bool CompareSteplist(PLISTOFSTEPSNODE* list, PLISTOFSTEPSNODE* list2)
{
	PLISTOFSTEPSNODE current = *list;
	PLISTOFSTEPSNODE current2 = list2;
	if (current == NULL || current2 == NULL)
	{
		return false;
	}
	do
	{
		if (comparestep(current->step, current2->step))
		{
			return true;
		}
		current = current->next;
		current2 = current2->next;
	} while (current != NULL && current2 != NULL);
	return false;
}


void Displaystep(PLISTOFSTEPSNODE list)
{
	PLISTOFSTEPSNODE current = list;
	if (current == NULL)
		return;
	fprintf(stdout, "Steps:\n");
	do
	{
		printstep(current->step);
		current = current->next;
	} while (current != NULL);
}

void Disposestep(PLISTOFSTEPSNODE* list)
{
	PLISTOFSTEPSNODE current = *list;
	while (current != NULL) {
		PLISTOFSTEPSNODE tmp = current;
		
		current = current->next;
		free(tmp);
	}
}


void savestepstodisk(PLISTOFSTEPSNODE list, FILE* fp)
{
	PLISTOFSTEPSNODE current = list;
	while (current != NULL)
	{
		savesteptodisk(current->step, fp);
		current = current->next;
	}
}


bool loadstepsfromdisk(PLISTOFSTEPSNODE* list, FILE* fp)
{
	char steptitlebuffer[MAXSTRINGSIZE];
	char stepinstructionbuffer[MAXSTRINGSIZE];
	int ingredentsloop = 0;
	while (ingredentsloop == 0)
	{
		fgets(steptitlebuffer, MAXSTRINGSIZE, fp);
		steptitlebuffer[strcspn(steptitlebuffer, "\n")] = '\0';
		if (strncmp(steptitlebuffer, "NEWRECIPE", 9) == 0)
		{
			return true;
		}
		else if (strncmp(steptitlebuffer, "ENDOFFILE", 9) == 0)
		{
			return false;
		}
		fgets(stepinstructionbuffer, MAXSTRINGSIZE, fp);
		stepinstructionbuffer[strcspn(stepinstructionbuffer, "\n")] = '\0';
		
		STEP step = Createstep(steptitlebuffer, stepinstructionbuffer);
		
		addstep(list, step);

	}
}