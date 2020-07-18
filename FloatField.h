//
// Created by Riccardo Carità on 25/06/2020.
//

#ifndef HOMEWORK_4_0_FLOATFIELD_H
#define HOMEWORK_4_0_FLOATFIELD_H

#include "FieldTemplate.hpp"
#include "Field.h"
//#include "Converters.hpp"

class FloatField : public FieldTemplate<float> {
public:

	FloatField(){};
	~FloatField(){};
	int getType();

	void addElem(const float& elem_to_add);

	string getElem(int j);

private:
	int _type = tFloat;
	vector<float> _content;
};


#endif //HOMEWORK_4_0_FLOATFIELD_H
