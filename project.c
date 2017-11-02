/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << Focal Chord >>

#include "project.h"

/*	
	********Commenting Style********

	If I am commenting for a block of code this will be the style of commenting:
		// comment
		do something 
		do more things

	If I am commenting for a line of code this will be the style of commenting:
		do something // comment

	The header of the main functions will always be in this format:

	Input -
	Output - 
	Description of the Function -
	Algorithm of the Function - 

	The header of the helper functions will always be in this format:

	Brief description where its used -
	Description of the function -
	Algorithm of the function (if required) -

*/

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */


/* ***************HELPER FUNCTIONS FOR THE FIRST TEN FUNCTIONS*************** */

/* 
	toUpper is the first helper function and is used in Emphasise

	Description of this function: 

	In Emphasise we are required to make all the lowercase letters between the two underscores capital. So what this function does is take
	any character between the underscore, checks if it is lower case and if it is returns the uppercase equivalent by using ASCII arithmetic,
	if it is not it returns the input.
*/

char toUpper(char lower)
{
	if ((lower >= 'a') && (lower <= 'z')) {
		char upper = lower - 32;
		return upper;
	}

	else
		return lower;
}

/*
	findCoordinates is the second helper function and is used in ConnectTwo

	Description of the function:

	This function finds the location of the '1' and '2' for the map in ConnectTwo

	Algorithm of the function: 

	Loop through all rows and columns
		i) If a 1 is found store these row and column numbers since this is where our path starts.
		ii) If a 2 is found store these row and column numbers since this is where our path ends
*/


void findCoordinates(int maze[10][10], int *startRow, int *startCol, int *endRow, int *endCol)
{
	int i;
	int j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {

			if (maze[i][j] == 1) {
				*startRow = i;
				*startCol = j;
			}

			if (maze[i][j] == 2) {
				*endRow = i;
				*endCol = j;
			}
		}
	}
}

/*
	findMax is the third helper function and is used in Histogram

	Description of the function:

	findMax finds the maximum value inside the values array 

	Algorithm of the function: 

	Loop through array
		i) if any value in the array is greater than the current max value
		ii) then replace the max value with the array value
*/

int findMax(int *values, int numValues)
{
	int i;
	int max = values[0];

	for (i = 1; i < numValues; i++) {
		if (values[i] > max)
		max = values[i];
	}

	return max;
}

/*
	printBorder is the fourth helper function and is used in Histogram

	Description of the function:

	printBorder prints the start border of the histogram and the end border of the histogram

	Algorithm of the function: 

	Loop through until arrayLength + 2
		i) Print the asterisk border
	If we are printing the top border
		i) End with a new line
	If we are printing the bottom border
		i) Terminate the string
*/

void printBorder(char *inputResult, int arrayLength, int printLine, int *count)
{
	int i;

	for (i = 0; i < (arrayLength + 2); i++) {
		inputResult[*count] = '*';
		(*count)++;
	}

	if (printLine == 1) {
		inputResult[*count] = '\n';
		(*count)++;	
	}

	else
		inputResult[*count] = '\0';
}

/*
	countTotalPureGold is the fifth helper function and is used in GoldRush and countPureGoldComponent

	Description of the function:

	Counts the amount of pure gold in the given map given conditions.
	This function was made because I had to use it twice in my project and also because the second if condition
	looked really bad if it was in my main functions since it is so long.

	Algorithm of the function: 

	1) Make sure you are in bounds for the pure gold region
		2) Check the adjacent elements have '9'
			3) If they do, then increment the gold
*/

void countTotalPureGold(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int *i, int *j, int rows, int cols, int *pureGold)
{
	if (*i != 0 && *i != rows - 1 && *j != 0 && *j != cols - 1) {
		if (map[*i + 1][*j] == 9 && map[*i - 1][*j] == 9 && map[*i][*j + 1] == 9 && map[*i][*j - 1] == 9 && map[*i + 1][*j + 1] == 9 && map[*i - 1][*j - 1] == 9 && map[*i + 1][*j - 1] == 9 && map[*i - 1][*j + 1] == 9)
			(*pureGold)++;
	}
}

