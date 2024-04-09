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
#include<stdlib.h>
#include"Recipe.h"
#include"ingredients.h"
#include"listofingredents.h"
#include"list.h"
#include"menu.h"
#include"User_Input.h"
int main()
{	
	char Recipefilename[MAXSTRINGSIZE] = "Recipes.dat";
	int menucondition = 0;
	PLISTNODE menurecipelist = { 0 };
	char testingstring[MAXSTRINGSIZE] = "Test";
	RECIPE testfindrecipe;
	loadRecipeFromdisk(&menurecipelist, Recipefilename);
	
	while (menucondition == 0)
	{
		PINGRDENTLISTNODE menuingredentlist;
		char menu_choice = PrintOptions();
		switch (menu_choice)
		{
		case 'a': //a.)Add a new Recipe
			menuingredentlist =  Createanewingredent();
			menurecipelist = Createanewrecipe(menuingredentlist, menurecipelist);
			Display(menurecipelist);
			break;
		case 'b'://b.)Delete an exitsing Recipe
			DeleteArecipe(&menurecipelist);
			break;
		case 'c'://c.)Update an exitsing Recipe

			break;
		case 'd'://d.)Display a single recipe
			DisplayARecipe(&menurecipelist);
			break;
		case 'e'://e.)Display a range of recipes

			break;
		case 'f'://f.)Display All appt recipes

			break;
		case 'g'://g.)Search For a recipe
			searchforarecipe(&menurecipelist);
			break;
		case 'h'://0.)To exit 
			saverecipestodisk(menurecipelist, Recipefilename);
			Dispose(&menurecipelist);
			menucondition = 1;
			break;
		default:
			printf("please enter a valid choice\n\n");
			break;
		}
	}
	
	return 0;
}