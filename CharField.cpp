//
// Created by Riccardo Carità on 25/06/2020.
//

#include "CharField.h"
int CharField::getType() {
	return _type;
}

void CharField::addElem(const char &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string CharField::getElem(int j) {
	return to_string(_content[j]);
}

vector<char> CharField::getContent() {
	return _content;
}