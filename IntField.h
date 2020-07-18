//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_3_0_INTFIELD_H
#define HOMEWORK_3_0_INTFIELD_H
#include "FieldTemplate.hpp"

//#include "Converters.hpp"

class IntField : public FieldTemplate<int> {
public:

	IntField(){};
	~IntField(){};
	int getType();

	void addElem(const int& elem_to_add);

	void autoIncrementer(const int pos);

	string getElem(int j);

	void setElem(int i, string& newfieldvalue);

	void operator=(const IntField& to_assign);

private:
	int _type = tInt;
	vector<int> _content;

};


#endif //HOMEWORK_4_0_INTFIELD_H
