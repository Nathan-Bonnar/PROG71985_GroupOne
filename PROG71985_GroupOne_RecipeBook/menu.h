#pragma once
//PROG71985 W24 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// menu interface
#include"ingredients.h"
#include"Steps.h"
#include"listofsteps.h"
#include"list.h"
#include"listofingredents.h"
#include"Recipe.h"
#include"User_Input.h"
char PrintOptions();

PINGRDENTLISTNODE Createanewingredent();

PLISTOFSTEPSNODE Createanewstep();

PLISTNODE Createanewrecipe(PINGRDENTLISTNODE functioningredentslist, PLISTOFSTEPSNODE steps, PLISTNODE functionrecipelist);

void DeleteArecipe(PLISTNODE* functionrecipelist);

void DisplayARecipe(PLISTNODE recipelist);

void searchforarecipe(PLISTNODE recipelist);

void DisplayRangeOfRecipe(PLISTNODE recipelist);

void updatearecipe(PLISTNODE* recipelist);