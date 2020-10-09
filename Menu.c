#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
/*
Compiler notes
cd ~/c/Users/lkri/source/repos/ANSICMenu
gcc -o menu Menu.c -lncurses
./menu

https://courses.cs.washington.edu/courses/cse451/99wi/Section/gccintro.html
https://matt.sh/howto-c
*/

//Global varialbles
int menuControl = 0; //controls highlight in menu
bool loopControl = true; //Controls while loop of program
int color = 31; //sets color of highlighted text. 31 = red ; 32 = green ; 33 = yellow ; 34 = blue ; 35 = Magenta ; 36 = cyan.
char *menuOptions[] = { //contains the menu options
	"Menu",
	"List",
	"Unit Test",
	"Init",
	"Exit",
};
int n_options = sizeof(menuOptions) / sizeof(char *); // contain size of menu options

/*
 * PrintMenu 
 * Prints out menuOptions and hightlights based on menuControl.
*/
void PrintMenu (void) {
	system("clear");
	
	if (menuControl < 0) {
		menuControl = 0;
	}
	if (menuControl > n_options-1) {
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
 * MenuControl 
 * Calls PrintMenu and then controls the program flow based on menuControl.
*/
void MenuControl (void) {
	PrintMenu();
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
			
		case 4: // "Exit"
			printf("Menu Option: %s\n", menuOptions[menuControl]);
			loopControl = false;
			break;
	}
}

/*
 * Main
 * Contain a switch case that controls menu based on console input.
*/
int main(void) {
	char c;
	MenuControl();
		
	while (loopControl) {
		printf("\033[0m");
		
		c = getchar();
		
		switch(c){
			case 'w':
				--menuControl;
				MenuControl();
				break;
			
			case 's':
				++menuControl;
				MenuControl();
				break;
				
			case 'e':
				printf("exit\n");
				loopControl = false;
				break;
		}
	}
}