/* ***************HELPER FUNCTIONS FOR GOLD RUSH BONUS TASKS*************** */
/*	
	This is kind of an explanation to how I solved the bonus tasks and how the helper functions come about.

	Let us consider this map:
	
	  1 2 3 4 5 6	--> (x direction) going down (y direction)
	  ----------- 	
	1|7 8 4 4 5 9|	
	2|2 1 0 7 8 9|	
	3|3 9 9 9 1 0|	
	4|9 9 9 9 3 5|
	5|9 9 9 0 1 4|
 	6|9 9 9 9 2 3|
     -------------	

    Lets consider these coordinates in the form (x,y), 

    The first component of gold is:
	[(2,3),(3,3),(4,3),(1,4),(2,4),(3,4),(4,4),(1,5),(2,5),(3,5),(1,6),(2,6),(3,6),(4,6)] 

	The second component of gold is:
	[(6,1),(6,2)]

	To find the components firstly we need to find all the cells that has 9 in it (let’s call
	this array cells) and I store these while running the GoldRush function.

	Once we have found the components, we then iterate over these cells and for each cell we can 
	find all of its neighbours.

	Once we have found the eight neighbours we need to check whether they are in bounds of the map or
	out of bounds and we also have to check if the adjacent neighbour was already encountered or not.

	There is where the isVisited helper function I wrote comes into play, consider we start at cell(2,3)
	and we find all its neighbours and then recursively call the function on each of its neighbours 
	so now we are at cell(3,3) (because it is one of the adjacent neighbours of cell(2,3) and it also has a '9' in it)
	but when we find all the neighbours of cell(3,3) we will also find (2,3) since it is the neighbour of (3,3)
	but we have already encountered it before so can skip it. If we don't skip (2,3) then the function
	finds (3,3) again and from (3,3) we will find (2,3) again and so on and we will be stuck in an infinite loop.

	So the isVisited function is used to skil cells that were already discovered (since we don't want our recursion to be endless)
	
	So that is an explanation of how I found components for the bonus tasks

	If we want the amount of pure gold in each component then we take one component that was found by the above strategy
	and we check whether it has 8 neighbours with '9' or not.
*/

/* 
	The sixth helper function (swap) is used in bubbleSort.

	Description of the function:

	Swaps two integers, for example (4,3) becomes (3,4)
*/

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* 
	The seventh helper function (bubbleSort) is a void type.

	Description of the function:

	Sorts elements in the reverse order using bubble sort algorithm.

	It is used in the computeBonusTasks function to sort region arrays in decreasing order.
*/

void bubbleSort(int arr[], int n)
{
	int i,j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j+1]>arr[j])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

/* 
	The eigth helper function (isVisited) is used in findComponent and computeBonusTasks functions.

	Description of the function:

	As described in the main strategy of how I solved this, isVisited makes sure we are not checking the same
	cell again because if we are then we get stuck in an infinite loop.

	It is used in the computeBonusTasks function to check if the cells are visited or not.
*/

int isVisited(int visited[MAX_ARRAY_SIZE][2], int cell[2])
{
	int lenVisited = 0;
	int i;

	for (i = 0 ; ; i++) {
		if (visited[i][0] == -1) {
			lenVisited = i;
			break;
		}
	}

	for (i = 0; i < lenVisited; i++) {
		if (visited[i][0] == cell[0] && visited[i][1] == cell[1])
		// if the x coord and the y coord of the current visited cells equals to the x,y coords of the given cell
		// then this cell have already been discovered - return 1
			return 1;
	}

	return 0; // If the cell was never discovered
}

/* 
	The ninth helper function (countPureGoldComponent) is used in the computeBonusTasks function to check if the given section of 
	the map contains pure gold or not.

	Description of the function:

	This function computes the amount of pure gold in the given component
	It runs through all the cells in the given component (part of the map), for each cell
	it checks whether it has 8 neighbours with '9', if yes then it increments the pure gold counter.

	This function returns pure_gold in the given component (area).
*/

