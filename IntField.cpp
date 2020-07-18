//
// Created by Riccardo Carità on 25/06/2020.
//

#include "IntField.h"
int IntField::getType() {
	return _type;
}

void IntField::addElem(const int &elem_to_add) {
	FieldTemplate::addElem(elem_to_add);
}

string IntField::getElem(int j) {
	return to_string(_content[j]);
}

void IntField::setElem(int i, string& newfieldvalue) {
	_content[i] = stoi(newfieldvalue);
}

void IntField::autoIncrementer(const int pos) {
	if (pos!=0) {
		_content[pos] = _content[pos - 1] + 1;
	}
}

void IntField::operator=(const IntField& to_assign) {
	_content = to_assign._content;
}