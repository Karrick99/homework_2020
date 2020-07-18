//
// Created by Riccardo Carità on 23/06/2020.
//

#ifndef HOMEWORK_3_0_TABLE_H
#define HOMEWORK_3_0_TABLE_H
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <iterator>
#include <algorithm>


//#include "FieldTemplate.hpp"
#include "IntField.h"
#include "FloatField.h"
#include "CharField.h"
#include "DateField.h"
#include "TextField.h"
#include "TimeField.h"


using namespace std;

class Table {
public:

	Table();

	~Table();

	void addField(const string& name, bool notnull, bool autoincr, int intfieldtype);

	void addRecord(const vector<string>& fieldname, const vector<string>& data);

	template <typename T>
	void deleteRecordTemplate(const string& fieldname, const string& fieldvalue);

	void deleteRecord(const string& fieldname, const string& fieldvalue);

	template <typename T>
	void updateRecordTemplate(const string& fieldname1,const string& fieldname2, const string& oldfieldvalue, const string& newfieldvalue);

	void updateRecord(const string& fieldname1, const string& fieldname2, const string& value1, const string& value2);

	void setPrimaryKey(const string &pk_to_set);

	void truncate();

	template <typename T>
	void recordSelectTemplate(string fieldname, string value, string orderfield, bool orderverse);


	void singleSelectTemplate(const string &name, int k);

	void select(const vector<string> &fieldNames, bool select_all,
		   const string &field_to_search, const string &value_to_search, string order_field, bool order_verse);

	void operator = (const Table &to_assign);

	exception writeOnAutoincr();

	exception absentNotNull();


private:


	//map <string, Field> _FieldsMap;
	map <string, shared_ptr<Field>> _FieldsMap;




	string _PrimaryKey;

	int _records = 0;

};


#endif //HOMEWORK_4_0_TABLE_H
