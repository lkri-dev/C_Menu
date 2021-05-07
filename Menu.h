#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
#include "keypress.h"

/*
Author: lkri-dev 
Source: https://github.com/lkri-dev/ANSICMenu

Compiler notes
gcc -o menu Menu.c -lncurses && ./menu

Helpfull links:
	curses.h:
	https://courses.cs.washington.edu/courses/cse451/99wi/Section/gccintro.html

	https://matt.sh/howto-c
*/

//Global varialbles
int menuControl = 0; //controls highlighted option in menu
bool loopControl = true; //Controls while loop of program
/*
* contains the menu options 
* 32 = green ; 33 = yellow ; 34 = blue ; 35 = Magenta ; 36 = cyan.
* To add or remove options in menu 2 edit are needed.
* First; the title need to be added or removed to the pointer char array.
* Second; a case need to be added or removed a case in Menu_option_choice.
*/
char *menuOptions[] = { 
	"Menu",
	"List",
	"Unit Test",
	"Init",
	"Exit",
};
int const n_options = sizeof(menuOptions) / sizeof(char *); // contain size of menu options
/*
 * MenuControl 
 * Calls PrintMenu and then controls the program flow based on menuControl.
*/
void Menu_option_choice (void) {
	switch (menuControl) {
		case 0: // "Menu"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			break;
		
		case 1: // "List"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			break;
		
		case 2: // "Unit Test"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			break;
			
		case 3: // "Init"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			break;
			
		case sizeof(menuOptions) / sizeof(char *) - 1: // "Exit"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			loopControl = false;
			break;
	}
}
/*
 * PrintMenu 
 * Prints out menuOptions and hightlights based on menuControl.
*/
void PrintMenu (int color) {
	system("clear");
	
	if (menuControl < 0) {
		menuControl = 0;
	}
	else if (menuControl > n_options-1) {
		menuControl = n_options-1;
	}
	
	for (int i = 0; i < n_options; ++i) {
		if (menuControl == i) {
			printf("\033[1;%dm", color);
			printf("%s\n", menuOptions[i]);
			
		} else {
			printf("\033[0m");
			printf("%s\n", menuOptions[i]);
		}
	}
}
/*
 * Main
 * Contain a switch case that controls menu based on keypress input.
*/
void main_menu_loop (void) {
	printf("Press 'w' and 's' or arrow up and down to navigate the menu.\n");
	printf("Press 'e' to exit.\n");
	printf("Press enter to select the red option.\n\n");
	printf("Press any key to continue.\n");
	keypress(0);
	
	int color = 31; //sets color of highlighted text. 31 = red ;
	int hit;
	
	PrintMenu(color);
	
	while (loopControl) {
		printf("\033[0m");
		
		hit = keypress(0);
		
 
		if (hit != 0)
		{
			switch(hit){
				case 65:
				case 119: //w or 65
					--menuControl;
					PrintMenu(color);
					break;
				
				case 66:
				case 115: //s or 66 
					++menuControl;
					PrintMenu(color);
					break;
				
				case 10: //enter
					Menu_option_choice();
					break;
					
				case 101: //e
					printf("exit\n");
					loopControl = false;
					break;
			}
		}
	}
}
