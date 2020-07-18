//
// Created by Riccardo Carità on 23/06/2020.
//

#include "Table.h"

void Table::addField(const string &name, bool notnull, bool autoincr, int intfieldtype){
//_interi.push_back(FieldTemplate<int> (name));

//TODO: valutare se mettere make_shared al posto del reset

	switch (intfieldtype) {
		case tInt:
			//_FieldsMap.emplace(name, new IntField);
			_FieldsMap[name].reset(new IntField());
			break;

		case tFloat:
			//_FieldsMap.emplace(name, new FloatField);
			_FieldsMap[name].reset(new FloatField());
			break;

		case tChar:
			//_FieldsMap.emplace(name, new CharField);
			_FieldsMap[name].reset(new CharField());
			break;

		case tText:
			//_FieldsMap.emplace(name, new TextField);
			_FieldsMap[name].reset(new TextField());
			break;

		case tDate:
			//_FieldsMap.emplace(name, new DateField);
			_FieldsMap[name].reset(new DateField());
			break;

		case tTime:
			//_FieldsMap.emplace(name, new TimeField);
			_FieldsMap[name].reset(new TimeField());
			break;

		default:
			//TODO: inserire una eccezione nuova per tipi non riconosciuti
			break;
	}
	if(autoincr)
		_FieldsMap[name]->setAutoIncr();
	if(notnull)
		_FieldsMap[name]->setNotNull();

}

void Table::setPrimaryKey(const string &pk_to_set) {
	//auto it = _FieldsMap.find(pk_to_set);
		_PrimaryKey = pk_to_set;
	}


Table::Table() {
	//_PrimaryKey = " ";
	//_FieldsMap.clear();
}

Table::~Table() {

}

void Table::operator = (const Table &to_assign) {
	_FieldsMap = to_assign._FieldsMap;
}

void Table::addRecord(const vector<string> &fieldname, const vector<string> &data) {

	for (auto it : _FieldsMap)
	{
		if(it.second->getAutoIncr() == true && it.second->getType()==tInt) {
			it.second->autoIncrementer(_records);
		}
	}
		for (int i = 0; i < fieldname.size(); i++) {
			if (_FieldsMap.find(fieldname[i]) != _FieldsMap.end()) {
				int tipo = _FieldsMap[fieldname[i]]->getType();
				if (_FieldsMap[fieldname[i]]->getAutoIncr() == true) {
					throw (writeOnAutoincr());
				} else
					switch (tipo) {
						case tInt:
							_FieldsMap[fieldname[i]]->addElem(stoi(data[i]));
							break;
						case tFloat:
							_FieldsMap[fieldname[i]]->addElem(stof(data[i]));
							break;
						case tChar:
							_FieldsMap[fieldname[i]]->addElem(data[i][1]);
							break;
						case tText:
							_FieldsMap[fieldname[i]]->addElem(data[i]);
							break;
						case tDate:
							_FieldsMap[fieldname[i]]->addElem(Date(data[i]));
							break;
						case tTime:
							_FieldsMap[fieldname[i]]->addElem(Time(data[i]));
							break;
					}
				_records++;

			}
		}

}
template <typename T>
void Table::deleteRecordTemplate(const string &fieldname, const string &fieldvalue) {

	//int tipo = it1.second->getType();
	typename vector<T>::iterator it1;
	typename vector<T>::iterator it2;
	_FieldsMap[fieldname]->getIterator<T>(it1, it2); //bor aggiunto <T> tolte & dai paramteri
	for (typename vector<T>::iterator iter = it1; iter != it2; ++iter)
	{
		FieldTemplate<T>* Ptr1 = dynamic_cast<FieldTemplate<T>*>(_FieldsMap[fieldname].get());
			if (Ptr1->getElem(iter) == fieldvalue || fieldvalue == "delete_all")
				for (auto &it3 : _FieldsMap) {
					FieldTemplate<T> *Ptr2 = dynamic_cast<FieldTemplate<T> *>(it3.second.get());
					Ptr2->deleteElem(iter);
				}
		}
	}





void Table::deleteRecord(const string& fieldname, const string& fieldvalue = "delete_all") {
	for(const auto& it : _FieldsMap)
	{
		int type = it.second->getType();
		switch (type){
			case tInt: deleteRecordTemplate<IntField>(fieldname, fieldvalue);
		    break;
			case tFloat: deleteRecordTemplate<FloatField>(fieldname, fieldvalue);
			break;
			case tChar: deleteRecordTemplate<CharField>(fieldname, fieldvalue);
			break;
			case tText: deleteRecordTemplate<TextField>(fieldname, fieldvalue);
			break;
			case tDate: deleteRecordTemplate<DateField>(fieldname, fieldvalue);
			break;
			case tTime: deleteRecordTemplate<TimeField>(fieldname, fieldvalue);
			break;
		}
	}
}
exception Table::writeOnAutoincr() {
	cerr << "Attempt to write on a parameter with 'AUTO_INCREMENT' target" << endl;
	return exception();
}
exception Table::absentNotNull() {
	cerr << "Absence of parameter which was defined as 'NOT NULL'"<<endl;
	return exception();
}

