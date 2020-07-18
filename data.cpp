//
// Created by Alessandro on 2019-04-12.
//
#define _CRT_SECURE_NO_WARNINGS


#include "data.h"
Date::Date() {
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	_day = now->tm_mday;
	_month = now->tm_mon + 1;
	_year = now->tm_year + 1900;
}

Date::Date(const string& stringDate){
	string delimiter="/";
	const char* s = stringDate.c_str();
	/*size_t pos = 0;
	string tokens[3];
	int i = 0;
	while((pos = s.find(delimiter)) != std::string::npos){
		tokens[i] = s.substr(0, pos);
		//cout << tokens[i] << endl;
		s.erase(0, pos + delimiter.length());
		++i;
	}*/
	sscanf(s , "%2d/%2d/%4d", &_day, &_month, &_year);

	/*string day = tokens[0];
	string month = tokens[1];
	string year = tokens[2];*/
	cout << "la data è" << _day << _month << _year;

	try{
		if(sizeof(_day)/sizeof(int)>2 || sizeof(_month)/sizeof(int)>2 || sizeof(_year)/sizeof(int) != 4){
			throw "Wrong size of input date parameters";
		}
	}
	catch(char const* err){
		cerr << err <<endl;
	}

	/*try {

		_day = stoi(day);
		_month = stoi(month);
		_year = stoi(year);
	}
	catch(exception& e){
		cerr << "standard exception: "<< e.what();
	}*/

}

Date::Date(const Date &to_copy) {
	*this = to_copy;
}

Date::Date(const int &d, const int &m, const int &y) {
	_day = d;
	_month = m;
	_year = y;
}

int Date::day() const {
	return _day;
}

int Date::month() const {
	return _month;
}

int Date::year() const {
	return _year;
}
int Date::yearsFrom(const Date &d) const {
	return _year - d._year;
}

std::string Date::str() const {
	ostringstream stream;

	stream 	<< setfill('0') << setw(2) << _day << "/"
			<< setfill('0') << setw(2) << _month << "/"
			<< setfill('0') << setw(4) << _year;
	return stream.str();
}

Date& Date::operator=(const Date &to_assign) {
	_day = to_assign._day;
	_month = to_assign._month;
	_year = to_assign._year;
	return (*this);
}

bool Date::operator==(const Date &to_compare) const {
	return ((_day == to_compare._day) &&
			(_month == to_compare._month) &&
			(_year == to_compare._year));
}

bool Date::operator!=(const Date &to_compare) const {
	return !(*this == to_compare);
}

Date Date::operator+(const Date &to_add) const {
	Date ret(to_add);
	ret._day += _day;
	ret._month += _month;
	ret._year += _year;
	return ret;
}
ostream& operator<< (ostream& stream, const Date& d) {
	stream << d.str();
	return  stream;
}

exception Date::dateError() {
	cerr << "Wrong date syntax" << endl;
	return exception();
}
