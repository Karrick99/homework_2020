//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_TEXTFIELD_H
#define HOMEWORK_4_0_TEXTFIELD_H


#include "FieldTemplate.hpp"


class TextField : public FieldTemplate<string> {
public:

	TextField(){};
	~TextField(){};
	int getType();

	void addElem(const string& elem_to_add);

	string getElem(int j);

private:
	int _type = tText;
	vector<string> _content;
};


#endif //HOMEWORK_4_0_TEXTFIELD_H
