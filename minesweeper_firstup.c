#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <time.h>

//plan of the minesweeper's contruction
//not the finished code

int main(){
	while(1){
		//entering the game phase
		
		//resetting the values of the boxes
		char grid[6][6]={}, field[6][6]={};
		
		//initialization
		char m[2], tmpstr[10];
		int gridn[6][6] = {0};
		int i, j, k, l;
		int x, y, xs, ys;
		int mine = 0;
		int nof;
		int a = 0;
		
		//passing to menu function for the interface here
		//not done yet
		char menu;
		menu = .....
		
		system("cls");
		//constructing the minesweeper's game interface of 6x6 into some symbol in ascii code
		for(i = 0; i < 6; i++){
			for(j = 0; j < 6; j++){
				field[i][j] = 177;
			}
		}
		//making it beautiful by giving it some space
		//so that it doesn't look too awkward to see
		
		for(i = 0; i < 6; i++){
			//making it a little bit centered on the terminal
			for(j = 0; j < 30; j++){
				printf(" ");
			}
			
			//giving the space between each box as we
			//constructing the game interface
			for(j = 0; j < 6; j++){
				printf("%c   ", field[i][j]);
			}
			printf("\n\n");
		}
		
		//giving details on how to use the mode option
		//and starting the game by opening the first block of boxes
		
		printf("\n Open the starting square.\n");
		//scanning the coordinate of (x,y)
		//the value of (x,y) can't be more than 6 and less than 1
		//storing the (x,y) into (xs,ys)
		...
		...
		...
		
		while(1){
			//creating the mines after we trying to open the starting boxes
			//using the rand() function to get many cases of the game
			//limiting the mines to 9 only
			...
			...
			...
			if(mine == 9) break;
		}
		
		nof = mine;
		//creating the hints or boxes value to indicate
		//where the bombs are
		for(i = 0; i < 6; i++){
			for(j = 0; j< 6; j++){
				...
				...
				...
				...
				//since gridn's data type is int, so we need
				//to add 48 to make it numeric in ascii code
				grid[i][j] = gridn[i][j] + 48;
			}
		}
		
		//storing the boxes value after the attempt to open it
		...
		...
		
		while(1){
			// game mode
			...
			...
			...
		}
		
		//option to play the game again or exit
		int opt;
    	printf("Play again?\n1. Yes\n2. No\n");
    	scanf("%d", &opt);
    	if(opt==2) break;
	}
	return 0;
}
