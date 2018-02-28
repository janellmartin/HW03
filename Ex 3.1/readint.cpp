#include "readint.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ios>
using namespace std;

//hint said to copy example on p.145
int read_int(const string &prompt, int low, int high)
{
    if (high <= low)
    {
        throw range_error("error in range");
    }
    cin.exceptions(ios_base::failbit);
    int num = 0;
    while (true)
    {
        try{
           
            cout << prompt;
            cin >> num;
            // added an if loop to make sure the number is within range
            //if number isn't in range it tells them what is wrong and asks for a new input
            while(num < low || num > high)
            {
                cout << "Number not in range, try again: ";
                cin >> num;
            }
            return num;
        }catch (ios_base::failure& ex)
        {
            cout << "Bad numeric string -- try again \n";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        
        
    }
}
