// Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Menu.h"
#include "Board.h"
#include <iostream>

using namespace std;

int main()
{
	while (1)
	{
		//std::cout << "Hello World!\n";
		Menu ui;
		ui.Start();
		if (ui.intmenu == 1)
		{
			printf("Mainnnn\n");
			Board minefield;
			minefield.PrintFirstBoard();
			minefield.FirstStep();
			while (1)
			{
				if(minefield.SpreadTheMine()) break;
			}
			minefield.MakeHints();
			minefield.MakeMap();
			while (1)
			{
				minefield.PrintBoard();
				OutputDebugString(L"Masuk\n");
				minefield.Details();
				OutputDebugString(L"Masuk2\n");
				if(minefield.ChoiceCheck()==1) break;
				OutputDebugString(L"Masuk3\n");
				minefield.ChoiceGetter();
				OutputDebugString(L"Masuk4\n");
				if (strcmp(minefield.m, "o") == 0) minefield.OpenSquare();
				else if (strcmp(minefield.m, "f") == 0) minefield.FlagSquare();
				else if (strcmp(minefield.m, "r") == 0) minefield.RemoveFlag();
				OutputDebugString(L"Masuk5\n");
				minefield.RevealAllBombs();
				OutputDebugString(L"Masuk6\n");
			}
			if (ui.Finish()) break;
		}
		if (ui.intmenu == 2)
		{
			ui.Rules();
		}
		if (ui.intmenu == 3)
		{
			break;
		}
//		else
//		{
//			ui.Unknown();
//			system("cls");
//			ui.Start();
//		}
		//system("Pause");
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
