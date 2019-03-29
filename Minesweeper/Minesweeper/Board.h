#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>

#define SQUARE 177;

class Board
{
public:
	Board();
	~Board();
	char grid[6][6], field[6][6];
	char m[2], tmpstr[10];
	int gridn[6][6] = { 0 };
	int i, j, k, l;
	int x, y, xs, ys;
	int mine = 0;
	int nof;
	int a = 0;

	void PrintFirstBoard();
	void FirstStep();
	int SpreadTheMine();
	void MakeHints();
	void MakeMap();

	void PrintBoard();
	void Details();
	int ChoiceCheck();
	void ChoiceGetter();
	void OpenSquare();
	void FlagSquare();
	void RemoveFlag();
	void RevealAllBombs();
};