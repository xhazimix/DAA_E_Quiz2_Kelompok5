#include "pch.h"
#include "Board.h"

using namespace std;

Board::Board()
{
	//Initialising map
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			grid[i][j] = 0;
		}
	}
	
	//Burying the mines
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			field[i][j] = SQUARE;
		}
	}
}

Board::~Board()
{
}

void Board::PrintFirstBoard()
{
	system("CLS");
	//making it beautiful by giving it some space
	//so that it doesn't look too awkward to see
	for (i = 0; i < 6; i++) {
		//making it a little bit centered on the terminal
		for (j = 0; j < 30; j++) {
			printf(" ");
		}

		//giving the space between each box as we
		//constructing the game interface
		for (j = 0; j < 6; j++) {
			printf("%c   ", field[i][j]);
		}
		printf("\n\n");
	}
}

void Board::FirstStep()
{
	for (;;)	//equivalent to while(true)
	{
		printf("\n Open the starting square.\n");
		//scanning the coordinate of (x,y)
		//the value of (x,y) can't be more than 6 and less than 1
		//storing the (x,y) into (xs,ys)
		printf("x: ");
		scanf_s("%d", &ys);
		printf("y: ");
		scanf_s("%d", &xs);
		//printf("%d""%d",xs,ys);
		if (xs > 6 || ys > 6 || xs < 1 || ys < 1) {
			printf("Row or column not defined. Try again\n"); continue;
		}
		else break;
	}
	
	//storing xs,ys initial value to help revealing
	//the starting boxes on MakeMap()
	xf = xs;
	yf = ys;
	
	xs = xs - 1;
	ys = ys - 1;
	srand(time(NULL));
}

int Board::SpreadTheMine()
{
	while (1) {
		//creating the mines after we trying to open the starting boxes
		//using the rand() function to get many cases of the game
		//limiting the mines to 9 only
		i = rand() % 6;
		j = rand() % 6;
		if (grid[i][j] != 42 && i != xs && j != ys) grid[i][j] = 42;
		else continue;
		mine++;
		if (mine == 9) return 1;
	}
}

void Board::MakeHints()
{
	nof = mine;
	//creating the hints or boxes value to indicate
	//where the bombs are
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (grid[i][j] != 42) {
				for (k = i - 1; k <= i + 1; k++) {
					for (l = j - 1; l <= j + 1; l++) {
						//make sure that the k and l values fixed in 0-5
						//counting the sum of mines nearby
						if (grid[k][l] == 42 && k >= 0 && l >= 0 && k <= 5 && l <= 5)
							gridn[i][j]++;
					}
				}
				//since gridn's data type is int, so we need
				//to add 48 to make it numeric in ascii code
				grid[i][j] = gridn[i][j] + 48;
			}
		}
	}
}

void Board::MakeMap()
{
	//storing the hints value as the bombs stored with * symbol in ascii
	//adding the condition when there's a 0 value on the revealed squares,
	//passing its neighbouring's value to be revelead too
	for (i = xs - 1; i <= xs + 1; i++)
	{
		for (j = ys - 1; j <= ys + 1; j++)
		{
			if(grid[i][j] != 42){
            			if(yf == 1 && j == -1) continue;
            			else if(yf == 6 && j == 6) continue;
            			field[i][j] = grid[i][j];
				//if the box's value is 0, then passing
				//its neighbouring's value to char field
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
			}
		}
	}

	x = xs;
	y = ys;
}

void Board::PrintBoard()
{
	//revealing the opened starting square on the first iteration.
			//on the next iteration, revealing the player's choices,
			//whether to open or flag the squares.
			//if a bomb is opened in the previous iteration,
			//revealing all the bombs location.
	system("cls");
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 30; j++)
			printf(" ");
		for (j = 0; j < 6; j++)
			printf("%c   ", field[i][j]);
		printf("\n\n");
	}
}

void Board::Details()
{
	//giving hints for the leftover flags
			//and providing details on game modes
	printf("Number of leftover flags: %d\n", nof);
	printf("Game mode:\n");
	printf("\t'o' for opening a square.\n\t'f' for flaging a square.\n\t'r' for removing square's flag.\n'");
}

int Board::ChoiceCheck()
{
	//if the square is a bomb
	if (grid[x][y] == 42 && strcmp(m, "o") == 0)
	{
		printf("\n\t\t\t\t\tYou opened a bomb!");
		printf("\n\t\t\t\t\t\tGAME OVER\n");
		return 1;
	}

	//checking if the player flagging the right squares with bombs
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (grid[i][j] == 42 && field[i][j] == 70)
				a++;
		}
	}

	//win if all the bombs are flagged
	if (a == mine)
	{
		printf("You win\n");
		return 1;
	}
}

void Board::ChoiceGetter()
{
	//scanning player's choices
	a = 0;
	printf("Mode chosen: ");
	cin >> m;
	//cin.ignore(2, '\n'); //fflush(stdin);
	printf("x: ");
	scanf_s("%d", &y);
	printf("y: ");
	scanf_s("%d", &x);
	x = x - 1;
	y = y - 1;
	printf("%d\n", field[x][y]);
}

void Board::OpenSquare()
{
	//if player chose to open the square, passing the hint
	//stored in grid array into the field array
	field[x][y] = grid[x][y];
}

void Board::FlagSquare()
{
	//if player chose to flag the square, change the field array value into F.
	//reminder that the square must be not a flagged square
	if(field[x][y] != 70 && field[x][y] == -79)
	{
		field[x][y] = 70;
		nof--;
	}
}

void Board::RemoveFlag()
{
	//if the player chose to remove the flag, change the field array value into symbol.
	if (field[x][y] == 70)
	{
		field[x][y] = SQUARE;
		nof++;
	}
}

void Board::RevealAllBombs()
{
	//if the player chose to open the square but it's a bomb
	//passing the bombs's location into field array so that
	//we can display it on the next iteration.
	if (grid[x][y] == 42 && strcmp(m, "o") == 0)
	{
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 6; j++)
			{
				if (grid[i][j] == 42)
					field[i][j] = grid[i][j];
			}
		}
	}
}
