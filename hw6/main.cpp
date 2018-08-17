#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string.h>
using namespace std;

void PrintStudent (Student**list, ofstream& outputfile, int x, string classname);

int main()
{
	int number_studs = 0; //holds number of students
	string filename; //string to hold filename
	string classname; //string to hold student info
	string fname; 
	string lname;
	ifstream inputfile;
	ofstream outputfile; //declare files
	 int g1=0; //stores grades
	int g2=0;
	int g3=0;
	int g4=0;
	int g5=0;
	int g6=0;
	int g7=0;
	int g8=0;



	cout << "Please enter the name of the input file. \n Filename:";
	cin>>filename;
	inputfile.open(filename.c_str());
	
	while(!inputfile.is_open())
	{
		cout << "Could not open file. Please try again: ";
		cin>>filename;
		inputfile.clear();
		inputfile.open(filename.c_str() );
	}
	
	cout << "Please enter the name of the output file. \n Filename:";
	cin >> filename;
	outputfile.open(filename.c_str() );
	
	while(!outputfile.is_open())
	{
		cout <<"Could not output file. Pleasse try again: ";
		cin >> filename;
		outputfile.clear();
		outputfile.open(filename.c_str());
	}
		
	inputfile >>number_studs;
	
	Student** list = new Student*[number_studs];
	
	for (int i=0;i<number_studs; i++)
	{
	getline(inputfile, lname, ',');
	getline(inputfile, fname, '\n');
	getline(inputfile,classname, ' ');
	cout << endl;

        if (classname[0]== 'H')
        {
                cout << "History" << endl;
                list[i] = new History(fname,lname,classname, g1 ,g2, g3, g4);                 
        }
        if (classname[0]=='M')
        {
                cout << "Math" << endl;
                list[i] = new Math(fname,lname,classname, g1, g2, g3, g4, g5, g6, g7, g8); 
        }
        if (classname[0]=='E')
        {
                cout << "English" << endl;
                list[i] = new English(fname,lname, classname, g1, g2, g3);
        }

	}
	int x=0;//sets x for switch statement
	if (classname=="History")
		x=1;
	if (classname=="Math")
		x=2;
	if (classname=="English")
		x=3;
		
	switch(x)
	{//uses switch to determine which class it is
		case 1:
			inputfile >> g1 >> g2 >> g3;
			cout << g1 << g2 << g3 << endl;
			break;
		case 2:
			inputfile >>g1>>g2>>g3>>g4>>g5>>g6>>g7>>g8;
			cout <<g1<<g2<<g3<<g4<<g5<<g6<<g7<<g7;
			break;
		case 3:
			inputfile >>g1>>g2>>g3>>g4;
			cout <<g1<<g2<<g3<<g4;
			break;
	}	
int acount=0,bcount=0,ccount=0,dcount=0,fcount=0;
 if (FinalAvg()>89.0)
                acount++;
        if (FinalAvg()>79.0)
                bcount++;
        if (FinalAvg()>69.0)
                ccount++;
        if (FinalAvg()>59.0)
                dcount++;
        if (FinalAvg()>0)
                fcount++;
	
	inputfile.close();

	//calls function to print students info
	PrintStudent(list, outputfile, number_studs, "English");
	outputfile <<endl;
	PrintStudent(list, outputfile, number_studs, "Math");
	outputfile <<endl;
	PrintStudent(list, outputfile, number_studs, "History");
	outputfile << endl;
	int Gradecount();//calls to distribute grades
	outputfile <<"OVERALL GRADE DISTRIBUTION\n\n";
	outputfile << "A: " << acount <<endl << "B: " <<bcount<<endl;
	outputfile << "C: " << ccount <<endl << "D: " <<dcount <<endl;
	outputfile << "F: " << fcount<<endl<< endl ;
//delete dynamically allocated array
delete [] list;		

return 0;
}

void PrintStudent (Student** list, ofstream& outputfile, int x, string classname)
{ 

//prints students info, outputs finalex, avg, and lettergrade
outputfile << "Student Grade Summary\n"
	   << "--------------------\n";

for (int i=0; i<x;i++)
{
	if (list[i]->Course()== "English")
	{
	        outputfile <<"English Class" <<endl;
	        outputfile <<"Student              Final\t"    
                <<"Final    Letter\n"
                <<"Name                 Exam\t"     
                <<"Avg      Grade\n"
	<<"---------------------------------------------\n";
	   outputfile<< fixed << showpoint << setprecision(2)
         << list[i]->FName()<<" "<< list[i]->LName()
         <<setw(17)<< left << setw(8)<< list[i]->FinalExam()
         <<setw(8)<< list[i]->FinalAvg() 
        << list[i]->FinalGrade(output)<<endl << endl << endl;

	}
	if (list[i]->Course()=="History")
	{
	outputfile<<"History Class" <<endl;
	   outputfile <<"Student              Final\t"    
                <<"Final    Letter\n"
                <<"Name                 Exam\t"     
                <<"Avg      Grade\n"
	<<"---------------------------------------------\n";
	    outputfile<< fixed << showpoint << setprecision(2)
         << list[i]->FName()<<" "<< list[i]->LName()
         <<setw(17)<< left << setw(8)<< list[i]->FinalExam()
         <<setw(8)<< list[i]->FinalAvg() 
        << list[i]->FinalGrade()<<endl << endl << endl;

	}
	if (list[i]->Course()=="Math")
	{
		outputfile<<"Math Class" <<endl;
	        outputfile <<"Student              Final\t"    
                <<"Final    Letter\n"
                <<"Name                 Exam\t"     
                <<"Avg      Grade\n"
	<<"---------------------------------------------\n";

       	 outputfile<< fixed << showpoint << setprecision(2)
         << list[i]->FName()<<" "<< list[i]->LName()
         <<setw(17)<< left << setw(8)<< list[i]->FinalExam()
         <<setw(8)<< list[i]->FinalAvg() 
	<< list[i]->FinalGrade(output)<<endl << endl << endl;
	}


}
}
