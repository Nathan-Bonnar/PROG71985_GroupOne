//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// menu implimentation
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
#include"menu.h"
char PrintOptions()
{
	char output[MAXSIZE] = "Please choose an option: ";
	printf("please enter the choice of the option you want to select\n");
	printf("a.) Add a new Recipe\n");
	printf("b.)Delete an exitsing Recipe\n");
	printf("c.)Update an exitsing Recipe\n");
	printf("d.)Display a single recipe\n");
	printf("e.)Display a range of recipes\n");
	printf("f.)Display All appt recipes\n");
	printf("g.)Search For a recipe\n");
	
	char charanswer = Char_input(output);
	
	return charanswer;
}

PINGRDENTLISTNODE Createanewingredent()
{
	int ingredents_check = 0;
	PINGRDENTLISTNODE functioningredentslist = { 0 };
	char output_name[MAXSIZE] = "Please enter an ingredents name: ";
	char output_unit[MAXSIZE] = "What is the unit you would like to use for that ingredent: ";
	char output_amount[MAXSIZE] = "How much of that ingredent is needed: ";
	char output_end[MAXSIZE] = "would you like to add a new ingredent ( Y | N ): ";
	float buffer_amount;
	char buffer_ingredent[MAXSIZE];
	char buffer_unit[MAXSIZE];
	INGREDENTS temp_ingredent;
	char menu_input;
	do
	{
		StringInput(output_name, buffer_ingredent);
		StringInput(output_unit, buffer_unit);
		buffer_amount = float_Number_input(output_amount);
		temp_ingredent = CreateIngredent(buffer_ingredent, buffer_amount, buffer_unit);
		Addingredent(&functioningredentslist, temp_ingredent);
		menu_input =  Char_input(output_end);
		if (menu_input == 'n')
		{
			ingredents_check = 1;
		}
	} while (ingredents_check == 0);
	
	//temp_recipe = CreateRecipe(&ingredentslist);
	//Add(&recipelist, temp_recipe);
	//INGREDENTS ingredent = CreateIngredent("tumric", 5 , "kg");
	//Addingredent(&functioningredentslist, ingredent);
	//RECIPE recipe = CreateRecipe(&functioningredentslist);
	//Add(&funtcionrecipelist, recipe);
	
	return functioningredentslist;
}

PLISTNODE Createanewrecipe(PINGRDENTLISTNODE functioningredentslist, PLISTNODE functionrecipelist)
{
	RECIPE temp_recipe;
	char title_output[MAXSIZE] = "What would you like the title of the recipe to be: ";
	char title_input[MAXSIZE];
	char difficulty_output[MAXSIZE] = "Is the difficulty of this recipe Easy(0) , Medium(1) , or Hard(3): ";
	int difficulty_choice = int_Number_input(difficulty_output);
	StringInput(title_output, title_input);
	temp_recipe = CreateRecipe(functioningredentslist, title_input,difficulty_choice);
	Add(&functionrecipelist, temp_recipe);
	return functionrecipelist;
}