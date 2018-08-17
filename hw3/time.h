using namespace std;

class Time
{
        friend std::ostream& operator <<(ostream& os, const Time& t1);
        friend std::istream& operator >>(istream& is, Time& t1);
        friend Time operator+(const Time& t1, const Time& t2);
        friend Time operator-(const Time& t1, const Time& t2);
        friend Time operator*(const Time& t1, int);
        friend bool operator<(const Time& t1, const Time& t2);
        friend bool operator>(const Time& t1, const Time& t2);
        friend bool operator<=(const Time& t1, const Time& t2);
        friend bool  operator>=(const Time& t1, const Time& t2);
        friend bool operator==(const Time& t1, const Time& t2);
	friend int Check (const Time& t1);
        friend bool operator!=(const Time& t1, const Time& t2);
public:
	Time();
	Time(int);
	Time(int, int, int, int);
	Time& operator++();
	Time operator++(int);
	Time& operator --();
	Time operator--(int);
private:
	friend int FixTime ();
	int days;
	int hours;
	int minutes; 
	int seconds;
        void Convert();
        void Convert(int, int, int, int);
	void DefaultTime();
};

