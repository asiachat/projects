//---------------------------------------------------------------------------
// File name:   myCar.cpp
// Assign ID:   PROG2
// Due Date:    May 27, 2023
//
// Purpose:     Perform series of calculations pertaining to car trips.
//
// Author:      chatmonA020 Asia Chatmon 
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   //----------------------------------------------------------------------
   //  Declare variables
   //----------------------------------------------------------------------
   string Driver,  // First name of driver.
           Make ,  // Make of car.
           Color;  // Color of car.
   float MPG;      // Miles per gallon.

   float Dist,     // Distance in miles.
         Time,     // Time of travel in hours.
         Speed,    // Miles per hour.
         gasUsed,  // Gallons used.
         gasCost,  // Cost of gas in dollars.
         PPG,      // Price per gallon.
         NOG,      // Number of gallons.
         costPerMile;  // Dollars per mile traveled.

   //-|----------------------------------------------------------------------
   //-|Print the copyright notice, to screen.
   //-|----------------------------------------------------------------------
   cout << endl << "(c) 2023, chatmonA020 Asia Chatmon" << endl << endl; 
   cout << fixed << showpoint << setprecision(2);    // DO NOT DELETE

   //-|----------------------------------------------------------------------
   //-| 0. Read values for driver, make, color and MPG.
   //-|----------------------------------------------------------------------
   cout << "\n Enter first name of driver, make of car, color and MPG "
        << "(separated by spaces):";
   cin >> Driver >> Make >> Color >> MPG;
   cout << endl << " [0] " << Driver << " drives a " << Color << " " << Make 
        << " that gets " << MPG << " MPG." << endl;

   //-|----------------------------------------------------------------------
   //-| 1. Calculate and output Speed [Speed], given inputs distance [Dist], 
   //-|    time [Time].
   //-|----------------------------------------------------------------------
   cout << "\n Enter distance traveled and time taken.";
    cin >> Dist >> Time;
    Speed = Dist / Time;
    cout << endl << " [1] To drive the " << Make << " " << Dist << " miles in "
         << Time << " hours requires speed of " << Speed << " mph. " << endl;    

   //-|----------------------------------------------------------------------
   //-| 2. Calculate and output Time, given inputs speed and distance.
   //-|----------------------------------------------------------------------
   cout << "\n Enter speed and distance traveled.";
   cin >> Speed >> Dist;
   Time = Dist / Speed;
   cout << endl << " [2] It takes " << Time << " hours to drive the " << Color 
        << " car " << Dist << " miles at " << Speed << " mph. " << endl;

   //-|----------------------------------------------------------------------
   //-| 3. Calculate and output gallons of Gas used [gasUsed], given input
   //-|    distance.
   //-|----------------------------------------------------------------------
   cout << "\n Enter distance traveled and miles per gallon.";  
   cin >> Dist >> MPG;
   gasUsed = Dist / MPG;
   cout << endl << " [3] The " << Make << " uses " << gasUsed << " gallons of"
        " gas to travel " << Dist << " miles. " << endl; 

   //-|----------------------------------------------------------------------
   //-| 4. Calculate and output Gas cost [gasCost], given inputs price per
   //-|    gallon and number of gallons.
   //-|----------------------------------------------------------------------
   cout << "\n Enter price per gallon and number of gallons.";
   cin >> PPG >> NOG;
   gasCost = PPG * NOG;
   cout << endl << " [4] At $" << PPG << " per gallon, it costs $" << gasCost 
        << " to add " << NOG << " gallons of gas to the " << Make << "." 
        << endl;

   //-|----------------------------------------------------------------------
   //-| 5. Calculate and output Gas cost, given inputs distance and price per
   //-|    gallon.
   //-|----------------------------------------------------------------------
   cout << "\n Enter distance traveled, price per gallon and miles per gallon.";
   cin >> Dist >> PPG >> MPG;
   gasCost = PPG * (Dist/MPG);
   cout << endl << " [5] When gas price is $" << PPG << "/gal, the cost of gas "
       "to drive the " << Make << " " << Dist << " miles is $" << gasCost << "."
       << endl;

   //-|----------------------------------------------------------------------
   //-| 6. Calculate and output Gas cost, given inputs speed, time, and price
   //-|    per gallon.
   //-|----------------------------------------------------------------------
   cout << "\n Enter speed traveled, time taken, price per gallon and miles" 
           " per gallon.";
   cin >> Speed >> Time >> PPG >> MPG;
   gasCost = (Speed * Time) / (MPG * PPG);
   cout << endl << " [6] " << Driver << " must purchase $" << gasCost
        << " of gas to drive " << Time << " hours at " << Speed << " mph, when" 
       " gas costs $" << PPG << "/gal. " << endl;

   //-|----------------------------------------------------------------------
   //-| 7. Calculate and output Distance, given input gallons used.
   //-|----------------------------------------------------------------------
   cout << " \n Enter the amount of gallons used and miles per gallon.";
   cin >> gasUsed >> MPG;
   Dist =  gasUsed * MPG;
   cout << endl << " [7] The " << Make << " uses " << gasUsed << " gallons of gas" 
        " to travel " << Dist << " miles. " << endl;

   //-|----------------------------------------------------------------------
   //-| 8. Calculate and output Cost per mile [costPerMile], given inputs
   //-|    gallons used, and price per gallon [PPG].
   //-|----------------------------------------------------------------------
   cout << "\n Enter the amount of gallons used, price per gallon and miles" 
           " per gallon.";
   cin >> gasUsed >> PPG >> MPG;
   costPerMile = (gasUsed * PPG) / (gasUsed * MPG);
   cout << endl << " [8] The " << Color << " " << Make << " used " << gasUsed 
        << " gallons of gas, at $" << PPG << " per gallon. The cost per mile is" 
        " $" <<  costPerMile << ". " << endl;

   //-|----------------------------------------------------------------------
   //-|Print the copyright notice to monitor.
   //-|----------------------------------------------------------------------
   cout << endl << endl << "(c) 2023, chatmonA020 Asia Chatmon" << endl << endl; 

   return 0;

}//main
