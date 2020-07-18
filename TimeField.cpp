//
// Created by Riccardo Carità on 25/06/2020.
//

#include "TimeField.h"
int TimeField::getType() {
	return _type;
}

void TimeField::addElem(const Time &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string TimeField::getElem(int j) {
	return _content[j].str();
}
