//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_CHARFIELD_H
#define HOMEWORK_4_0_CHARFIELD_H


#include "FieldTemplate.hpp"
#include "Field.h"
#include "Converters.hpp"

class CharField : public FieldTemplate<char> {
public:

	CharField(){};
	~CharField(){};
	int getType();

	void addElem(const char& elem_to_add);

	string getElem(int j);

	vector<char> getContent();

private:
	int _type = tChar;
	vector<char> _content;
};


#endif //HOMEWORK_3_0_CHARFIELD_H
