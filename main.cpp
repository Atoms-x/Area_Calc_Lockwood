/*
	Input Validation with Ref Functions 
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c

	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Purpose: Area calculation program
  IDE: Repl.it
*/

#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
#include <string> //for string manipulation
#include <sstream> //for string manipulation and comparison
#include <iomanip> //for precision setting
#include <cmath> //for exponents (pow) and pi constant

using namespace std;

double menu(); //function prototype for menu
double triArea(double, double); //function prototype for area of triangle function
double recArea(double, double); //function prototype for area of rectangle function
double cirArea(double); //function prototype for area of rectangle function

int main()
{
  cout << fixed << setprecision(3); //setting max decimal places to 3 program output

  //menu option variable
  int menuOption = 0;
 
  //variables to be passed to the functions
  double base = 0.0;
  double height = 0.0;
  double length = 0.0;
  double width = 0.0;
  double radius = 0.0;

  //color code variables and clear
   string cRed = "\x1b[1;91m";
   string cGreen = "\x1b[1;32m";
   string cYellow = "\x1b[1;93m";
   string cBlue = "\x1b[1;34m";
   string cOrange = "\x1b[1;33m";
   string cCyan = "\x1b[1;36m";
   string cPurple = "\x1b[1;35m";
   string cBGreen = "\x1b[1;102m\x1b[30m";
   string cBCyan = "\x1b[1;106m\x1b[30m";
   string cBYellow = "\x1b[1;103m\x1b[30m";
   string cItalic = "\x1b[3m";
   string cUnderL = "\x1b[4m";
   string cReset = "\x1b[0m";
   string cClear = "\033[2J\033[1;1H";

  //do-while loop to ensure the menu executes at least once
  do
  {
    //Prompt: Menu options
    cout << cUnderL << "\n Choose an option \n" << cReset << endl;
    cout << cGreen << "1 - The area of a Triangle \n" << cReset << endl;
    cout << cCyan << "2 - The area of a Rectangle \n" << cReset << endl;
    cout << cYellow << "3 - The area of a Circle \n" << cReset << endl;
    cout << cOrange << "4 - Clear the Screen and Start Over \n" << cReset << endl;
    cout << cRed << "5 - TERMINATE THE PROGRAM \n" << cReset << endl;

    //Input: menu choice
    menuOption = validateInt(menuOption);

    //Processing
    if ( menuOption == 1)
    {
      cout << "\n Input a base length \n";
      base = validateDouble(base);
      cout << "Input a height \n";
      height = validateDouble(height);
      cout << "The area of your Triangle is " << cBGreen << triArea(base, height) << cReset << endl; 
      cout << "\n Press the any key to continue...";
      cin.ignore();
      cout << cClear << endl;
    }

    else if ( menuOption == 2)
    {
      cout << "\n Input a length \n"; 
      length = validateDouble(length); 
      cout << "Input a width \n";
      width = validateDouble(width);
      cout << "The area of your rectangle is " << cBCyan << recArea(length, width) << cReset << endl;
      cout << "\n Press the any key to continue...";
      cin.ignore();
      cout << cClear << endl; 
    }
    
    else if ( menuOption == 3)
    {
      cout << "\n Input a radius \n";
      radius = validateDouble(radius);
      cout << "The area of your circle is " << cBYellow << cirArea(radius) << cReset << endl;
      cout << "\n Press the any key to continue...";
      cin.ignore();
      cout << cClear << endl;
    }

    else if ( menuOption == 4)
    {
      cout << cClear << endl;
      cout << "\n Press the any key to continue...";
      cin.ignore();
      cout << cClear << endl;
    }
    
    if ( menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4 && menuOption != 5 )
    {
      cout << cRed << "\n NOT A MENU OPTION \n" << cReset << endl;
    }

  } while (menuOption != 5);
  
  cout << cClear << cRed << "TERMINATED";
  
    return 0;
}

double triArea (double b, double h)
{
 return (b * h)/2;
}

double recArea (double l, double w)
{
  return l * w;
}

double cirArea (double r)
{
  return M_PI * (pow(r, 2));
}