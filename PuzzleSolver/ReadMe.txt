========================================================================
    CONSOLE APPLICATION : PuzzleSolver Project Overview
========================================================================


// Puzzle Solver for Nurikabe 
/* https://en.wikipedia.org/wiki/Nurikabe_(puzzle) */

// http://homepages.e3.net.nz/~djm/cppcontainers.html
// Container picker including unordered_ options
// https://i.stack.imgur.com/G70oT.png 

// http://homepages.e3.net.nz/~djm/cppiterators.html
// http://homepages.e3.net.nz/~djm/cppstrings.html


// TODO: Move the TODO: notes around the program into the list here.

// TODO: Study the constructor code that uses push_back on entire vectors of unique_ptrs and study how it is adding rows/columns 
// TODO: Get a better system for printing the board working.


// Step 1: Define the problem (I want a better way to keep track of my friends� phone numbers.)

// I want to make a solver for nurikabe puzzles.




// Step 2: Collect requirements For example:
// (Phone numbers should be saved, so they can be recalled later)

// Our program should be able to dectect if we gave it an invalid puzzle as input
// Once we have given our unsolved puzzle as input, we shouldn't need any other user input to solve the puzzle.
// Our program needs to have a system where it "tests" the result of marking cells
// - (Marking unknown cells white may force other cells to be black and vice versa(unknown to black test also), 
// - (because a section of black would be isolated when they need to connect))
// No blind guessing should be required 
// Our program needs to output how long it took to solve a puzzle.
// Our Program should output to cout what our board looks like before it was solved and after it was solved.




// Step 3: Define your tools, targets, and backup plan
// (Defining your testing/feedback/release strategy)
// (Determining how you will back up your code)

// Plan to write the code and test it going task by task.
// No backup storage plan yet.




// Step 4: Break hard problems down into easy problems

// Example:
// We want to ~ 
// Write report on carrots

// Write report on carrots
//	- Do research on carrots
//  - Write outline
//  - Fill in outline with detailed information about carrots
//  - Add table of contents

// Write report on carrots
//  - Do research on carrots
//     - Go to library and get book on carrots
//     - Look for information about carrots on internet
//     - Take notes on relevant sections from reference material
//  - Write outline
//     - Information about growing
//     - Information about processing
//     - information about nutrition


// Example 2 List Outline
/* 
Solving the problem:

(get from bed to work)

Make a list of the things you do in the morning going from bed to work.

Pick out clothes
Get dressed
Eat breakfast
Drive to work
Brush your teeth
Get out of bed
Prepare breakfast
Get in your car
Take a shower

Organize it into a hierarchy like so

Get from bed to work
	Bedroom things
		Get out of bed
		Pick out clothes
		Get dressed
	Bathroom things
		Take a shower
		Brush your teeth
	Breakfast things
		Prepare breakfast
		Eat breakfast
	Transportation things
		Get in your car
		Drive to work

*/


//	Solve A NuriKabe Puzzle
//	What are some things I need to do to solve a nurikabe puzzle

//	Make sure there is only one numbered cell in an island (set of connected white cells)
//	Keep connected cells (coordinate pairs) black/white in a set (so coordinate pairs are unique)
//	Make logic for a way to test if marking a cell a color will force another cell to be a color.
//		Create a copy (temp) of the board in that function and use that to test 
// A solve function that should keep track of its current state when solving if we try to mark a cell (50% done)
// - that has already been marked a color we should return a "contradiction state" and stop solving so we can fix errors



//  Reserach strategy solving tips on wikipedia 

// TODO: finish filtering these into tasks


Some puzzles will require the location of "unreachables"�cells that cannot be connected to any number, being either too far away from all of them or blocked by other numbers. Such cells must be black. Often, these cells will have only one route of connection to other black cells or will form an elbow whose required white cell (see previous bullet) can only reach one number, allowing further progress.
	A function that tests for unreachable cells.
		function that will create a sequence container(queue?) and push the current cell
		- then while the queue is not empty test the current cell
		- each time at the end of the loop pushing all valid neighboring cells into the queue for testing
		- the indepth logic for testing between the inital tests on a cell and when we add valid neighbor cells
		- still needs to be deteremined but we will start our current cell counter at 1, then each time the loop 
		- restarts we will pop once and add one to the counter then test that counter against a numbered region 
		- or white region if we encounter one when stepping. 
		- Function to check if connecting our region with a white region will create an impossibly large white region.
		- Function to test if adding our (current counter (+ 1 ?)) to a numbered region would be greater
			than the size (amount of numbered squares connected) of that region.
		- Function that runs test to make sure we wont connect 2 different numbered regions with eachother. 
			- Funtion that will run a test on the current cell we are looking at that will check if there are 2 nearby
				different numbered regions (connected cells)




/* Figure out how to test this condition 

Undetermined cells adjacent to a straight row (or a straight column) of black cells can be tested for
being black, because if they are black it will form two elbows, 
and there will be two adjacent white cells which need to be reachable from the islands. 
If they can not be fulfilled within the constraints, it means the cell that was
probed for blackness must be white.
*/








// Step 5: Figure out the sequence of events

/* 


int main()
{
	getOutOfBed();
	pickOutClothes();
	takeAShower();
	getDressed();
	prepareBreakfast();
	eatBreakfast();
	brushTeeth();
	getInCar();
	driveToWork();
}


If we were writing a calculator, we might do things in this order:

Get first number from user
Get mathematical operation from user
Get second number from user
Calculate result
Print result
*/


Create Our Grid with our puzzle info (size, width, numbered cells)
Have our grid solve our given puzzle
Output the result to console (cout)






// Step 6: Figure out the data inputs and outputs for each task
// (Make function prototypes)
// int calculateResult(int input1, int op, int input2);

// This should be possible, since you have a sequence of events, if you solve them in order.
// You will know your inputs and outputs.

//  If you already have the input data from a previous step, that input data will become a parameter. 
// If you are calculating output for use by some other function, that output will generally become a return value.












// Step 7: Write the task details
// In this step, for each task, you will write its actual implementation (implementation for the function)
// If confused break it into smaller tasks.











// Step 8: Connect the data inputs and outputs
// result is a temporary value used to transfer the output of calculateResult()
// into an input of printResult()
// int result = calculateResult(input1, op, input2); // temporarily store the calculated result in result






