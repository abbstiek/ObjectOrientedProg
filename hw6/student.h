#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 
#include <cctype>
using namespace std;

class Student
{
public:
	Student(string fn, string ln, string cn);
	string Course(); //takes coursename
	virtual double FinalAvg()=0; //used in each class, formula
	virtual int FinalExam()=0;//calculated in each class
	string FName();//firstname
        string LName();//lastname
	char FinalGrade(ofstream& output); //char for letter grade
	int finalgrade; //determines final grade in class
	int total;
	int Gradecount();
protected:
	string fname, lname,classname; //to hold string values
};

class English: public Student
{
public:
	English (string, string, string, int, int, int); //holds info and grads
private:
	double FinalAvg(); //part of virtual double
	int TermPaper; //grades
	int Midterm;
	int FinalExam(); //returns grade
	int finalexam; //int to hold final exam grade
	int total; //total grade
};

class History: public Student
{
public:
	History(string, string, string, int, int, int, int); //holds info
//and grades

private:
	double FinalAvg(); //virtual double, returns avg
	int Attendance; //grades
	int Project;
	int Midterm;
	int FinalExam(); //returns grade, virtual
	int finalexam; //holds grade
	int total; 
};

class Math: public Student
{
public: //holds math student info and grades
	Math(string, string, string, int, int, int, int, int, int, int, int);
private:
	double FinalAvg(); //virtual double, returns avg
	double QuizAvg(); //adds all quiz grades for average
	int grade1, grade2, grade3, grade4, grade5; //added for average
	int Test1;//grades
	int Test2;
	int FinalExam(); //virtual
	int finalexam; //returned grade
	int total;
};
