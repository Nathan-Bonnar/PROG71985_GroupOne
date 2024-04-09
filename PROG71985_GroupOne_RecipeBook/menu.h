#pragma once
//PROG71985 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
// menu interface
#include"ingredients.h"
#include"list.h"
#include"listofingredents.h"
#include"Recipe.h"
#include"User_Input.h"
char PrintOptions();

PINGRDENTLISTNODE Createanewingredent();

PLISTNODE Createanewrecipe(PINGRDENTLISTNODE functioningredentslist, PLISTNODE functionrecipelist);

void DeleteArecipe(PLISTNODE* functionrecipelist);

void DisplayARecipe(PLISTNODE recipelist);