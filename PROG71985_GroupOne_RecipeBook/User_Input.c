//PROG71985 W24 Nathan Bonnar - Carter Blackie - Nicholas Rojas 
//Make a recipe Book
//User Input Interface
//Grabs different types of user input 
#define _CRT_SECURE_NO_WARNINGS 
#include"User_Input.h"
float float_Number_input(char* outputstring)
{
	float number_input;
	int numbervalid_check = 0;
	do
	{
		printf("%s", outputstring);
		int number_check = scanf("%f", &number_input);

		if (number_check != 1)
		{
			printf("Please enter a vaild input\n");
			int checker = getchar() != '\n';
		}
		else
		{
			numbervalid_check++;
		}
	
	} while (numbervalid_check == 0);
	int checker = getchar() != '\n';
	return number_input;

}


int int_Number_input(char* outputstring)
{
	int number_input;
	printf("%s", outputstring);
	int number_check = scanf("%d", &number_input);

	if (number_check != 1)
	{
		printf("Please enter a vaild input\n");
		exit(EXIT_FAILURE);
	}
	if (number_input > MAXSIZE)
	{
		printf("Please enter a valid input");
		exit(EXIT_FAILURE);
	}
	int checker = getchar() != '\n';
	return number_input;

}



char Char_input(char* outputstring)
{
	char char_input;
	printf("%s", outputstring);

	scanf(" %c", &char_input);
	while (getchar() != '\n'); // Clear the input buffer

	// Check if the input is a letter
	if ((char_input >= 'a' && char_input <= 'z') || (char_input >= 'A' && char_input <= 'Z')) {

	}
	else {
		printf("Please enter a valid input\n");
		exit(EXIT_FAILURE);
	}
	return char_input;
}




bool StringInput(char* output_string, char* input_string)
{
	char buffer[MAXSIZE] = { 0 };

	printf("%s", output_string);

	fgets(buffer, MAXSIZE, stdin);
	
	buffer[strcspn(buffer, "\n")] = '\0';
	
	int lengthofstring = (int)strlen(buffer);

	for (int loop = 0; loop< lengthofstring; loop++)
	{
		if (isalpha(buffer[loop]) == 0)
		{
			if (buffer[loop] == ' ')
			{
				continue;
			}
			return false;
		}
	}
	
	strncpy(input_string, buffer, MAXSIZE);
	return true;
}
