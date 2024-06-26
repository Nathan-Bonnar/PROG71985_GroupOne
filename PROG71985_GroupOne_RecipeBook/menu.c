//PROG71985 W24 Nathan Bonnar - Carter Blackie - Nicholas Rojas  
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
//11. random recipe display
#include"menu.h"
char PrintOptions()
{
	char output[MAXSIZE] = "Please choose an option: ";
	printf("please enter the choice of the option you want to select\n");
	printf("a.)Add a new Recipe\n");
	printf("b.)Delete an exitsing Recipe\n");
	printf("c.)Update an exitsing Recipe\n");
	printf("d.)Display a single recipe\n");
	printf("e.)Display a range of recipes\n");
	printf("f.)Display All recipes\n");
	printf("g.)Search for a recipe\n");
	printf("h.)Search for a random recipe\n");
	printf("i.)Exit the program\n");
	
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
		int continue_check = 0;
		StringInput(output_name, buffer_ingredent);
		StringInput(output_unit, buffer_unit);
		buffer_amount = float_Number_input(output_amount);
		temp_ingredent = CreateIngredent(buffer_ingredent, buffer_amount, buffer_unit);
		Addingredent(&functioningredentslist, temp_ingredent);
		do
		{
			menu_input = Char_input(output_end);
			if (menu_input == 'n' || menu_input == 'N')
			{
				ingredents_check = 1;
				continue_check = 1;
			}
			else if (menu_input == 'y' || menu_input == 'Y')
			{
				continue_check = 1;
				continue;
			}
			else
			{
				printf("please enter a valid input\n");
			}
		} while (continue_check == 0);
	} while (ingredents_check == 0);
	
	//temp_recipe = CreateRecipe(&ingredentslist);
	//Add(&recipelist, temp_recipe);
	//INGREDENTS ingredent = CreateIngredent("tumric", 5 , "kg");
	//Addingredent(&functioningredentslist, ingredent);
	//RECIPE recipe = CreateRecipe(&functioningredentslist);
	//Add(&funtcionrecipelist, recipe);
	
	return functioningredentslist;
}
PLISTOFSTEPSNODE Createanewstep()
{
	int steps_check = 0;
	PLISTOFSTEPSNODE functionstepslist = { 0 };
	char output_name[MAXSIZE] = "Please enter the steps title: ";
	char output_instruction[MAXSIZE] = "What do you do in that step: ";
	char output_end[MAXSIZE] = "Would you like to add a new Step ( Y | N ): ";
	char buffer_title[MAXSIZE];
	char buffer_instruction[MAXSIZE];
	STEP tempstep;
	char menu_input;
	do
	{
		int continue_check = 0;
		StringInput(output_name, buffer_title);
		StringInput(output_instruction, buffer_instruction);
		tempstep = Createstep(buffer_title, buffer_instruction);
		addstep(&functionstepslist, tempstep);
		do
		{
			menu_input = Char_input(output_end);
			if (menu_input == 'n' || menu_input == 'N')
			{
				steps_check = 1;
				continue_check = 1;
			}
			else if (menu_input == 'y' || menu_input == 'Y')
			{
				continue_check = 1;
				continue;
			}
			else
			{
				printf("Please enter a valid input\n");
			}
		} while (continue_check == 0);
	} while (steps_check == 0);

	//temp_recipe = CreateRecipe(&ingredentslist);
	//Add(&recipelist, temp_recipe);
	//INGREDENTS ingredent = CreateIngredent("tumric", 5 , "kg");
	//Addingredent(&functioningredentslist, ingredent);
	//RECIPE recipe = CreateRecipe(&functioningredentslist);
	//Add(&funtcionrecipelist, recipe);

	return functionstepslist;
}

PLISTNODE Createanewrecipe(PINGRDENTLISTNODE functioningredentslist, PLISTOFSTEPSNODE steps,  PLISTNODE functionrecipelist)
{
	RECIPE temp_recipe;
	char title_output[MAXSIZE] = "What would you like the title of the recipe to be: ";
	char title_input[MAXSIZE];
	int mealtype_loop_check = 0;
	char mealtype_output[MAXSIZE] = "Is the meal for breakfast(1): Lunch(2): or dinner(3): ";
	int mealtype_choice;
	do
	{
		//change difficulty to meal type (B, L, D, or snack)
		mealtype_choice = int_Number_input(mealtype_output);
		
		if (mealtype_choice > 3 || mealtype_choice <= 0)
		{
			printf("Please enter a valid choice\n");
		}
		else
		{
			mealtype_loop_check = 1;
		}
	} while (mealtype_loop_check == 0);
	mealtype_choice = mealtype_choice -1;
	StringInput(title_output, title_input);
	temp_recipe = CreateRecipe(functioningredentslist, steps,  title_input,mealtype_choice);
	Add(&functionrecipelist, temp_recipe);
	return functionrecipelist;
}




