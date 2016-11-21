#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <exception>
#include "sorting.h"
#include "userin.h"
#include "LList.h"

using namespace std;

int sorting::comparisons = 0;

int read_Int(int lower, int upper);//Verifies user inputs integer within the bounds of the menu options

int main()
{
    vector<int> a;
    int menuN;//variables for menu number, position where a desired key is found, and the key respectively
    sorting s;

    s.showMainMenu();//Prompts user for menu choice
    menuN = read_Int(1, 6);//gets mainMenu choice

    while( menuN != 6 )//while the user has not quit the menu run the program
        {
            if( menuN == 1 )//------------Read--------
                s.read(a);//reads user input into the seq dynamic array

            else if( menuN == 2 )//-------Print-------
                {
                    //cout << "The current list is: ";
                    s.print(a);//Displays the contents of the current list
                }

            else if( menuN == 3 )//-----Generate Random List---------
                {
                    unsigned int low = 1, hi = 100000, numElements;

                    cout << "Enter the number of elements in the ";
                    cout << "list you would like to generate." << endl;
                    numElements = read_Int(0, 1000000);
                    cout << "Enter an integer corresponding to the ";
                    cout << "low end of the range for the elements generated." << endl;
                    low = read_Int(low, hi);
                    cout << "Enter an integer corresponding to the ";
                    cout << "high end of the range for the elements generated." << endl;
                    hi = read_Int(low+1, hi);

                    s.genRandList(a, low, hi, numElements);
                }

            else if( menuN == 4 )//------Sort--------
                {
                    s.showSortMenu();//diplays the options for the three sorts included for the program
                    menuN = read_Int(1, 5);//verifies valid sort menu choice within the range of 1 and 4

                    while(menuN != 5)
                        {
                            if(menuN == 1)
                            {
                                a = s.selection_sort(a);//executes the selection sort
                                cout << sorting::comparisons << endl;
                                sorting::comparisons = 0;//reset comparisons counter
                            }
                            else if(menuN == 2)
                                {
                                    a = s.insertion_sort(a);//executes the insertion sort
                                    cout << sorting::comparisons << endl;
                                    sorting::comparisons = 0;//reset comparisons counter
                                }
                            else if(menuN == 3)
                                {
                                    a = s.quicksort(a, 0, a.size()-1);//executes the bubble sort
                                    cout << sorting::comparisons << endl;
                                    sorting::comparisons = 0;//reset comparisons counter
                                }
                            else if (menuN == 4)
                                {
                                    a = s.mergeSort(a, 0, a.size());
                                    cout << sorting::comparisons << endl;
                                    sorting::comparisons = 0;//reset comparisons counter
                                }
                            s.showSortMenu();//end of while loop to prompt user for input
                            menuN = read_Int(1, 5);
                        }
                }//End of sort menu

                else if( menuN == 5 )//-----Shuffle-------
                    s.shuffle(a);//permutates the current list

            s.showMainMenu();//Prompts user for menu choice at the end of the main while loop
            menuN = read_Int(1, 6);
        }
    return 0;
}//*/

//Note: regular functions
//verifies that the user has entered an integer value that is valid for the current menu options
int read_Int(int lower, int upper)
{
	int userval; //Holds value for user input
	//cout << "Enter an integer in the range [lower, upper]." << endl;
	cin>>userval;

    while( !cin.good() )//verifies that an integer has been entered into the userval variable
        {
			cin.clear();
			cin.ignore(100, '\n');
			cout<< "Invalid data type, should match type int.";
			cout<<"Try again."<<endl;
			cin>>userval;
        }

		while( userval < lower || userval > upper )//verifies that a valid integer within the specified range is entered
            {
                cout<<"Invalid entry. ";
                cout<<"Should be >= "<< lower <<"and <= " << upper;
                cout<<endl;
                cin>>userval;

                while( !cin.good() )
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout<< "Invalid data type, should match type int.";
                        cout<<"Try again."<<endl;
                        cin>>userval;
                    }
			}
	return userval;
}
