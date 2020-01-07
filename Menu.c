#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <curses.h>
/*
Compiler notes
gcc -o menu Menu.c -lncurses
./menu
*/

//Global varialble
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
void PrintMenu () {
	system("clear");
	
	if (menuControl < 0) {
		menuControl = 0;
	}
	
	for (int i = 0; i < n_options; ++i) {
		if (menuControl == i) {
			printf("\033[1;%dm", color);
			printf("%s\n", menuOptions[i]);
			
			if (menuOptions[i] == "Exit") {
			loopControl = false;
			}
		} else {
			printf("\033[0m");
			printf("%s\n", menuOptions[i]);
		}
	}
}

/*
 * Main
 * Contain a switch case that controls menu based on console input.
*/
int main() {
	char c;
		
	while (loopControl) {
		printf("\033[0m");
		c = getchar();
		
		switch(c){
			case 'w':
				--menuControl;
				PrintMenu();
				break;
			
			case 's':
				++menuControl;
				PrintMenu(1);
				break;
				
			case 'e':
				printf("exit");
				loopControl = false;
				break;
		}
	}
}

