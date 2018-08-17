#include "student.h"
Student::Student (string fn, string ln, string cn)
{
	fname=fn;
	lname=ln;
	classname=cn;
}

English::English (string fname, string lname, string classname, int tp,int mt,int fe) 
: Student(fname,lname,classname)
{
 	TermPaper=tp;
	Midterm=mt;
	finalexam=fe;
}

History::History(string fname, string lname, string classname, int at, int p, int mt2, 
int fe2) 
: Student (fname, lname, classname)
{
	Attendance=at;
	Project=p;
	Midterm=mt2;
	finalexam=fe2;
}

Math::Math(string fname, string lname, string classname, int g1, int g2, int g3, int 
g4, int g5, int t1, int t2, int fe3) : Student (fname, lname, classname)
{
	grade1=g1;
	grade2=g2;
	grade3=g3;
	grade4=g4;
	grade5=g5;
	Test1=t1;
	Test2=t2;
	finalexam=fe3;
}
double Math::QuizAvg()
{
	double QuizAvg=0.0;
	QuizAvg=grade1+grade2+grade3+grade4+grade5;
	QuizAvg=QuizAvg/5;
	return QuizAvg;
}

double English::FinalAvg()
{ //returns 
	 const double ter=.25, mid=.35, fin= .4;
	return ((TermPaper*ter)+(Midterm*mid)+(finalexam*fin));
}

double Math::FinalAvg()
{
 const double qui=.15, tes1=.25, tes2=.25, fin=.35;
	return ((QuizAvg()*qui)+(Test1*tes1)+(Test2*tes2)+(finalexam*fin));
}

double History::FinalAvg()
{
const double att=.1,pro=.3, mid=.3, fin=.3;
	return ((Attendance*att)+(Project*pro)+(Midterm*mid)+(finalexam*fin));
}

char Student::FinalGrade(ofstream& outputfile)
{
char grade;
        {//sets number grade to letter grade
        if (FinalAvg()>89.0)
                outputfile<<'A';
        if (FinalAvg()>79.0)
                outputfile<<'B';
        if (FinalAvg()>69.0)
                outputfile<<'C';
        if (FinalAvg()>59.0)
                outputfile<<'D';
        if (FinalAvg()>0)
                outputfile<<'F';
        }
return grade;
}


string Student::Course()
{
	return classname;
}

string Student::FName()
{
	return fname;
}

string Student::LName()
{
	return lname;
}


int History::FinalExam()
{
	return finalexam;	
}

int Math::FinalExam()
{
	return finalexam;
}

int English::FinalExam()
{
	return finalexam;
}