int countPureGoldComponent(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int component[MAX_ARRAY_SIZE][2], int rows, int cols, int numComps)
{
	int pureGold = 0;
	int k;

	for (k = 0; k < numComps; k++) {
		int i = component[k][0];
		int j = component[k][1];
		countTotalPureGold(map, &i, &j, rows, cols, &pureGold);
	}

	return pureGold;
}

/* 
	The tenth helper function (findComponent) is an int type and used in the computeBonusTasks function.

	findComponent is based of DepthFirstSearch (a famous algorithm)
	The pseudocode from this page has been used: https://en.wikipedia.org/wiki/Depth-first_search
	(Recursive implementation of DPS)

	Description of the function:

	This function finds non-connected components
	Description of the algorithm:
	a) If the given cell is out of bounds of the map, or was already discovered
	or it doesn't have '9' in it  then return 0	
	b) Else append given cell to visited array, then append this cell to the component array
	   ,find all its neighbours and return 1+ recursive call of this function on each neighbour of
	   the given cell.

	So, this function forms a sort of web where we start from one cell and the find all its neighbours and for each 
	neighbour of the neighbour we find all its neighbours and so forth.
*/

int findComponent(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int rows, int cols, int visited[MAX_ARRAY_SIZE][2], int cell[2], int component[MAX_ARRAY_SIZE][2])
{
	int lenVisited = 0;
	int i = 0;
	int k = 0;

	if (cell[0] > rows - 1 || cell[0] < 0 || cell[1] < 0 || cell[1] > cols - 1 || (isVisited(visited, cell) == 1) || map[cell[0]][cell[1]] != 9)
		return 0;
	else {

		//Find the number of visited cells
		for (i = 0; ; i++) {
			if(visited[i][0] == -1) {
				lenVisited = i;
				break;
			}
		}

		//Append x,y coordinates of the current cell to the visited array
		visited[lenVisited][0] = cell[0];
		visited[lenVisited][1] = cell[1];

		visited[lenVisited+1][0] = -1;
		int componentIndex = 0;

		for (k = 0; ; k++) {
			if (component[k][0] == -1)
				break;
			componentIndex++;
		}

		//Append x,y coordinates of the current cell to the component
		component[componentIndex][0] = cell[0];
		component[componentIndex][1] = cell[1];

		// Mark end of the array
		component[componentIndex + 1][0] = -1;

		// Find all 8 neighbours of the current cell
		int cell1[2]; cell1[0] = cell[0] + 1; cell1[1] = cell[1];
		int cell2[2]; cell2[0] = cell[0] - 1; cell2[1] = cell[1];
		int cell3[2]; cell3[0] = cell[0];	  cell3[1] = cell[1] + 1;
		int cell4[2]; cell4[0] = cell[0];	  cell4[1] = cell[1] - 1;
		int cell5[2]; cell5[0] = cell[0] + 1; cell5[1] = cell[1] - 1;
		int cell6[2]; cell6[0] = cell[0] - 1; cell6[1] = cell[1] + 1;
		int cell7[2]; cell7[0] = cell[0] + 1; cell7[1] = cell[1] + 1;
		int cell8[2]; cell8[0] = cell[0] - 1; cell8[1] = cell[1] - 1;

		// Return 1 + the amount of the '9' neighbours of the neighbours (recursive call)

		return 1 + findComponent(map, rows, cols, visited, cell1, component) + findComponent(map, rows, cols, visited, cell2, component) + findComponent(map, rows, cols, visited, cell3, component) + findComponent(map, rows, cols, visited, cell4, component) + findComponent(map, rows, cols, visited, cell5, component) + findComponent(map, rows, cols, visited, cell6, component) + findComponent(map, rows, cols, visited, cell7, component) + findComponent(map, rows, cols, visited, cell8, component);
	}

	}

