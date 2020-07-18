//
// Created by Riccardo Carità on 07/06/2020.
//

#ifndef HOMEWORK_4_0_FIELDTEMPLATE_HPP
#define HOMEWORK_4_0_FIELDTEMPLATE_HPP

#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

 template <typename T>
class FieldTemplate : public Field, public vector<FieldTemplate<T>> {
public:

	FieldTemplate() : Field() {}


	explicit FieldTemplate(const T& to_set) {
		_content.push_back(to_set);
	}

	~FieldTemplate(){};

	//virtual string GetType(){};

	void addElem(const T &elem_to_add) {
		_content.push_back(elem_to_add);
	}



	string getElem(typename vector<T>::iterator i){
		return "";
	}

	void setElem(typename vector<T>::iterator i, const string& newfieldvalue){};

	void deleteElem(int i){
		_content.erase(i);
	}

	void deleteElem(typename vector<T>::iterator i) {
		_content.erase(i);
	}

	void getIterator(typename vector<FieldTemplate<T>>::iterator &it1, typename vector<FieldTemplate<T>>::iterator &it2){
		it1 = _content.begin();
		it2 = _content.end();
	}
	void getIterator(typename vector<FieldTemplate<T>>::iterator &it, int i){
		it = _content[i];
	}

	void operator=(const FieldTemplate& to_assign) {
		_content = to_assign._content;
	}

	FieldTemplate getVector(){
		return _content;
	}

private:
	string _name;
	vector<T> _content;

};


#endif //HOMEWORK_4_0_FIELDTEMPLATE_HPP
