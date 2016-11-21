#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <exception>
#include <iomanip>
#include "sorting.h"
#include "userin.h"
//#include "LList.h"

using namespace std;

//Initializes the Native Object's list to a capacity of 5 and the iterator to 0
sorting::sorting()
{
  	//I:None
	//O:The class object's default constructor
}//*/

//displays all items in the array
void sorting::print(vector<int> a)
{
    //I: A list of n integer elements
    //O: The contents of the array have been displayed to the user
    for( int i = 0; i < 75; i++ )
        cout << "=";
    cout << endl << endl;
    cout << "The current list is:" << endl;
	for(int i = 0; i < a.size(); i++)
    {
        if( i%10 == 0)
            cout << endl;
        cout << setw(5) << a.at(i);
        if( i < a.size()-1 )
            cout << "," << setfill(' ');
    }
    cout << endl;
    for( int i = 0; i < 75; i++)
        cout << "=";
    cout << endl;
    return;
}

//orders a list of values by repetitively putting a particular value into its final position
vector<int> sorting::selection_sort(vector<int> a)
{
    //I: An array of n elements to be sorted
    //O: The contents of the array have been sorted and the number
    //of comparisons have been displayed to the user
    int min_index, it = 0;//tracks the minimum position of the array that has not been sorted

    for(int i = 0; i < a.size() - 1; i++)
        {
            min_index = i;//sets lowest sorted position to 0
            for(int j = i+1; j < a.size(); j++)
                {
                    if (a.at(j) < a.at(min_index))//checks if a smaller number is found than the one in the min_index position
                        min_index = j;
                    sorting::comparisons++;
                }

            if (min_index != i)//swaps if a smaller value was found outside of the current min index position
                {
                    swap( a.at(i), a.at(min_index) );
                    sorting::comparisons++;//tracks the number of iterations through the list
                }
            sorting::comparisons++;
        }
    cout << endl << "Iterations " << it << ": ";
    return a;
}

//Uses a balanced selection sort where the pivot is selected at random
vector<int> sorting::quicksort(vector<int> a, int lower, int upper)
{
    //I: An array to be sorted, the lowest position of the vector,
    // and the highest position in the vector
    //O: The same array has been returned, but with its elements in a sorted order from
    //lowest elements at the beginning of the array and ascending to the highest element
    int num, pivot;
    vector<int> lte, gt;//hold elements <, =, > pivot respectively

    if (a.size() <= 50)
        return insertion_sort(a);
    num = randNumGen(lower, upper);
    pivot = a[num];

    lte = partition(a, pivot, 0);
    gt = partition(a, pivot, 1);

    lte = quicksort(lte, 0, lte.size()-1);
    gt = quicksort(gt, 0, gt.size()-1);

    for(unsigned int i = 0; i < gt .size(); i++)
        lte.push_back(gt.at(i));

    return lte;
}

//
vector<int> sorting::partition(vector<int> a, int pivot, int part)
{
    //I: a vector of integers in a to be partition,
    //part = 0 if getting those integers in a <= pivot
    //part = 1 if getting those integers > pivot
    //O: a partition of the desired integers <= or > pivot
    vector<int> temp;

    for(unsigned int i = 0; i < a.size(); i++)
    {
        if( part == 0 && a.at(i) <= pivot )
            {
                temp.push_back(a.at(i));
                sorting::comparisons++;
            }
        else if( part == 1 && a.at(i) > pivot )
            {
                temp.push_back(a.at(i));
                sorting::comparisons++;
            }
    }
    return temp;
}

//Sorts a list of integers and swaps positions with their neighbor if they are greater in value until the list has been sorted properly
vector<int> sorting::insertion_sort(vector<int> a)
{
    //I:A list of integers of size count
	//O: The list has been ordered from smallest to largest
	int key, pos, it = 0;//a temporary variable so no integers are lost, the current list position, and the iteration counter

	for( int i = 1; i < a.size(); i++ )
	{
		key = a.at(i);//temporary variable to holdthe current seq element
		pos = i;
		sorting::comparisons++;

		while( pos > 0 &&  a.at(pos-1) > key )//swaps positions with the key element until it's proper place has been found
            {
                a.at(pos) = a.at(pos - 1);
                pos -= 1;
                sorting::comparisons++;
			}
		a.at(pos) = key;//places key in its proper place in the array
    }
    return a;
}

vector<int> sorting::mergeSort(vector<int> a, int low, int hi)
{
    //I: An array to be sorted, the lowest position of the vector,
    // and the highest position in the vector
    //O: The same array has been returned, but with its elements in a sorted order from
    //lowest elements at the beginning of the array and ascending to the highest element
    vector<int> b, c, d, e, f;
    if( a.size() <= 1 )
        return a;
    else
    {
         for( int i = low; i < (low+hi)/2; i++ )
             c.push_back( a[i] );
         for( int i = (low+hi)/2; i < hi; i++ )
            d.push_back( a[i] );

         e = mergeSort( c, 0, c.size() );
         f = mergeSort( d, 0, d.size() );
         b = merge( e, f );
    }
    return b;
}

