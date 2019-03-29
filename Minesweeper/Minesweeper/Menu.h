#pragma once
#include <windows.h>
#include <string.h>
#include <iostream>
#define SQUARE 177

class Menu
{
public:
	Menu();
	~Menu();
	int intmenu;
	void Start();
	void Rules();
	int Finish();
	void Unknown();
};