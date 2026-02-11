// Define a class invariant
// Check and provide the invariant
// Define operators +, +=
// Examine the compiler warnings
class Time
{
private:
	int _hours;
	int _minutes;
	int _seconds;

	void normalizeTime();
	
public:
	static const double hourToDec;
	// finalise the constructor
	Time(int s = 0, int m = 0, int h = 0) :_hours(h), _minutes(m), _seconds(s) {}
	Time (const Time& t):_hours(t._hours), _minutes(t._minutes), _seconds(t._seconds) {}
	~Time(){};

	Time& operator=(const Time&);
	operator int() const {
		return _seconds + _minutes * 60 + _hours * 3600;
	}
	//operator double() const;

	int hours() const {return _hours;}
	int minutes() const {return _minutes;}
	int seconds() const {return _seconds;}

	// change modifiers
	int& hours() {return _hours;}
	int& minutes() {return _minutes;}
	int& seconds() {return _seconds;}
};