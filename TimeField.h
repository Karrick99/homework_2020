//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_TIMEFIELD_H
#define HOMEWORK_4_0_TIMEFIELD_H


#include "FieldTemplate.hpp"
#include "Field.h"
#include "Time.h"

class TimeField : public FieldTemplate<Time> {
public:

	TimeField(){};
	~TimeField(){};
	int getType();

	void addElem(const Time& elem_to_add);

	string getElem(int j);

private:
	int _type = tTime;
	vector<Time> _content;
};


#endif //HOMEWORK_4_0_TIMEFIELD_H
