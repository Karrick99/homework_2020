//
// Created by Riccardo Carità on 23/06/2020.
//

#include "Database.h"


void Database::createTable(const string name) {
	_tableMap[name] = Table();
	//_tableMap.emplace(name, new Table);
}

void Database::addField(const string& tablename, const string &fieldname, string fieldtype, bool notnull, bool autoincr) {

	if(_tableMap.find(tablename)!=_tableMap.end()) {
		int intfieldtype = typeConverter(fieldtype);
        _tableMap[tablename].addField(fieldname, notnull, autoincr, intfieldtype); //bor _tableMap[fieldname].addField
	}

}

void Database::setPrimaryKey(const string &tab_name, string &primary_key) {
    if(_tableMap.find(tab_name)!=_tableMap.end())
    _tableMap[tab_name].setPrimaryKey(primary_key);
}

/*bool Database::colExists(const string& tab_name, const string& col_name) {
    const auto & it_target_tab = _tables.find(tab_name);
    return it_target_tab->second.colIsPresent(col_name);
}

bool Database::tabExists(const string& name) {
    const auto & it_target_tab = _tables.find(tab_name);
    bool result = (it_target_tab != _tables.end()) ? true : false;
    return result;
}
*/
void Database::dropTable(const string &tab_name) {
        const auto it = _tableMap.find(tab_name);
        if(it != _tableMap.end())
        this->_tableMap.erase(tab_name);
}

void Database::addRecord(const string &tablename, const vector<string> &names, const vector<string> &values) {
	if(_tableMap.find(tablename)!=_tableMap.end())
		_tableMap[tablename].addRecord(names, values);
}

//template <typename T>
void Database::deleteRecord(const string &tablename, const string &fieldname, const string &fieldvalue) {
	if(_tableMap.find(tablename)!=_tableMap.end())
		_tableMap[tablename].deleteRecord(fieldname, fieldvalue);
}

void Database::updateRecord(const string &tablename, const string &fieldname1, const string& fieldname2, const string &value1, const string& value2) {
	if(_tableMap.find(tablename)!=_tableMap.end())
		_tableMap[tablename].updateRecord(fieldname1, fieldname2, value1, value2);
}

void Database::truncate(const string &tablename) {
	if(_tableMap.find(tablename)!=_tableMap.end())
		_tableMap[tablename].truncate();
}

void Database::select(const vector<string> &fieldNames, const string &table_name, bool select_all,
					  const string &field_to_search, const string &value_to_search, string order_field, bool order_verse) {
	if(_tableMap.find(table_name)!=_tableMap.end())
		_tableMap[table_name].select(fieldNames, select_all, field_to_search, value_to_search, order_field, order_verse);

}

/*string Database::typeOfColumn(const string &tab_name, const string &col_name) {
    if (this->tabIsPresent(tab_name)) {
        const auto & it_target_tab = _tables.find(tab_name);
        return it_target_tab->second.typeOfCol(col_name);
    } else {
        return string();
    }
}
*/