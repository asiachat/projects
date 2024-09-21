#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "intCalculator_functions.h"

//------------------------------------------------------------------
// File name:   intCalculator.cpp
// Assign ID:   PROG8
// Due Date:    8/3/23 at 11:30pm 
//
// Purpose:     Implement integer calculator using do-while loop, functions..
//
// Author:      chatmonA020 Asia Chatmon
//------------------------------------------------------------------

//****************************************************************
// **** FUNCTIONS used by main program. 
// YOUR JOB: Create a BODY for each function.
//  ** WARNING #1: Do NOT CHANGE the function parameters!
//  ***WARNING #2: Implement ONE FUNCTION AT A TIME!! Write+compile+run.
//****************************************************************

//----------------------------------------------------------------
// Function: Display copyright, given year, courseID and full name.
//----------------------------------------------------------------
void Display_Copyright(string Name, string courseID, int year)
{
   cout << "\n(c) " << year << ", " << courseID << ' ' << Name;
   cout << endl;
   cout << "\n"; 
}


//----------------------------------------------------------------
// Function: Display Calculator Menu and prompt for menu choice.
//           MUST MATCH menu from key-intCalculator.crun
//----------------------------------------------------------------
void Show_Menu()
{
   cout << "   +========================+" << endl;
   cout << "   | INTEGER CALCULATOR     |" << endl;
   cout << "   +========================+" << endl;
   cout << "   |                        |" << endl;
   cout << "   |   + Add                |" << endl;
   cout << "   |   - Subtract           |" << endl;
   cout << "   |   * Multiply           |" << endl;
   cout << "   |   / Divide             |" << endl;
   cout << "   |   % Remainder          |" << endl;
   cout << "   |   Q Quit/terminate     |" << endl;
   cout << "   |                        |" << endl;
   cout << "   +========================+" << endl;
}

//----------------------------------------------------------------
// Read menu choice from keyboard.
//----------------------------------------------------------------
char MenuChoice()
{
   char menuChoice;
   cout << "\n   Enter Menu Choice: ";
   cin >> menuChoice;
   return menuChoice;
}


//----------------------------------------------------------------
// Read operands from keyboard.
//----------------------------------------------------------------
void Read_Operands(string Prompt, int & left, int & right)
{
   cout << Prompt;
   cin >> left >> right;
   cout << "\n";
}

//----------------------------------------------------------------
// Output labeled value.
//----------------------------------------------------------------
void DisplayLV(string Label, int value)
{
   cout << Label << value << endl;
}

void DisplayVL(ostream & oF, int value, string Label)
{
   oF << value << Label << endl;
   cout << "\n";
   cout << value << Label << endl;
}

void DisplayLV(ostream & S, string Label, int value)
{
	S << Label << value << endl;
}

void Display_BadChoice_Message(char choice)
{
   cout << "\nBAD MENU CHOICE" << "(" << choice << ")"; 
   cout << "... Retry\n";
   cout << endl;  
}

void Display_Termination_Message()
{
	cout << "\n\nintCalculator READY to terminate ... " << endl;
}

//----------------------------------------------------------------
// Arithmetic Functions.
//----------------------------------------------------------------
int Sum(int x, int b)
{
   return x + b;
}

int Quotient(int divisor, int dividend)
{ 
   if (dividend == 0)
  {
    return 0; 
  }

  else (dividend > 0);
  {
    return divisor / dividend;
  }
}

void Remainder(int dividend, int & r, int divisor) 
{  
   
   if (divisor == 0)
   {
     r = 0;  
   }
    
   else 
   {
     r = dividend % divisor;
   }

}
void Product( int & p, int a, int b)
{
	p = a * b;
}

int Diff( int m, int n)
{
	return m - n;
}

//----------------------------------------------------------------
// Output result of operation.
//----------------------------------------------------------------
void Output_Result(ostream & outF, int L, char op, int R, 
int result)
{
   outF << L << ' ' << op << ' ' << R << " = " << result;
   outF << endl;
   cout << L << ' ' << op << ' ' << R << " = " << result;
   cout << endl;
}

//----------------------------------------------------------------
// Log (record) the requested calculation.
//----------------------------------------------------------------
void Log_Request(ostream & recF, char op, int left, int right)
{
   recF << op << ' ' << left << ' ' << right << endl; 
}

