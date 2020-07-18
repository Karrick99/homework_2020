//
// Created by Riccardo Carità on 25/06/2020.
//

#include "FloatField.h"
int FloatField::getType() {
	return _type;
}

void FloatField::addElem(const float &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string FloatField::getElem(int j) {
	return to_string(_content[j]);
}
