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
		char grid[6][6], field[6][6];
		
		//initialization
		char m[2], tmpstr[10];
		int gridn[6][6] = {0};
		int i, j, k, l;
		int x, y, xs, ys;
		int xf, yf;
		int mine = 0;
		int nof;
		int a = 0;
		
		//passing to menu function for the interface
		char menu;
		for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			grid[i][j] = 0;
		}
		}
		printf("\t\t\t\t\t\t\tMinesweeper 6x6\n\n");
        printf("\t\t\t\t\t\t1.Play Minesweeper\n\t\t\t\t\t\t2.Rules\n");
        scanf("%c",&menu);
		if(menu == 50){
			system("cls");
            printf("This is the classic game of minesweeper written in C.\n\nRules for minesweeper:\n");
            printf("1. You are in a mine field and you have to successfully flag all the places which have a mine(%c). If you flag all the mines, You win!\n",42);
            printf("2.In your first turn, you have to choose a starting square. You can open a square by entering its row number(x) and column number(y)\n(Note: row and column number starts from 1)\n");
            printf("3.There are three modes of operation:\n");
            printf("\t(i) open mode. type 'o' in mode option. This mode lets the user to open a square\n");
            printf("\t(ii) flag mode. type 'f' in mode option. This mode lets the user to flag a particular square. Flagged square is denoted by an 'F'\n");
            printf("\t(iii) remove flag mode. type 'r' in mode option. This mode lets the user to remove a particular flag from a flagged square\n");
            printf("4.If you open a square with a mine, you lose\n");
            printf("5.If you open a square with a number written on it. The number shows that how many mines are there in the adjacent 8 squares\n");
            printf("\nFor eg:\n%c  %c  %c\n\n%c  4  %c\n\n%c  %c  %c",177,177,177,177,177,177,177,177);
            printf("\nHere 4 denoted that there are 4 mines in the remaining uncovered squares");
            printf("\n\nPress enter to continue.....");
            fflush(stdin);
            gets(tmpstr);
		}
		
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
		
		//int starting;
		//starting:
		for(;;){
		printf("\n Open the starting square.\n");
		//scanning the coordinate of (x,y)
		//the value of (x,y) can't be more than 6 and less than 1
		//storing the (x,y) into (xs,ys)
		printf("x: ");
		scanf("%d", &xs);
    	printf("y: ");
    	scanf("%d", &ys);
    	//printf("%d""%d",xs,ys);
		if(xs>6 || ys>6 || xs<1 || ys<1){
			printf("Row or column not defined. Try again\n"); continue;
		}
		else break;
	}
		xf = xs;
		yf = ys;
		
		xs = xs-1;
		ys = ys-1;
		srand(time(NULL));
		while(1){
			//creating the mines after we trying to open the starting boxes
			//using the rand() function to get many cases of the game
			//limiting the mines to 9 only
			i=rand()%6;
        	j=rand()%6;
        	if(grid[i][j]!=42 && i!=xs && j!=ys) grid[i][j]=42;
        	else continue;
        	mine++;
			if(mine == 9) break;
		}
		
		nof = mine;
		//creating the hints or boxes value to indicate
		//where the bombs are
		for(i = 0; i < 6; i++){
			for(j = 0; j< 6; j++){
				if(grid[i][j] != 42){
					for(k = i-1; k <= i+1; k++){
						for(l = j-1; l <= j+1; l++){
							//make sure that the k and l values fixed in 0-5
							//counting the sum of mines nearby
							if(grid[k][l] == 42 && k >= 0 && l >= 0 && k <=5 && l <= 5)
								gridn[i][j]++;
						}
					}
					//since gridn's data type is int, so we need
					//to add 48 to make it numeric in ascii code
					grid[i][j] = gridn[i][j] + 48;
				}
			}
		}
		
