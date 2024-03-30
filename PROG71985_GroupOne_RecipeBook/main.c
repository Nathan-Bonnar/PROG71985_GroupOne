//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book with the following features
//1. add a new recipe 
//2. delete an existing recipe 
//3. update an existing recipe
//4. display single recipe 
//5. display range recipe
//6. display all appt recipe
//7. search for recipe
//8. friendly / easy to use UI(or menu system)
//9. save accumulated data to disk
//10. load accumulated data from disk
#include<stdio.h>
#include"Recipe.h"
#include"ingredients.h"
#include"listofingredents.h"
#include"list.h"
#include"menu.h"
#include"User_Input.h"
int main()
{	
	int menucondition = 0;
	PINGRDENTLISTNODE menuingredentlist = { 0 };
	PLISTNODE menurecipelist = { 0 };
	while (menucondition == 0)
	{
		char menu_choice = PrintOptions();
		switch (menu_choice)
		{
		case 'a':
			menuingredentlist =  Createanewingredent(menuingredentlist);
			menurecipelist = Createanewrecipe(&menuingredentlist, menurecipelist);
			Display(menurecipelist);
			break;
		default:
			printf("please enter a valid choice\n");
			break;
		}
	}
	return 0;
}