//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_FIELD_H
#define HOMEWORK_4_0_FIELD_H


#include <iostream>
#include <vector>
#include <iterator>
#include "Converters.hpp"
#include "data.h"
#include "time.h"
//#include "FieldTemplate.hpp"
using namespace std;


class Field {
public:
	template <typename U>
	void getIterator(typename vector<U>::iterator& it1, typename vector<U>::iterator& it2){};
	template <typename U>
	void getIterator(typename vector<U>::iterator& it, int i){};



	Field() {};

	virtual ~Field() {};

	virtual int getType() {
		return 0; //bor solo un default
	};

	virtual void addElem(const int& elem_to_add){};
	virtual void addElem(const float& elem_to_add){};
	virtual void addElem(const char& elem_to_add){};
	virtual void addElem(const string& elem_to_add){};
	virtual void addElem(const Date& elem_to_add){};
	virtual void addElem(const Time& elem_to_add){};

	void setAutoIncr();
	void setNotNull();
	bool getAutoIncr();
	bool getNotNull();

	virtual string getElem(int i){};

	virtual void autoIncrementer(const int pos){};

	void deleteElem(){}

private:

	bool _notnull = false;
	bool _autoincr = false;

};


#endif //HOMEWORK_4_0_FIELD_H
