// PuzzleSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// https://en.wikipedia.org/wiki/Nurikabe_(puzzle)



// Test how I will setup my multidimensional array

#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>   // for TimerCode ~ ostringstream variable
#include "Windows.h" // for TimerCode ~ LARGE_INTEGER and QueryPerformanceCounter(&li);

#include "Grid.h"
#include "Coordinate2D.h"
#include "Cell.h"

enum class SolveStatus
{
	KEEP_GOING,
	CONTRADICTION_FOUND,
	SOLUTION_FOUND
};

using namespace std;


int Width = 10;
int Height = 9;

// TODO: Filter into function
vector<pair<Coordinate2D, int> > NumberedIslandCells
{
	make_pair(Coordinate2D(0, 0), 2),
	make_pair(Coordinate2D(0, 6), 2),
	make_pair(Coordinate2D(1, 2), 2),
	make_pair(Coordinate2D(1, 8), 1),
	make_pair(Coordinate2D(2, 5), 2),
	make_pair(Coordinate2D(3, 6), 4),
	make_pair(Coordinate2D(4, 2), 7),
	make_pair(Coordinate2D(6, 1), 2),
	make_pair(Coordinate2D(6, 4), 3),
	make_pair(Coordinate2D(6, 8), 2),
	make_pair(Coordinate2D(7, 5), 3),
	make_pair(Coordinate2D(8, 4), 3),
	make_pair(Coordinate2D(8, 8), 4),
	make_pair(Coordinate2D(9, 0), 2)
};


// TODO: Get the code timer working for the solving code in main().

long long counter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return li.QuadPart;
}

long long frequency() 
{
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	return li.QuadPart;
}

string format_time(const long long start, const long long finish)
{
	ostringstream oss;

	if ((finish - start) * 1000 < frequency())
	{
		oss << (finish - start) * 1000000.0 / frequency() << " microseconds";
	}
	else if (finish - start < frequency())
	{
		oss << (finish - start) * 1000.0 / frequency() << " milliseconds";
	}
	else
	{
		oss << (finish - start) * 1.0 / frequency() << " seconds";
	}

	return oss.str();
}


int main()
{
	// Create our Grid and correctly initalize it.
	Grid GameBoard(Width, Height, NumberedIslandCells);
	
	GameBoard.PrintGrid(); 

	try
	{
		// we don't care how long it took to create our grid so we won't time it.
		const long long start = counter();
		// TODO: Make logic for solving something like 
		// while (GameBoard.SolvePuzzle == Something..) so we can time how long it takes to solve, 
		// Most likely we need a loop because to solve these puzzles means repeating some of the solving steps multiple times.
		// It will know when it needs to stop when all cells are known(not unknown probably) 
		// - so we will probably need a tracker variable for that, which shouldn't be that hard to put in.
		//auto CurrentRes = GameBoard.SolvePuzzle();

		while (GameBoard.SolvePuzzle() == SolveStatus::KEEP_GOING) {}
		//while (CurrentRes == SolveStatus::KEEP_GOING)
		//{
		//	CurrentRes = GameBoard.SolvePuzzle();
		//}
		const long long finish = counter();

		// Print how long it took to solve the puzzle
		cout << "Puzzle Solve Time: " << ": " << format_time(start, finish) << ", " << endl << endl;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	//	A function that checks if its still possible for all black cells to still be connected.
	//		- iterate over all black cells, check all of its neighbors and make sure there is at least 1 unknown or 1 black cell 
	//		  in its valid neighbors, this function should always return true, if it returns false...idk
	//	A function that checks if there is an unknown cell that needs to be black to connect 2 black squares(that are diagional ? )
	//		A function that marks an unknown cell white, then iterates over all of its valid neighbors passing a lambda,
	//		- if the neighbor is a black cell, iterate over all of that cells neighbors and see if its possible to connect to 
	//			another black

	GameBoard.PrintGrid(); 






	// This is debug code.. can be removed later.
	// TODO: This Debug Code should be more clear.  (50% done, still hard to read)
	// - Are these regions white black etc.... 
	// - Where are they, takes a long time to look for them using the coordinates.

	//cout << endl;
	//GameBoard.PrintAllCellsInAllRegions(); // Working
	//cout << endl;

	//cout << endl;
	//GameBoard.PrintAllUnknownsInAllRegions();
	//cout << endl;

	return 0;
}