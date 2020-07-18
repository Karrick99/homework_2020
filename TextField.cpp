//
// Created by Riccardo Carità on 25/06/2020.
//

#include "TextField.h"
int TextField::getType() {
	return _type;
}

void TextField::addElem(const string &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string TextField::getElem(int j) {
	return _content[j];
}