template <typename T>
void Table::updateRecordTemplate(const string &fieldname1,const string& fieldname2, const string &value1, const string& value2) {

	//int tipo = it1.second->getType();
	typename vector<T>::iterator it1;
	typename vector<T>::iterator it2;
	_FieldsMap[fieldname1]->getIterator<T>(it1, it2);
	for (typename vector<T>::iterator iter = it1; iter != it2; ++iter)
	{
		FieldTemplate<T>* Ptr1 = dynamic_cast<FieldTemplate<T>*>(_FieldsMap[fieldname1].get());
		if (Ptr1->getElem(iter) == value1)
			dynamic_cast<FieldTemplate<T>*>(_FieldsMap[fieldname1].get())->setElem(iter,value2);
	}
}

void Table::updateRecord(const string& fieldname1, const string& fieldname2, const string& value1, const string& value2) {
	for(const auto& it : _FieldsMap)
	{
		int type = it.second->getType();
		switch (type){
			case tInt: updateRecordTemplate<IntField>(fieldname1, fieldname2, value1, value2);
				break;
			case tFloat: updateRecordTemplate<FloatField>(fieldname1, fieldname2, value1, value2);
				break;
			case tChar: updateRecordTemplate<CharField>(fieldname1, fieldname2, value1, value2);
				break;
			case tText: updateRecordTemplate<TextField>(fieldname1, fieldname2, value1, value2);
				break;
			case tDate: updateRecordTemplate<DateField>(fieldname1, fieldname2,value1, value2);
				break;
			case tTime: updateRecordTemplate<TimeField>(fieldname1, fieldname2, value1, value2);
				break;
		}
	}
}

void Table::truncate() {
	for(const auto it1 : _FieldsMap) {
			deleteRecord(it1.first);
	}
}

template <typename T>
void Table::recordSelectTemplate(string fieldname, string value, string orderfield, bool orderverse) {

	//stampa uno o più record

	//int tipo = it1.second->getType();
	//integer vectors to order from the requested field which has to be integer
	typename vector<int>::iterator it1;
	typename vector<int>::iterator it2;
	typename vector<int>::iterator itOrder;

	//template vectors to print the content
	typename vector<T>::iterator it3;
	typename vector<T>::iterator it4;


	if(orderfield.empty())
	_FieldsMap[fieldname]->getIterator<T>(it3, it4);
	else {
		_FieldsMap[orderfield]->getIterator<int>(it1, it2);

		for(auto &it5 : _FieldsMap){
			it5.second->getIterator<T>(it3, it4);
				//sort(it3, it4, ascOrder);
		}
	}

	for (typename vector<T>::iterator iter = it3; iter < it4; ++iter)
	//for(int i=0; i<_records; ++i)
	{
		FieldTemplate<T>* Ptr1 = dynamic_cast<FieldTemplate<T>*>(_FieldsMap[fieldname].get());
		if (Ptr1->getElem(iter) == value)
			for (const auto &it3 : _FieldsMap) {
				FieldTemplate<T>* Ptr2 = dynamic_cast<FieldTemplate<T>*>(it3.second.get());
				cout << Ptr2->getElem(iter) << " ";
			}
		cout << endl;

	}
}

void Table::singleSelectTemplate(const string &name, int k){
	cout << _FieldsMap[name].get()->getElem(k) << endl;
}

void Table::select(const vector<string> &fieldNames, bool select_all, const string &field_to_search,
				   const string &value_to_search, string order_field, bool order_verse) {

	//gestisce stampa sia per record sia per fields

	bool already_printed = false;
	bool exclusive_selection = false;

	if(!value_to_search.empty() && !field_to_search.empty()) {
		exclusive_selection = true;
	}

	// exclusive selection by records
	if(exclusive_selection)
		{
		int type = _FieldsMap[field_to_search]->getType();
		switch (type){
			case tInt: recordSelectTemplate<int>(field_to_search, value_to_search, order_field, order_verse);
				break;
			case tFloat: recordSelectTemplate<float>(field_to_search, value_to_search, order_field, order_verse);
				break;
			case tChar: recordSelectTemplate<char>(field_to_search, value_to_search, order_field, order_verse);
				break;
			case tText: recordSelectTemplate<string>(field_to_search, value_to_search, order_field, order_verse);
				break;
			case tDate: recordSelectTemplate<Date>(field_to_search, value_to_search, order_field, order_verse);
				break;
			case tTime: recordSelectTemplate<Time>(field_to_search, value_to_search, order_field, order_verse);
				break;
		}
	}
	else
		//stampa verticale per fields
	for(int k = 0; k < _records; k++)
		for(const auto& it1 : _FieldsMap) {
			for (const auto &it2 : fieldNames) {
				if ((select_all == true || it1.first == it2) && !already_printed) {

					int type = it1.second.get()->getType();

					cout << it1.second.get()->getElem(k) << " ";
					already_printed = true;

				}
			}
		}
}

//bool Table::ascOrder()