//		printf("xs: %d  ys: %d\n", xs, ys);
		//storing the hints value as the bombs stored with * symbol in ascii
		for(i = xs-1; i <= xs+1; i++)
    	{
        	for(j = ys-1; j <= ys+1; j++)
        	{
            	if(grid[i][j] != 42){
            		if(yf == 1 && j == -1) continue;
            		else if(yf == 6 && j == 6) continue;
            		field[i][j] = grid[i][j];
            		if(field[i][j] == 48){
            			field[i-1][j] = grid[i-1][j];
            			field[i+1][j] = grid[i+1][j];
            			field[i][j+1] = grid[i][j+1];
            			field[i][j-1] = grid[i][j-1];
						field[i-1][j+1] = grid[i-1][j+1];
						field[i-1][j-1] = grid[i-1][j-1];
						field[i+1][j+1] = grid[i+1][j+1];
						field[i+1][j-1] = grid[i+1][j-1];
					}
//            		printf("i: %d j: %d value: %c\n", i, j, field[i][j]);
            		
				}
        	}
    	}
    	
    	x=xs;
    	y=ys;
		
		//starting the game as the starting square opened
		while(1){
			
			//revealing the opened starting square on the first iteration.
			//on the next iteration, revealing the player's choices,
			//whether to open or flag the squares.
			//if a bomb is opened in the previous iteration,
			//revealing all the bombs location.
			system("cls");
	        for(i = 0; i < 6; i++)
	        {
	            for(j = 0; j < 30; j++)
	                printf(" ");
	            for(j = 0; j < 6; j++)
	                printf("%c   ", field[i][j]);
	            printf("\n\n");
	        }
	        
	        //giving hints for the leftover flags
	        //and providing details on game modes
	        printf("Number of leftover flags: %d\n", nof);
	        printf("Game mode:\n");
			printf("\t'o' for opening a square.\n\t'f' for flaging a square.\n\t'r' for removing square's flag.\n'");
	        
	        //if the square is a bomb
	        if(grid[x][y] == 42 && strcmp(m, "o") == 0)
	        {
	        	printf("\n\t\t\t\t\tYou opened a bomb!");
	            printf("\n\t\t\t\t\t\tGAME OVER\n");
	            break;
	        }
	        
	        //checking if the player flagging the right squares with bombs
	        for(i = 0; i < 6; i++)
	        {
	            for(j = 0; j < 6; j++)
	            {
	                if(grid[i][j] == 42 && field[i][j] == 70)
	                    a++;
	            }
	        }
	        
	        //win if all the bombs are flagged
	        if(a == mine)
	        {
	            printf("You win\n");
	            break;
	        }
	        
	        //scanning player's choices
	        a = 0;
	        printf("Mode chosen: ");
	        scanf("%s", &m);
	        printf("x: ");
        	scanf("%d",&x);
        	printf("y: ");
        	scanf("%d",&y);
	        x = x-1;
	        y = y-1;
	        printf("%d\n", field[x][y]);
	        //if player chose to open the square, passing the hint
			//stored in grid array into the field array
	        if(strcmp(m, "o") == 0) field[x][y] = grid[x][y];
	        
	        //if player chose to flag the square, change the field array value into F.
	        //reminder that the square must be not a flagged square
	        else if(strcmp(m, "f") == 0 && field[x][y] != 70 && field[x][y] == -79){
				field[x][y] = 70;
	            nof--;
			}
			
			//if the player chose to remove the flag, change the field array value into symbol.
	        else if(strcmp(m, "r") == 0 && field[x][y] == 70){
	            field[x][y] = 177;
	            nof++;
	        }
	        
	        //if the player chose to open the square but it's a bomb
	        //passing the bombs's location into field array so that
	        //we can display it on the next iteration.
	        if(grid[x][y] == 42 && strcmp(m, "o") == 0)
	        {
	            for(i = 0; i < 6; i++)
	            {
	                for(j = 0; j < 6; j++)
	                {
	                    if(grid[i][j] == 42)
	                        field[i][j] = grid[i][j];
	                }
	            }
	        }
		}
		
		//option to play the game again or exit
		int opt;
    	printf("Play again?\n1. Yes\n2. No\n");
    	scanf("%d", &opt);
    	if(opt==2) break;
	}
	return 0;
}
