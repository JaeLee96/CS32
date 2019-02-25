#ifndef PAST_H_
#define PAST_H_
#include "globals.h"
#include "Player.h"

class Arena;

class Past
{
public:
	Past(int nRows, int nCols);
	bool markIt(int r, int c);
	void printThePast() const;
private:
	int nrow;
	int ncol;
	char letter;
	char grid[MAXROWS][MAXCOLS];
};

#endif // !PAST_H_
