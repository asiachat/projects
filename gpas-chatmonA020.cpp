//----------------------------------------------------------------------------
//File name:   myGPA.cpp
//Assign ID:   PROG3 
//Due Date:    06/03/2023
//
//Purpose:     Performing calculation of GPA.
//
//Author:      chatmonA020 Asia Chatmon
//----------------------------------------------------------------------------
//------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   //-------------------------------------------------------------------------
   // Declare variables, ONE PER LINE, with comment.
   //-------------------------------------------------------------------------
   string Student_FULL_Name;   // The student's first, middle and last name.

   int studentID,              // The student's ID number.
       nA,                     // Number of As earned.
       nB,                     // Number of Bs earned.
       nC,                     // Number of Cs earned.
       nD,                     // Number of Ds earned.
       nF,                     // Number of Fs earned.
       Courses,                // Number of courses taken.
       Hours,                  // Number of credit hours taken.
	   studnum,                // Number of students.
       var=0;                  // Random variable.  

   float GPA;                  // Grade Point Average.
  
   ifstream studgrades("grades.dat"); // Input file for student grades.

   //-|-----------------------------------------------------------------------
   //-| 0. Display the copyright notice declaring authorship.
   //-|-----------------------------------------------------------------------
   cout << "(c) 2023, chatmonA020 Asia Chatmon" << endl << endl << endl; 
   cout << showpoint << fixed << setprecision(2);


   //-|-----------------------------------------------------------------------
   //-| 1. Read inputs.
   //-|-----------------------------------------------------------------------
   cout << "Enter #students: "; 
   cin >> studnum;
   for(int var=1; var<=studnum; var++)
   {

   studgrades >> nA >> nB >> nC >> nD >> nF >> studentID;
   getline(studgrades, Student_FULL_Name);


   //-|-----------------------------------------------------------------------
   //-| 2. PROCESS(P) SECTION: Perform calculation(s).
   //-|-----------------------------------------------------------------------
   GPA = (4.0*nA + 3.0*nB + 2.0*nC + 1.0*nD + 0.0*nF) / (nA+nB+nC+nD+nF);
   Courses = (nA+nB+nC+nD+nF);
   Hours = (nA+nB+nC+nD+nF) * 3;


   //-|-----------------------------------------------------------------------
   //-| 3. OUTPUT(O) SECTION: Display outputs. 
   //-|-----------------------------------------------------------------------
   cout << endl << "      ===========================================" << endl;
   cout << "      STUDENT ID: " << studentID << endl;
   cout << "      STUDENT NAME:" << Student_FULL_Name << endl << endl;
   cout << "      LETTER GRADE: A -> " << nA << endl; 
   cout << "                    B -> " << nB << endl;
   cout << "                    C -> " << nC << endl;
   cout << "                    D -> " << nD << endl;
   cout << "                    F -> " << nF << endl << endl;
   cout << "      " << Courses << " COURSES TAKEN" << endl;
   cout << "      " << Hours << " HOURS TAKEN" << endl;
   cout << "      STUDENT GPA = " << GPA << endl;
   cout << "      ===========================================" << endl;
   
   }

   //-|-----------------------------------------------------------------------
   //-| 5. Display the copyright notice declaring authorship again.
   //-|-----------------------------------------------------------------------
   cout << "\n\n(c) 2023, chatmonA020 Asia Chatmon" << endl << endl; 


   return 0;

}//main