/* 
	The eleventh helper function (computeBonusTasks) is a void type.

	Description of the function:

	This function is an auxillary function which computes the required bonus tasks.
	
	All the above 5 helper functions are used in this function.

	Description of the algorithm:
	a) Runs through all the cells that have a 9 on the map.
		i) If the current cell was not visited then it is the part of the new component so we call findComponent on this cell (bonus task 1)
		It also tells you if there is a region of pure gold around this given region by calling 
		countPureGoldComponent on this component.
	b) Once everything was found, return the results (either for bonus 1 or bonus 2)

	This last helper function is used in GoldRush to compute the bonus tasks
*/

void computeBonusTasks(int *results, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int visited[MAX_ARRAY_SIZE][2], int rows, int cols, int cells[MAX_ARRAY_SIZE][2], int numCells, int bonus)
{	
	int regions[MAX_ARRAY_SIZE] = {0}; // Store the amount of regions
	int pureComponents[MAX_ARRAY_SIZE] = {0}; // Stores the amount of pure gold in each component

	int regionIndex = 0;
	int pureIndex = 0;
	int i;

	for (i = 0; i < numCells; i++) {
		if (isVisited(visited, cells[i]))
			continue;

		int component[MAX_ARRAY_SIZE][2];
		component[0][0] = -1;
		regions[regionIndex] = findComponent(map, rows, cols, visited, cells[i], component);

		if (bonus == 2) {
			pureComponents[pureIndex] = countPureGoldComponent(map, component, rows, cols, regions[regionIndex]);
			pureIndex++;
		}

		regionIndex++;
	}

	// To compute Bonus Task I
	if (bonus == 1) {
		bubbleSort(regions, regionIndex);
		for (i = 0; i < regionIndex; i++) {
			results[i] = regions[i];
		}

		results[regionIndex] = 0;
	}

	// To compute Bonus Task II
	if (bonus == 2) {
		bubbleSort(pureComponents, pureIndex);
		for (i = 0; i < pureIndex; i++) {
			results[i] = pureComponents[i];
		}

		results[pureIndex] = 0;
	}
}

/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* 
	The first function (DivisorOfThree) of int type has

	Input(s):
	1) int a (arbitrary number)
	2) int b (arbitrary number)
	3) int c (arbitrary number)
	
	Output:
	1) gcd (Returns the greatest common divisor of these 3 numbers). 

   	Description of the function:

	DivisorOfThree finds the greatest common divisor of three given numbers.

    Algorithm of the Function: 
 
	1) First check if all the inputs are greater than zero, if they are:
		a) loop through all numbers starting at 1 to check the gcd and increment until i reaches the largest input integer. 
		b) if they all inputs divide i (ie remainder of zero) then the gcd is equal to i
		c) At the end of the loop return the gcd. 
	2) If the first condition is false then return -1 because then one of the inputs is negative or equal to zero. 
*/

int DivisorOfThree(int a, int b, int c)
{	
	int i = 0;
	int gcd = -1;

	if ((a && b && c) > 0) {
		for (i = 1; (i <= a && i <= b && i <= c); ++i) {
			if (a % i == 0 && b % i == 0 && c % i == 0)
				gcd = i;
		}
		return gcd;
	}
}

/* 
   The second function (AverageSheep) of double type has 

   Input(s):
   1) counts (which is an array of max length 1000)

   Output (type double):
   1) Average of all the numbers in the array
   
   Description of the function:

   Average Sheeptakes an array of an arbitrary length (int type) and finds the average of all the numbers in that array.
   If there is a '-1' inside the array, then the function ignores this and the function ends the loop when a '9999' is spotted inside that array. 
   This function returns the average of the values in the array.

   Algorithm of the Function:
 
	1) Loop through the counts array (starting at zero) until you reach the number '9999' in the array
		a) if you approach a number not equal to '-1' then increment sum with the number in the array and increment the count of numbers  
		b) Increment the index number 
	2) After the loop has finished, we are left with a sum and count
		a) If no numbers were found before '9999' was reached (ie count equals zero) then return zero.
		b) Else return sum/count which is the average of the numbers found.
*/

