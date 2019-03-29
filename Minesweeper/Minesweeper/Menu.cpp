#include "pch.h"
#include "Menu.h"

using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
	system("CLS");
	printf("\t\t\t\t\t\t\tMinesweeper 6x6\n\n");
	printf("\t\t\t\t\t\t1.Play Minesweeper\n\t\t\t\t\t\t2.Rules\n");
	scanf_s("%d", &intmenu);
}

void Menu::Rules()
{
	system("cls");
	printf("This is the classic game of minesweeper written in C.\n\nRules for minesweeper:\n");
	printf("1. You are in a mine field and you have to successfully flag all the places which have a mine(%c). If you flag all the mines, You win!\n", 42);
	printf("2.In your first turn, you have to choose a starting square. You can open a square by entering its column number(x) and row number(y)\n(Note: row and column number starts from 1)\n");
	printf("3.There are three modes of operation:\n");
	printf("\t(i) open mode. type 'o' in mode option. This mode lets the user to open a square\n");
	printf("\t(ii) flag mode. type 'f' in mode option. This mode lets the user to flag a particular square. Flagged square is denoted by an 'F'\n");
	printf("\t(iii) remove flag mode. type 'r' in mode option. This mode lets the user to remove a particular flag from a flagged square\n");
	printf("4.If you open a square with a mine, you lose\n");
	printf("5.If you open a square with a number written on it. The number shows that how many mines are there in the adjacent 8 squares\n");
	printf("\nFor eg:\n%c  %c  %c\n\n%c  4  %c\n\n%c  %c  %c", SQUARE, SQUARE, SQUARE, SQUARE, SQUARE, SQUARE, SQUARE, SQUARE);
	printf("\nHere 4 denoted that there are 4 mines in the remaining uncovered squares\n");
	system("PAUSE");
}

int Menu::Finish()
{
	int opt;
	printf("Play again?\n1. Yes\n2. No\n");
	scanf_s("%d", &opt);
	if (opt == 1) { return 0; }
	else if (opt == 2) { return 1; }
}

void Menu::Unknown()
{
	printf("Sorry, unknown command\nPlease try again\n");
	Sleep(2500);
}