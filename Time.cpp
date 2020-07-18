//
// Created by Riccardo Carità on 25/06/2020.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"

Time::Time() {
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	_h = now->tm_hour;
	_m = now->tm_min;
	_s = now->tm_sec;
}

Time::Time(int h, int m, int s) {
	if(h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0)
		throw(timeError());

	_h = h;
	_m = m;
	_s = s;
}

Time::Time(const string& stringTime){
	string s = stringTime;
	string hour = s.substr(0,s.find(":"));
	string minute = s.substr(1,s.find(":"));
	string second = s.substr(2,s.find(":"));
}

string Time::str() const {
	return to_string(_h) + ":"
		   + to_string(_m) + ":"
		   + to_string(_s);
}

int Time::getHour() const {
	return _h;
}

int Time::getMinute() const {
	return _m;
}

int Time::getSecond() const {
	return _s;
}

void Time::setHour(int h) {
	if(h < 0 || h > 23)
		throw timeError();
	_h = h;
}

void Time::setMinute(int m) {
	if(m < 0 || m > 59)
		throw timeError();
	_m = m;
}

void Time::setSecond(int s) {
	if(s < 0 || s > 59)
		throw timeError();
	_s = s;
}

void Time::operator=(const Time &t2) {
	_h = t2._h;
	_m = t2._m;
	_s = t2._s;
}

ostream &operator<<(ostream &stream, const Time &t) {
	stream << t.str();
	return stream;
}

exception Time::timeError() {
	cerr << "Wrong time format" << endl;
	return exception();
}

Time::Time(const Time &to_copy) {
	_h = to_copy.getHour();
	_m = to_copy.getMinute();
	_s = to_copy.getSecond();
}
