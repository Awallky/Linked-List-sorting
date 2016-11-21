#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string Sentinel = "q";

class sorting{
   public:
    static int comparisons;
    sorting();
	// display all the items in the array
	void print(vector<int> a);

	// sort the sequence into non-decreasing order
	// using Selection Sorting algorithm
	vector<int> selection_sort(vector<int> a);

	// sort the sequence into non-decreasing order
	// using Insertion Sorting algorithm
	vector<int> insertion_sort(vector<int> a);

    //balanced version of selection sort
	vector<int> quicksort(vector<int> a, int lower, int upper);

    //returns a partition of #s in a < pivot if part == -1,
    //returns a partition of #s in a == pivot if part == 0,
    //returns a partition of #s in a > pivot if part == 1,
	vector<int> partition(vector<int> a, int pivot, int part);

    //sort the sequence into non-decreasing order
    //using the merge sort algorithm
	vector<int> mergeSort(vector<int> a, int lo, int hi);

	//
	vector<int> merge(vector<int> x, vector<int> y);


	// generates a random # in the range [lower, upper]
	int randNumGen(int lower, int upper);

	//Creates a temporary variable so that no integers are lost in the swap
	//Assigns the first number to the temp,
	// the second # to the first, and then the temp to the second
	void swap(int& num1, int& num2);

	//Displays the requisite main menu of 1. Read, 2. Print,
	// 3. Sort, 4. Shuffle, 5. Search, and 6. Quit
	void showMainMenu();

	//Shows the options for the 3 sorts included in the program
	// 1. Selection Sort, 2. Insertion Sort, 3. Bubble Sort, 4. Merge Sort, 5. Quit
	void showSortMenu();

	//reads user input from the keyboard into a vector of integers
	void read(vector<int>& a);

	//takes keyboard input for the # of elements desired by the user
	//then takes the lowest desired integer by the user and the highest desired integer
	//and generates the number of desired integers within the specified range
	// between the low and hi inputs
	void genRandList(vector<int>& a, int lower, int upper, int numElements);

	//returns a string of the user's keyboard input
	string getUserIn();

	//permutates the current list
	void shuffle(vector<int>& a);

	//default destructor
	~sorting();
};
#endif // SORTING_H_INCLUDED
