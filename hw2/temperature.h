class Temperature
{
public:
	//constructor 
	Temperature (double, char);
	Temperature ();
	//member functions
	void Input();
	void Show() const;
	bool SetScale (char);
	double GetDegrees() const;
	char GetScale() const;
	bool SetFormat (char);
	void Convert (char);
	int Compare (Temperature& d);
	void Increment (int, char);
private:
	char scale;
	double degree;
	char format;
};