double AverageSheep(int *counts)
{
	double count = 0;
	double sum = 0;
	int i = 0;

	while (counts[i] != 9999) {
		if (counts[i] != -1 ) {
			sum += counts[i];
			count++;
		}
		i++;
	}

	if (count == 0)
		return 0;
	else 
		return (sum / count);
}

/* 
	The third function (Emphasise) of void type has

	Input(s):
	1) word (which is a string of char type)

	Output:
	- No output since this function modifies a string
	
	Description of the function:

	Emphasise takes a given string which contains letters/numbers and exactly 2 underscores -> _ 
    Emphasise takes the letters between the 2 underscores and capitalizes them (makes them uppercase) and then removes these underscores. 

	Algorithm of the function:
	
 	1) Find the index of the underscores in the word string by using strchr and strrchr
 	2) We then split up our string into 3 seperate segments (before underscore, after underscore and between them)
 	3) Loop through the middle string and make any lower case letters uppercase by calling the toUpper function (helper).
 	4) Concatenate all the 3 segments together.
*/

void Emphasise(char* word)
{
	char mString[MAX_ARRAY_SIZE];
	char eString[MAX_ARRAY_SIZE];

	int i = strchr(word, '_') - word;
	int j = strrchr(word, '_') - word;
	int k = 0;

	word[i] = word[j] = 0; 	//Splitting string into segments

	strcpy(mString, word + i + 1); 	//Removing the underscore from the middle string

	while (mString[k] != '\0') {
		mString[k] = toUpper(mString[k]);
		k++;
	}

	strcat(word, strcat(mString, strcpy(eString, word + j + 1)));
}

/* 
	The fourth function (PrimeFactors) of int type has 

	Input(s):
	1) n (an intger number greater than or equal to two)
	2) factors (an empty array)

	Output:
	1) index = The number of prime factors for the input 'n'
	
	Description of the function:

	PrimeFactors takes a given integer number (greater than or equal to two) and an empty array (int type)
	The function, takes this number and finds its prime factors and stores them in an array called 'factors'.
	Ultimately, this function returns the number of factors the input number has. 
 
    Algorithm of the Function:

	1) Initially divisor equals 2 since this is the smallest prime.

	2) While the number is not equal to 0
		a) if the number cannot be divided by the divider
			i) increase divider
		b) else 
			i) divide number by divider
			ii) append divider to the factors array
		c)	if the number equal 1 then
			i) break (since no more numbers can be found)
*/

int PrimeFactors(int n, int *factors)
{
	int numFactors = 0;
	int primeDiv = 2;

	while (n != 0) {

		if (n % primeDiv != 0)
			primeDiv++;

		else {
			n /= primeDiv;
			factors[numFactors] = primeDiv;
			numFactors++;

			if (n == 1) 
				break;
		}
	}
	
	return numFactors;
}


/* 
	The fifth function (ConnectTwo) of void type has 

	Input(s):
	1) map (an array with 10 rows and 10 cols)

	Output:
	- there is no output since this function has a void return type.
	
	Description of the function: 

	Connect takes a 10x10 array which contains all elements to be zero except two elements  
	where they are initialized to be 1 (the starting point) and 2 (the end point).

	What this function does is find the shortest path between the starting point and the end point through this array,
	this function will prioritize a diagonal path and then a vertical or horizontal path. The path that is found by this function
	will be represented by 3's.
	
	The function doesn't return anything as it is a void return type and only modifies the given map.
 
    Algorithm of the function: 

	1) Call the findCoordinates helper function to find the start and end coordinates (x,y)
	2) While the start (x,y) coordinate is not equal to its equivalent end (x,y) coordinate 
		a) if the end row number is greater than the start row number
			i) move down
		b) if the end row number is less than the start row number
			i) move up
		c) if the end col number is greater than the start col number
			i) move right 
		d) if the end col number is less than the start col number
			i) move left
		
		After moving, append a '3' to the path.

	3) Mark the end of the maze with a '2', since this was overwritten in the process of making the path.		

*/

