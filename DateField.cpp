//
// Created by Riccardo Carità on 25/06/2020.
//

#include "DateField.h"
int DateField::getType() {
	return _type;
}

void DateField::addElem(const Date &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string DateField::getElem(int i) {
	return _content[i].str();
}
