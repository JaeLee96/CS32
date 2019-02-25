#include <iostream>
#include "Past.h"
#include "globals.h"
using namespace std;

Past::Past(int nRows, int nCols) : nrow(nRows), ncol(nCols)
{

	for (int r = 0; r < nrow; r++) {
		for (int c = 0; c < ncol; c++)
			grid[r][c] = '.';
	}
}

bool Past::markIt(int r, int c)
{
	if (r < 1 || r > MAXROWS || c < 1 || c > MAXCOLS) // Check if out of bounds
		return false;

	char& gridChar = grid[r-1][c-1];

	switch (gridChar)
	{
	case '.': gridChar = 'A'; break;
	case 'Z': break;
	default: gridChar++; break;
	}
}

void Past::printThePast() const
{
	clearScreen();

	for (int r = 0; r < nrow; r++) {
		for (int c = 0; c < ncol; c++)
			cout << grid[r][c];
		cout << endl;
	}
}
