//------------------------------------------------------------------
// File name:   standing.cpp
// Assign ID:   PROG5
// Author:      chatmonA020 Asia Chatmon
//
// Purpose:     Read student data from input file, reformat data and
//              compute the average GPA and weighted (by cumHours) GPA.
//
// Input Line:  ID Firstname Lastname MiddleInit Courseload CumHours GPA 
//
//
// Sample Output:  
//
//       ACADEMIC STANDING REPORT
//
//       1234bb123456789bb1234bb12345bbb1234567890123bb      (yardstick)
//       ====  =========  ====  =====   =============  ========================
//        GPA  StudentID  Load  Hours   Standing       Student_Name
//       ====  =========  ====  =====   =============  ========================
//       2.52  143841138    18    112   GOOD STANDING  Jones, Edward L
//       ====  =========  ====  =====   =============  ========================
//       Number of Students =  1
//       12bxxxxxxxxxxxxxxxxxxxxxxxxx    (yardstick)
//        1 Students in Good Standing
//        1 Students On Probation
//        1 Honors Students
//
//-------------------------------------------------------------------
// 
//       STUDENT GPA REPORT
//
//       1234xx123456789xx1234xx12345xxx123456789012345678901234 (yardstick)
//       ====  =========  ====  =====   ========================
//        GPA  StudentID  Load  Hours   Student_Name
//       ====  =========  ====  =====   ========================
//       2.52  143841138    18    112   Jones, Edward L
//       ====  =========  ====  =====   ========================
//       Number of Students =  1
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{

   // -----------------------------------------------------------
   // Declare input stream, studF, connecting file 'students.dat'.
	// -----------------------------------------------------------
      ifstream studF("students.dat");    // Input file stream 
                                          //   connected to file
                                          //    "students.dat";

   // -----------------------------------------------------------
   // Declare output streams:
	//    1) reportF, connecting to output file 'students.rpt'.
	//    2) rejectF, connecting to output file 'rejected.txt'.
	// -----------------------------------------------------------
      ofstream reportF("students.rpt"),   // Output file stream 
                                          // connected to file
                                          // "students'rpt."

               rejectF("rejected.txt");   // Output file stream
                                          // connected to file 
                                          // "rejected.txt."

   // -----------------------------------------------------------
   // Declare input variables for student data.
   // -----------------------------------------------------------
      string firstname,     // Student's first name.
      lastname,             // Student's last name. 
      middleinit;           // Student's middle initial.

      float gpa;            // Student's grade point average.

      int courseload,       // Total credit hours.
          cumhours,         // Cumulative hours.
          id;               // Student ID.


   // -----------------------------------------------------------
   // Declare counters and sums.
   // -----------------------------------------------------------
   int goodcount,           // Amount of students in good standing.
       probationcount,      // Amount of students on probation. 
       honorscount,          // Amount of honors students.
       students;            // Number of students reported.

   // -----------------------------------------------------------
   // Declare calculation variables student data.
   // -----------------------------------------------------------
   string Standing;      // Standing: "HONORS"  or "GOOD STANDING"
                         //           or "ON PROBATION"-

   
   //-|-----------------------------------------------------------
   //-| Display copyright notice ON SCREEN only..
   //-|-----------------------------------------------------------
   cout << "(c) 2023, chatmonA020 Asia Chatmon" << endl << endl;
   
   
   //-|-----------------------------------------------------------
   //-| 1. Open output files.
   //-|-----------------------------------------------------------


   //-|-----------------------------------------------------------
   //-| 2. Check that input file has been opened. On failure, 
   //-|    display error message
   //-|
   //-|        FATAL ERROR .. can not open input file 'students.dat'.
   //-|
   //-|    and terminate program.
   //-|-----------------------------------------------------------
   ifstream datafile;
   datafile.open("students.dat");
   //-| Terminate if unable to open file.
   if (datafile.fail())
   {
	   cout << "FATAL ERROR .. can not open file 'students.dat'.\n";
	   exit(1);
   }


   //-|-----------------------------------------------------------
   //-| 3. Initialize all counters to zero. 
   //-|-----------------------------------------------------------
       goodcount =0,
       probationcount =0,
	   honorscount =0,
       students =0;

   //-|-----------------------------------------------------------
   //-| 4. Write GPA REPORT headings to report file.
   //-|-----------------------------------------------------------
   reportF << "STUDENT GPA REPORT" << endl;
   reportF << "====  =========  ====  =====   ===================="
           << "====" << endl;
   reportF << " GPA  StudentID  Load  Hours   Student_Name" << endl;
   reportF << "====  =========  ====  =====   ====================="
           << "===" << endl;

   //-|-----------------------------------------------------------
   //-| 5. Write ACADEMIC STANDING REPORT headings to screen.
   //-|-----------------------------------------------------------
   cout << "ACADEMIC STANDING REPORT" << endl << endl;
   cout << "====  =========  ====  =====   =============  ========"
        << "================" << endl;
   cout << setw(6) << left << "GPA" << setw(11) << "StudentID" 
        << setw(6) << left << "Load " << setw(8) << left << "Hours" 
		<< setw(11) << left << setw(15) << "Standing" << left 
		<< setw(15) << "Student_Name" << endl;
   cout << "====  =========  ====  =====   =============  ========"
        << "================" << endl;
   

   //-|-----------------------------------------------------------
   //-| 6. Read student data.
   //-|-----------------------------------------------------------
   studF >> id >> firstname >> lastname >> middleinit >> courseload 
         >> cumhours >> gpa;
         

   //-|-----------------------------------------------------------
   //-| 7. If GPA is bad:
   //-|    7.1 Write input data to file 'rejected.txt'
   //-|    7.2 Display message: BAD GPA (x.xx).
   //-|    7.3 Exit the program -- exit(2).
   //-|-----------------------------------------------------------
   if (gpa < 0.0 || gpa > 4.0)
   {
       rejectF << id << ' ' << firstname << ' ' << lastname << ' ' 
       << middleinit << ' ' << courseload << ' ' << cumhours << ' ' 
       << gpa << endl;

               cout << "BAD GPA (" << gpa << ") ... TERMINATING" << endl;
               exit(2);
   }

   //-|-----------------------------------------------------------
   //-| 8 Output student record to GPA report.
   //-|-----------------------------------------------------------
   reportF << gpa << setw(11) << right << id 
           << setw(6) << right << courseload << setw(7) << right 
           << cumhours << setw(10) << right << middleinit << ", " 
           << firstname << ' ' << lastname << endl;
   reportF << "====  =========  ====  =====   ===================="
           << "====" << endl;        

   //-|-----------------------------------------------------------
   //-| 9. DETERMINE status of student. 
   //-|    9.1 if GPA >= 3.0 
   //-|          Standing = "HONORS"
   //-|          honorsCount++ 
   //-|    9.2 otherwise,  if GPA < 2.0
   //-|          Standing = "ON PROBATION"
   //-|          probationCount++ 
   //-|    9.3 otherwise,  
   //-|          Standing = "GOOD""
   //-|          goodCount++ 
   //-|-----------------------------------------------------------
   if (gpa >= 3.0)
   {
       Standing = "HONORS",
       honorscount++;
   }

   else if (gpa < 2.0)
   {
       Standing = "ON PROBATION",
       probationcount++;
   }

   else (gpa > 2.1 || gpa < 2.9);
   {
       Standing = "GOOD STANDING",
       goodcount++;
   }
   //-|-----------------------------------------------------------
   //-| 10. Display standings record to Standing Report (screen).
   //-|-----------------------------------------------------------
   cout << gpa << setw(11) << right << id 
        << setw(6) << right << courseload << setw(7) << right 
        << cumhours << setw(16) << right << Standing << setw(9)
        << right << middleinit << ", " << firstname << ' ' 
        << lastname << endl;
   cout << "====  =========  ====  =====   =============  ========"
        << "================" << endl;    

   //-|-----------------------------------------------------------
   //-| 11. Write statistics to GPA Report file.
   //-|-----------------------------------------------------------
   //-|    - Number of Students 
   //-|-----------------------------------------------------------
   reportF << "Number of Students = " << students++ << endl;

   //-|-----------------------------------------------------------
   //-| 12. Write statistics to Academic Standings report (screen).
   //-|-----------------------------------------------------------
   //-|    - Number of Students 
   //-|    - #Students in Good Standing
   //-|    - #Students On Probation
   //-|    - #Honors Students   
   //-|-----------------------------------------------------------
   cout << "Number of Students = " << students++ << endl;
   cout << honorscount++ << " Honors Students" << endl;
   cout << goodcount++ << " Students in Good Standing" << endl;
   cout << probationcount++ << " Students on Probation" << endl;

   //-|-----------------------------------------------------------
   //-| 13. Write copyright notice to GPA report file..
   //-|-----------------------------------------------------------
   reportF << "(c) 2023, chatmonA020 Asia Chatmon" << endl << endl;

   //-|-----------------------------------------------------------
   //-| 14. Close all files.
   //-|-----------------------------------------------------------
   


   cout << endl;
   return 0;
}//main	

