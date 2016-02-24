// labyrinth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAX = 100;

char labyrinth[MAX][MAX];
int n, m;

//Функция която чете лабиринт от стандартния вход
void readLabyrinth() 
{
	cin >> n >> m;
	cin.ignore();
	//работим със символни низове следователно можем да прочетем
	//цял ред с getline вместо да четем символ по символ
	for (int i = 0; i < n; i++)
	{
		cin.getline(labyrinth[i], m + 2);
	}
}

//Функция за извеждане на лабиринта на стандартния изход
void printLabyrinth() 
{
	//също както в предишната функция работим с низове
	//а не със самите символи поотделно
	for (int i = 0; i < n; i++)
	{
		cout << labyrinth[i] << endl;
	}
}

//Функция за намиране на индексите на ред и стълб на 
//началната позиция в лабиринта
void findStart(int& x, int& y) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (labyrinth[i][j] == 'o') 
			{
				x = i;
				y = j;
				return;
			}
		}
	}
}

//Това е допълнената функция за намиране на съкровището
//с дължина на пътя и отбелязването му по лабиринта
bool findTreasure(int x, int y, int move) 
{
	cout << "Опитваме позиция (" << x << "," << y << ")" << endl;

	if (x < 0 || y < 0 || x >= n || y >= m ||
		labyrinth[x][y] == '#' ||
		labyrinth[x][y] >= '0' && labyrinth[x][y] <= '9')
		//дъно на рекурсията при лош случай -  опитваме се
		//да излезем от лабринта, да стъпим на стена или
		//на вече обходено квадратче(предотвратява зацикляне)
		return false;

	if (labyrinth[x][y] == '$') 
	{
		//дъно на рекурсията при хубав случай - намерихме
		//съкровището 
		cout << "Намерихме съкровището на (" << x <<
			"," << y << ")!\n";
		cout << "Направихме " << move << " стъпки!\n";
		return true;
	}
	
	//маркираме обходеното квадратче - ако не ни интересува
	//как точно сме минали просто слагаме някакъв символ
	labyrinth[x][y] = '0' + (move % 10);

	//стъпка надолу
	if (findTreasure(x + 1, y, move + 1))
		return true;

	//стъпка наляво
	if (findTreasure(x, y - 1, move + 1))
		return true;

	//стъпка надясно
	if (findTreasure(x, y + 1, move + 1))
		return true;

	//стъпка нагоре
	if (findTreasure(x - 1, y, move + 1))
		return true;

	//отбелязваме задънени пътища, които не водят до
	//съкровището(само за образност не е задължително)
	labyrinth[x][y] = 'X';
	return false;
}

int countPaths = 0;

//Намиране на всички пътища до съкровището
//не се различава много от предишната
void findAllPathsToTreasure(int x, int y, int move) 
{
	cout << "Опитваме позиция (" << x << "," << y << ")" << endl;

	if (x < 0 || y < 0 || x >= n || y >= m ||
		labyrinth[x][y] == '#' ||
		labyrinth[x][y] >= '0' && labyrinth[x][y] <= '9')
		//същото както предишната функция
		return;

	if (labyrinth[x][y] == '$') 
	{
		//не правим return защото искаме всички пътища
		//вместо това извеждаме лабиринта и задържаме
		//програмата за да видим пътя
		cout << "Намерихме съкровището на (" << x <<
			"," << y << ")!\n";
		cout << "Направихме " << move << " стъпки!\n";
		printLabyrinth();
		cout << "Натиснете <ENTER> за още..." << endl;
		cin.get();
		countPaths++;
		return;
	}

	//също както предишната функция
	labyrinth[x][y] = '0' + (move % 10);

	//няма return функцията работи докато не я прекъснем
	//или не се намерят всички пътища до съкровището
	// стъпка надолу
	findAllPathsToTreasure(x + 1, y, move + 1);

	// стъпка наляво
	findAllPathsToTreasure(x, y - 1, move + 1);

	// стъпка надясно
	findAllPathsToTreasure(x, y + 1, move + 1);

	// стъпка нагоре
	findAllPathsToTreasure(x - 1, y, move + 1);

	//също както предишната функция
	labyrinth[x][y] = 'X';
}

//void findAllPathsToTreasure(int, int);
//void multiplyNumbers(int, int);
//void printNumbersFromTo(int, int);

void findAllPathsToTreasure(int startx, int starty) 
{
	findAllPathsToTreasure(startx, starty, 0);
}

int main() 
{
	cout << "dali е език или не";
	readLabyrinth();
	//printLabyrinth();
	int startx, starty;
	findStart(startx, starty);
	cout << "Започваме от " << "("
		<< startx << "," << starty << ")\n";
	// cout << findTreasure(startx, starty, 0) << endl;
	// printLabyrinth();
	findAllPathsToTreasure(startx, starty);
	cout << "Намерени " << countPaths << " пътя" << endl;

	return 0;
}	
/*
6 6
o_____
_####_
_#____
_#_###
_#___#
___#_$
*/


