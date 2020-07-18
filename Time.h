//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_TIME_H
#define HOMEWORK_4_0_TIME_H


#include <iostream>
#include <ctime>
#include "Converters.hpp"

using namespace std;

class Time {

public:
	Time();
	Time(int h, int m, int s);

	Time(const string& stringTime);
	Time(const Time& to_copy);
	std::string str() const;

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	void operator= (const Time & to_assign);
	friend ostream& operator<< (std::ostream& stream, const Time& t);

	exception timeError();

private:

	int _h, _m, _s;

};



#endif //HOMEWORK_4_0_TIME_H