int main()
{
   char menuChoice ='Q';    // Choice entered by user.

   int right,               // Right operand.
       left,                // Left operand.
       prod,                // Product of right and left operands.  
       rem,                 // Remainder of right and left operands.
       p,                   // Function parameter.
       r,                   // Function parameter.
       bmccount,            // Counter for bad menu choices.
       addcount,            // Counter for additions performed.
       subcount,            // Counter for subtractions performed.
       mulcount,            // Counter for multiplications performed.
       divcount,            // Counter for divisions performed.
       remcount,            // Counter for finding remainders.
	   calccount,           // Counter for all calculations performed.
	   result;              // Variable for 'sum' and 'diff' functions.

   ofstream oF("log_intCalculator.txt");  
   ofstream recF("requests.txt");  
   //-|---------------------------------------------------------------
   //-| 1. Display copyright.
   //-|---------------------------------------------------------------
   Display_Copyright("Asia Chatmon", "chatmonA020", 2023);
   //-|---------------------------------------------------------------
   //-| 2. Initialize counters. 
   //-|---------------------------------------------------------------
   bmccount = 0,
   addcount = 0,
   subcount = 0,
   mulcount = 0, 
   divcount = 0,
   remcount = 0,
   calccount = 0;
   //-|------------------------------------------------------------------
   //-| 3. Repeat the following (do-while):
   //-|    3.1 Display menu.
   //-|    3.2 Read menu choice.
   //-|    3.3 Perform menu choice.
   //-|        a) Count choice.
   //-|        b) Read operands (only for valid choices).
   //-|        c) Log the request
   //-|        d) Perform the calculation.
   //-|        e) Display the result.
   //-|    3.4 Log the request
   //-| UNTIL menu choice 'Q' is selected.
   //-|------------------------------------------------------------------
   do
   {
      Show_Menu();
	  menuChoice = MenuChoice();
      

       switch(menuChoice)
       {
          case '+' : 
		            Read_Operands("\n\nA: Enter left and right operands: ",
                     left, right);
                     result = Sum(left, right);
                     Output_Result(oF, left, '+', right, result); 
					 Log_Request(recF, '+', left, right);
                     addcount++;
					 calccount++;
		             break;

          case '-' :
                     Read_Operands("\n\nS: Enter left and right operands: ", 
                     left, right);
                     result = Diff(left, right);
                     Output_Result(oF, left, '-', right, result);
					 Log_Request(recF, '-', left, right);
                     subcount++;
					 calccount++;
                     break;

         case '*' :  Read_Operands("\n\nM: Enter left and right operands: ", 
                     left, right);
                     Product(p, left, right);
                     Output_Result(oF, left, '*', right, p);
					 Log_Request(recF, '*', left, right);
                     mulcount++;
					 calccount++;
                     break; 

          case '/' : Read_Operands("\n\nD: Enter left and right operands: ", 
                     left, right);
                     result = Quotient(left, right);  
                     Output_Result(oF, left, '/', right, result);
					 Log_Request(recF, '/', left, right);
                     divcount++;
					 calccount++;
                     break;

          case '%' : Read_Operands("\n\nR: Enter left and right operands: ", 
                     left, right);
                     Remainder(left, r, right);
                     Output_Result(oF, left, '%', right, r);
					 Log_Request(recF, '%', left, right);
                     remcount++;
					 calccount++;
                     break;                  

          case 'Q' : 
                     Display_Termination_Message();
                     break;       

          default:  
                    Display_BadChoice_Message(menuChoice);
                    bmccount++;  
                    break; 

       }//switch

   }
   while (menuChoice != 'Q');

  
   

   //-|--------------------------------------------------------------------
   //-| 4. Display session summaries (counts):
   //-|    a) Number of bad menu choices [ xx BAD MENU CHOICES]
   //-|    b) Number of adds:       [ + COUNT = xx ]
   //-|    c) Number of subtracts:  [ - COUNT = xx ]
   //-|    d) Number of multiplies: [ * COUNT = xx ]
   //-|    e) Number of divisions:  [ / COUNT = xx ]
   //-|    f) Number of remainders: [ % COUNT = xx ]
   //-|--------------------------------------------------------------------
   DisplayVL(oF, bmccount, " BAD MENU CHOICES\n");
 
   DisplayLV("+ COUNT = ", addcount);
   DisplayLV("- COUNT = ", subcount);
   DisplayLV("* COUNT = ", mulcount);
   DisplayLV("/ COUNT = ", divcount);
   DisplayLV("% COUNT = ", remcount);
   
   DisplayVL(oF, calccount, " CALCULATIONS ATTEMPTED\n");

   cout << "\nintCalculator TERMINATED" << endl;
   //-|---------------------------------------------------------------
   //-| Display copyright.
   //-|---------------------------------------------------------------
   Display_Copyright("Asia Chatmon", "chatmonA020", 2023);

   return 0;
}//main