void ConnectTwo(int maze[10][10])
{
	int startRow = 0, startCol = 0, endRow = 0, endCol = 0;
	findCoordinates(maze, &startRow, &startCol, &endRow, &endCol);

	while (startRow != endRow || startCol != endCol) {
		startRow = (endRow > startRow) ? (startRow++) : (startRow--);
		startCol = (endCol > startCol) ? (startCol++) : (startCol--);
		maze[startRow][startCol] = 3;
	}

	maze[endRow][endCol] = 2;
}

/* 
	The sixth function (DayTrader) of void type has:

	Input(s):
	1) Prices (an array of integers representing the price information)
	2) n (the length of array)
	3) bestRun (length of the best run)
	4) bestRunIndex (index of the array where the best run starts)

	Outputs:
	- No output since this is a void type function and ultimately use pointers to output bestRun and bestRunIndex.

	Description of the function:
	
	DayTrader takes an array of max length 1000, and finds an increasing sequence in the array (from left to the right).

	Algorithm of the function:
	
	1) Start the nested loop 
		a) Finds the longest increasing subsequence.
		b) When a new subsequence is found it compares the length to the previously found subsequence.
		c) If the new subsequence's length is longer than the old one than the new subsequence becomes the best one.
		d) It also sets the index of the best subsequence. 
*/

void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int i, j = 0;
	*bestRun = 0;
	*bestRunIndex = 0;
	int currentRun = 0;

	if (numPrices == 1)
		return;

	for (i = 0; i < numPrices; i++) {
		for (j = i; j < numPrices - 1; j++) {

			if (prices[j+1]>prices[j])
				currentRun++;
			else
				break;
		}

		if (currentRun > *bestRun) {
			*bestRun = currentRun;
			*bestRunIndex = i;
		}

		currentRun = 0;
	}
}

/* 
	The seventh function (Compress) of void type has:

	Input(s):
	1) input (an array of non negative integers)
	2) output (an empty array which will contain the compressed data)

	Outputs:
	- No output since this is a void type function and ultimately use pointers to output the compressed array.

	Description of the function:
	
	Compress takes an array of max length 1000, and counts how many times a value is repeated consecutively and 
	it will store the number of times a number repeated 'x' followed by the number it self in an array.

	Algorithm of the function:
	
	1) Loop through the array until you reach negative -1
		a) if the number to find is equal to to the input array element then increase occurences
		b) if the array element is not equal to the number to find then
			i) append 'i' element to output which is occurences
			ii) append 'i+1' element to output which is the number to find
			iii) reset occurences and numberToFind
		c) terminate array with appending -1 to the last element of output
*/

void Compress(int *input, int *output)
{
	int inputCounter = 0;
	int outputCounter = 0;
	int occurences = 1;
	int numberToFind = input[inputCounter];

	while (input[inputCounter] != -1) {
		inputCounter++;

		if (input[inputCounter] == numberToFind) 
			occurences++;
		else if (input[inputCounter] != numberToFind) {
			output[outputCounter] = occurences;
			output[outputCounter + 1] = numberToFind;
			outputCounter += 2;
			occurences = 1;
			numberToFind = input[inputCounter];
		}
	}

	output[outputCounter] = -1;
}

/* 
	The eight function (AddOne) of void type has:

	Input(s):
	1) input (an array of non negative integers)
	2) output (an empty array which will contain the incremented data)

	Outputs:
	- No output since this is a void type function and ultimately use pointers to output the incremented output array.

	Description of the function:
	
	AddOne takes a numerical string and uses ascii arithmetic to increment this string by one. (ie '999' becomes '1000')

	Algorithm of the function:
	
	1) Loop through while length is greater than zero
		a) if the element of input array is 9 then make this zero
		b) else add one to it
		c) if the element doesnt equal zero then break the loop

	2) At the end, if the first element of the array is equal to zero
		a) copy this string with an element plus one
		b) else copy the altered string to the output
*/

