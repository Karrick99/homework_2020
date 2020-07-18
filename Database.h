//
// Created by Riccardo Carità on 23/06/2020.
//

#ifndef HOMEWORK_4_0_DATABASE_H
#define HOMEWORK_4_0_DATABASE_H
#include <map>
#include "Table.h"
#include <iterator>
//#include "Converters.hpp"

using namespace std;

class Database {

public:

    Database(){}
    ~Database(){}

    void createTable(string name);

    void addField(const string& tablename, const string& fieldname, string fieldtype, bool notnull, bool autoincr);

    void dropTable(const string & tab_name);

    void setPrimaryKey(const string & tab_name, string & primary_key);

    //bool colExists(const string& tab_name, const string& col_name);

	//bool tabExists(const string& name);

    //string typeOfColumn(const string & tab_name, const string & col_name);

    void addRecord(const string& tablename, const vector<string> &names, const vector<string> &values);

    //template <typename T>
    void deleteRecord(const string& tablename, const string& fieldname, const string& fieldvalue);


    void updateRecord(const string& tablename, const string& fieldname1, const string& fieldname2, const string& value1, const string& value2);


	void truncate(const string& tablename);

	void select(const vector<string>& _FieldNames, const string& tableName, bool select_all, const string& field_to_search, const string& value_to_search, string order_field, bool order_verse);

private:

    map<string, Table> _tableMap;

};


#endif //HOMEWORK_4_0_DATABASE_H
