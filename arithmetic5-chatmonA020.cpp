#include <iostream>
#include <cmath>
using namespace std;

// ---------------------------------------------------------------------------
// File name:   arithmetic5.cpp
// Assign ID:   PROG7
// Due Date:    7/17/23 by 11 pm
// Purpose:     Transform PROG1 math5.cpp into program arithmetic5.cpp, which
//              does the same work, but must use functions.
// Author:      chatmonA020, Asia Chatmon
// ---------------------------------------------------------------------------


//*****************************************************************
//****** These functions are placed ABOVE the main. ***************
//*****************************************************************

// Function: Display copyright.
void DisplayCopyright(int year, string courseID, string Name)
{
  cout << "\n\n(c) " << year <<"," << ' ' << courseID << ' ' << Name 
       << endl << endl;
}//DisplayCopyright


// Function: Read ONE whole number after issuing a prompt.
int InputValue( string Prompt)
{
 int num;
 cout << "\n" << Prompt;
 cin >> num;
 return num;
}//InputValue


// Function: Display output label followed by value.
void DisplayLV( string Label, int value)
{
  cout << "\n" << Label << " =" << ' ' << value << endl;

}//DisplayLV

// Function: Display value followed by output label.
void DisplayVL( int num, string Label)
{
  cout << num << Label << endl;
}//DisplayVL

// Function: Compute the sum of two whole numbers.
int Sum2(int a, int b)
{
  return a + b;
}//Sum2

// Function: Compute difference between two whole numbers (p-q).
int Diff(int p, int q)
{
  return p - q;
}//Diff

// Function: Compute the product of THREE whole numbers.
int Product3( int x, int y, int z)
{
  return x * y * z;
}//Product3

// Function: Compute the quotient of dividend / divisor.
//           NOTE: Avoid dividing by zero; return 0 instead.
int Quotient( int dividend, int divisor)
{
  if (divisor > 0)
  {
    return dividend / divisor; 
  }

  else (divisor = 0);
  {
    return 0;
  }
}//Quotient

int main()
{

//-|----------------------------------------------------------------------
//-| Declare variables.
//-|----------------------------------------------------------------------
  int num1,                         // First number.
      num2,                         // Second number.
      num3,                         // Third number.
      num4,                         // Fourth number.
      num5,                         // Fifth number.
      sum,                          // Sum of all five numbers.
      prod,                         // Product of all five numbers.
      quo,                          // Quotient of the first and fifth 
                                    //numbers.
      diff;                         // Difference between the fourth and 
                                    // second numbers.
  
//-|----------------------------------------------------------------------
//-| Print the copyright notice to screen.
//-|----------------------------------------------------------------------
  DisplayCopyright(2023, "chatmonA020", "Asia Chatmon");

//-|----------------------------------------------------------------------
//-| 1. Read each of the five numbers.
//-|----------------------------------------------------------------------
  num1 = InputValue("ENTER first: ");

  num2 = InputValue("ENTER second: ");

  num3 = InputValue("ENTER third: ");

  num4 = InputValue("ENTER fourth: ");

  num5 = InputValue("ENTER fifth: ");


//-|----------------------------------------------------------------------
//-| 2. Display each of the input values.
//-|----------------------------------------------------------------------
  DisplayLV("FIRST value", num1);

  DisplayLV("SECOND value", num2);

  DisplayLV("THIRD value", num3);

  DisplayLV("FOURTH value", num4);

  DisplayLV("FIFTH value", num5);

  
//-|----------------------------------------------------------------------
//-| 3. Compute the sum of all five numbers using function Sum2.
//-|----------------------------------------------------------------------
  sum = Sum2(num1, num2);
  sum = Sum2(sum, num3);
  sum = Sum2(sum, num4);
  sum = Sum2(sum, num5);

//-|----------------------------------------------------------------------
//-| 4. Display the sum in form:  ALL SUM = x
//-|----------------------------------------------------------------------
  cout << "\nALL SUM = " << sum << endl;

//-|----------------------------------------------------------------------
//-| 5. Compute the product of all five numbers, using function Product3.
//-|----------------------------------------------------------------------
  prod = Product3(num1, num2, num3);
  prod = Product3(prod, num4, num5);

//-|----------------------------------------------------------------------
//-| 6. Display product in form:  xx = ALL PRODUCT
//-|----------------------------------------------------------------------
  cout << "\n" << prod << " = ALL PRODUCT" << endl;

//-|----------------------------------------------------------------------
//-| 7. Compute the quotient of the first number divided by the last number.
//-|----------------------------------------------------------------------
  quo = Quotient(num1, num5);

//-|----------------------------------------------------------------------
//-| 8. Display quotient in form:   QUOTIENT15 = xx
//-|----------------------------------------------------------------------
  cout << "\nQUOTIENT = " << quo << endl;

//-|----------------------------------------------------------------------
//-| 9. Compute the difference between the fourth number.
//-|----------------------------------------------------------------------
  diff = Diff(num4, num2);

//-|----------------------------------------------------------------------
//-| 10. Display the difference in the form: xx = DIFF42
//-|----------------------------------------------------------------------
  cout << "\n" << diff << " = DIFF42" << endl;

   return 0;
}//main


/*    

DELIVERABLES (what you must submit):

[1] Submit your source code to Canvas,  arithemtic5-xxxx.cpp, where xxxx is your course ID.
[2] Submit a 2-3 minute (MAX)  video named PROG7_Video-xxxx.mp4, where xxxx is your course login. Record the video using Zoom.  The video must show:

   1. You compiling and running your program.
   2. You showing your source file (no need to explain lines, but make sure I can see:
         - your header documentation.
         - function definitions.
         - Numbered algorithm steps.
         - function calls in the body of main.
   3. You using the self-grader to grade your program:
          Command:  ./gradeMy_arithmetic5.crun
   4. You, viewing your grading report file:  My_arithmetic5.cpp_gradingreport-xxxx.txt  (xxxx is your course ID).
*/