void AddOne(char *input, char *output)
{
	int len = strlen(input);
	while (len > 0) {
		len--;

		if (input[len] == '9')
			input[len] = '0';
		else
			input[len] = (input[len] + 1);

		if (input[len] != '0')
			break;
	}

	if (input[0] == '0') {
		strcpy(output + 1, input);
		output[0] = '1';			
	} else 
		strcpy(output, input);
}

/* 
	The ninth function (Histogram) of void type has:

	Input(s):
	1) result (char type array, where the output histogram will be stored)
	2) value (an array representing the data to be stored on the histogram)
	3) numValues (length of the value array)

	Outputs:
	- No output since this is a void type function and ultimately use pointers to output the histogram.

	Description of the function:
	
	Histogram takes in data values and plots a histogram composed of only 'X's and '*'s.

	For example let's say we are given data such as {1,2,1}, this function outputs:
	*****
	* X *
	*XXX*
	*****

	Algorithm of the function:
	
	1) Prints top border using printBorder helper function
	2) Finds the largest value in the data given 
	3) Nested Loop (starting from the maximum number and decrementing)
		i) If the condition that the maximum value - rows is equal to value[current cols] then print 'X'
		ii) Else append ' '
	4) Prints bottom border using printBorder helper function
	
*/

void Histogram(char *result, int *values, int numValues)
{
	int i, j;
	int maxValue = findMax(values, numValues);
	int count = 0;
	printBorder(result, numValues, 1, &count);

	for (i = 0; i < maxValue; i++) {
		for (j = 0; j < numValues + 2; j++) {
			if (j == 0 || j == (numValues + 1))
				result[count] = '*';
			else if (values[j - 1] >= (maxValue - i))
				result[count] = 'X';
			else 
				result[count] = ' ';
			count++;
		}
		
		result[count] = '\n';
		count++;
	}

	printBorder(result, numValues, 0, &count);
}

/* 
	The tenth function (GoldRush) of void type has:

	Input(s):
	1) results (a one dimensional array where 2 things will be stored - total gold and pure gold)
	2) row (indicates how many rows are present on the map)
	3) cols (indicates how many columns are present on the map)
	4) map (a two dimensional array containing the map data)
	5) bonus ( to activate the bonus tasks (either 1 or 2))

	Outputs:
	- No output since this is a void type function and ultimately modifies the map input.

	Description of the function:
	
	GoldRush takes an arbitary map and searches this map for total gold and pure gold.
	The map contains random numbers from 0-9, a '9' on the map represents gold. If any 
	element has all its neighbours being a '9' then this counts as 1 pure gold.

	This function basically takes this map, finds the amount of gold and pure gold and 
	outputs it into an array.

	Algorithm of the function:
	
	1) Nested loop through the row and columns
		a) If the current row and column equals 9
			i) Increment the total gold
				ii) If all 8 neightbours of the current cell has 9 then increase pure gold.
	2) If no bonus task has been selected (bonus equals zero) then return the result.
	3) Else call the computeBonus function which will carry out the bonus tasks.
*/ 

void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	int i,j;

	int cellsIndex = 0;
	int totalGold = 0;
	int pureGold = 0;
	int cells[MAX_ARRAY_SIZE][2]; //Initializing the array which is going to store the cells that has '9'

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {

			if (map[i][j] == 9) {
				//add this cell to cellIndex for bonus tasks
				cells[cellsIndex][0] = i;
				cells[cellsIndex][1] = j;
				cellsIndex++;
				totalGold++;
				countTotalPureGold(map, &i, &j, rows, cols, &pureGold);
			}
		}
	}

	if (bonus == 0) {
		results[0] = totalGold;
		results[1] = pureGold;
		return;
	}

	// **************** ONLY FOR BONUS TASKS **************** //

	int visited[MAX_ARRAY_SIZE][2];
	visited[0][0] = -1;
	computeBonusTasks(results, map, visited, rows, cols, cells, cellsIndex, bonus);
}