void DeleteArecipe(PLISTNODE* functionrecipelist)
{
	PLISTNODE recipelist = *functionrecipelist;
	RECIPE recipetodelete; 
	char delete_choice[MAXSIZE];
	char delete_output[MAXSIZE] = "What is the name of the recipe you would like to delete (Case matters): ";
	StringInput(delete_output, delete_choice);
	bool findrecipe_check = FindRecipe(functionrecipelist, delete_choice, &recipetodelete);
	if (!(findrecipe_check))
	{
		fprintf(stderr, "Couldnt find recipe\n");
		return;
	}
	
	bool removecheck = Remove(functionrecipelist, recipetodelete);
	if (!(removecheck))
	{
		fprintf(stderr, "ERROR FREEING MEMORY\n");
		exit(1);
	} 
	printf("Recipe Successful Deleted\n\n");
	return;
}

void DisplayARecipe(PLISTNODE recipelist)
{
	PLISTNODE r = recipelist;
	RECIPE recipetodisplay;
	char displaychoice[MAXSTRINGSIZE];
	char display_output[MAXSTRINGSIZE] = "What is the title of recipe you would like to display(case matters): ";
	StringInput(display_output, displaychoice);
	bool findrecipe_check = FindRecipe(r, displaychoice, &recipetodisplay);
	if (!(findrecipe_check))
	{
		fprintf(stderr, "Couldnt find recipe\n");
		return;
	}
	
	PrintRecipe(recipetodisplay);
	return;
}


void searchforarecipe(PLISTNODE recipelist)
{
	PLISTNODE r = recipelist;
	RECIPE recipetodisplay;
	char displaychoice[MAXSTRINGSIZE];
	char display_output[MAXSTRINGSIZE] = "What is the title of recipe you would like to find(case matters): ";
	StringInput(display_output, displaychoice);
	bool findrecipe_check = FindRecipe(r, displaychoice, &recipetodisplay);
	if (!(findrecipe_check))
	{
		fprintf(stderr, "Couldnt find recipe\n");
		return;
	}

	printf("FOUND!\n");
	return;
}

//Display range of recipes 

void DisplayRangeOfRecipe(PLISTNODE recipelist) {
	PLISTNODE r = recipelist;
	int starting = 0; 
	int ending = 0;
	bool rangeCheck = false;

	while (rangeCheck == false) {
		char starting_output[MAXSTRINGSIZE] = "What is the starting recipe number: ";
		starting = int_Number_input(starting_output);

		char ending_output[MAXSTRINGSIZE] = "What is the ending recipe number: ";
		ending = int_Number_input(ending_output);

		rangeCheck = true;

		if (starting > ending) {
			printf("Invalid Input, Please try again!\n");
			rangeCheck = false;
		}
	}

	int amount_of_recipes = getcurrentcount(r);
	

	if (ending > amount_of_recipes)
	{
		fprintf(stderr, "Requesting ending amount is larger then current amount of recipes\n");
		return;
	}
	if(starting > amount_of_recipes || starting == 0)
	{
		fprintf(stderr, "Starting value is greater then amount of recipes\n");
		return;
	}

	RecipeRangeDisplayer(starting, ending, recipelist);
	
}


void updatearecipe(PLISTNODE* recipelist)
{
	RECIPE recipetoupdate = { 0 };
	char updateoutput[MAXSTRINGSIZE] = "Please enter the title of the recipe you would like to update(Case matters): ";
	char updateinput[MAXSTRINGSIZE];
	StringInput(updateoutput, updateinput);
	bool findrecipecheck = FindRecipe(recipelist, updateinput, &recipetoupdate);
	if (findrecipecheck == false)
	{
		fprintf(stderr, "RECIPE NOT FOUND\n");
		return;
	}
	bool removecheck = Remove(recipelist, recipetoupdate);
	if (removecheck == false)
	{
		fprintf(stderr, "PROBLEM UPDATING RECIPE\n");
		return;
	}
	
	printf("Updating values, please enter the new values of the recipe\n");
	PINGRDENTLISTNODE updatedingredents = Createanewingredent();
	PLISTOFSTEPSNODE updatesteps = Createanewstep();
	*recipelist = Createanewrecipe(updatedingredents, updatesteps,  *recipelist);

	return;
}
