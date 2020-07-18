//
// Created by Riccardo Carità on 25/06/2020.
//

#include "Field.h"

void Field::setAutoIncr() {
	_autoincr = true;
}

void Field::setNotNull() {
	_notnull = true;
}

bool Field::getAutoIncr() {
	if(_autoincr==true)
		return true;
	else
	return false;
}

bool Field::getNotNull() {
	if(_notnull == true)
		return true;
	else
	return false;
}

