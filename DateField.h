//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_DATEFIELD_H
#define HOMEWORK_4_0_DATEFIELD_H


#include "FieldTemplate.hpp"
#include "Field.h"
#include "data.h"

class DateField : public FieldTemplate<Date> {
public:

	DateField(){};
	~DateField(){};
	int getType();

	void addElem(const Date& elem_to_add);

	string getElem(int i);

private:
	int _type = tDate;
	vector<Date> _content;
};


#endif //HOMEWORK_4_0_DATEFIELD_H