//Combines two sorted arrays into a single sorted array
vector<int> sorting::merge( vector<int> x, vector<int> y )
{
    //I: Two sorted arrays
    //O: The arrays have been combined so that the combined array's elements are sorted in ascending order
    vector<int> c;
    if( x.size() == 0 && y.size() == 0)
        return c;
    else if( x.size() == 0 )
        return y;
    else if( y.size() == 0 )
        return x;
    int i = 0, j = 0;
    while( i < x.size() && j < y.size() )
    {
        if( x[i] <= y[j] )
        {
            sorting::comparisons++;
            c.push_back( x[i] );
            i++;
        }
        else
        {
            sorting::comparisons++;
            c.push_back( y[j] );
            j++;
        }
        if( j == y.size() )
            while( i < x.size() )
                {
                    c.push_back( x[i] );
                    i++;
                }
        else if( i == x.size() )
            while( j < y.size() )
                {
                    c.push_back( y[j] );
                    j++;
                }

            }
    return c;
}

//Generates a random number in the range [lower, upper]
int sorting::randNumGen(int lower, int upper)
{
    //I:Lowest integer to generate, highest integer to generate
    //O:A number generated uniformly at random over the range [lower...upper]
    int j;//a temporary variable to catch the random number

    for(int i=0; i<1; i++)//random number generator seed
		srand(int(time(0)));

    j = (rand()%(upper-lower+1))+lower; //random number from 0 to i
    return j;
}

//displays the main menu options
void sorting::showMainMenu()
{
    //I: None
    //O: Displays to the user a menu of options to choose from
    //for the main menu
    cout << endl << "Choose the associated integers to do one of ";
    cout << "the following:" << endl << endl;
    cout << "1.\t Read integers from keyboard" << endl << "2.\t Print current list" << endl;
    cout << "3.\t Generate random list of integers" << endl << "4.\t Show sort menu" << endl;
    cout << "5.\t Shuffle current list" << endl;
    cout << "6.\t Quit" << endl << endl;
}

//displays the sort menu options
void sorting::showSortMenu()
{
    //I:None
    //O:Displays the sorting options menu to the user
    cout << endl << "Choose the associated integers to do one of ";
    cout << "the following:" << endl;
    cout << "1.\t Selection Sort" << endl;
    cout << "2.\t Insertion Sort" << endl;
    cout << "3.\t Quick Sort" << endl << "4.\t Merge Sort" << endl;
    cout << "5.\t Quit" << endl;
}

//Swaps the two numbers values in the list
void sorting::swap(int& num1, int& num2)
{
    //I: two integers to  be swapped
    //O: the integers have swapped places in memory
	int temp;//temporary variable used so that neither integer is lost in the swap

	temp = num1;
	num1 = num2;
	num2 = temp;
}

//Reads user input integers into the list until "q" or "Q" has been entered
//Can accept negative integers
void sorting::read(vector<int>& a)
{
    //I:An array to place a list of integers into, user keyboard input
    //O:The user's desired integers typed fro the keyboard have been placed into the list
    a.clear();//reset the vector from previous instances
    cin.ignore(1000, '\n');//clears the menu choice from the input stream

    string userval;
    int num;
    cout << endl << "Enter an integer value and q to stop" << endl << endl;

    userval = getUserIn();
    if( userval != "q" && userval != "Q" )
			while( userval != "q" && userval != "Q" )//will repeatedly prompt the user for input until "q" or "Q" entered
				{
					try{
					    for(int i = 0; i < userval.size(); i++)
                            {
                                if(userval.size() == 1)
                                    if(userval.at(i) < '0' || userval.at(i) > '9' && userval.at(0) != 'q' && userval.at(0) != 'Q')//check for exception
                                        throw outOfRange();
                                if( userval.at(0) == '-')
                                    if( i > 0 && userval.at(i) < '0' || userval.at(i) > '9')
                                        throw outOfRange();
                                if( userval.size() > 1 && userval.at(0) != '-')
                                    if(!isdigit(userval.at(i)))
                                        throw outOfRange();
                            }

						num = atoi(userval.c_str());//otherwise execute the two following statements
						a.push_back(num);
						}
					catch( outOfRange& error ){
						cout << "Exception: " << error.getName() << endl;
						}
					userval = getUserIn();
				}
}

//Gets the user input for the test score
string sorting::getUserIn()
{
	//PRE: None
	//POST: The user's input for the test score is returned to the calling function
	string val;
	//cout << "Enter a test score between 0 and 100. (q or Q to stop)." << endl << endl;
	cin >> val;
//	if( (val < "0" || val > "100") && val != "q" && val != "Q" )
//		throw OutOfRange();
	return val;
}


//This permutates the current list
void sorting::shuffle(vector<int>& a)
{
    //I:An array whose elements are to be permutated
    //O:The elements in the array have been randomly assigned to new positions in the array
    int j;//a temporary variable to catch the random number

    for(int i=0; i<1; i++)//random number generator seed
		srand(int(time(0)));

    for(int i = a.size()-1; i > 1; i--)
        {
            j = (rand()%(i+1)); //random number from 0 to i
            swap( a.at(j), a.at(i) );
        }

}

void sorting::genRandList(vector<int>& a, int rangeLow, int rangeHi, int numElements)
{
    //I:An array to place integer elements into, low and hi range for the randomly
    //generated elements such that all elements generated are in the range [rangeLow...rangeHi],
    //and the number of random elements to generate
    //O: An array containing randomly generated elements within the range
    //specified by the user's keyboard input with the the number of elements equal to
    //numElements, which is also specified by the user's keyboard input
    a.clear();
    int j;

    for(int i=0; i<1; i++)//random number generator seed
		srand(int(time(0)));

    for(int i = 0; i < numElements; i++)
        {
            j = (rand()%(rangeHi-rangeLow+1))+rangeLow; //random number from 0 to i
            a.push_back(j);
        }
}

//Default destructor
sorting::~sorting()
{

}
