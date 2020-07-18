#include <iostream>

#include <vector>

#include "Database.h"
#include <string>
#include <algorithm>

using namespace std;

string stringAdapter(string& to_adapt);

int main() {

	string s_in, command, comma;
	string table_name, field_name, type;
	bool exit = false, notnull = false, autoincrement = false;
	int IntCommand, IntType;
	exception wrong_command;
	//int commandConverter(string& s);



	Database dB1;

    // Here's the beginning of the loop that asks to the user
    //to insert the command and handles it

	do {
		s_in.clear();
		cout << "type a command:" << endl;
		getline(cin, s_in, ';');

		if (s_in == "QUIT()")
		return 0;
		else
			{
			try {
				s_in = stringAdapter(s_in);
				//cout << "stringa inserita:" << endl;
				cout << s_in << endl;
				istringstream linestream(s_in);
				linestream >> command;

				IntCommand = commandConverter(command);

				string param[4];

				switch (IntCommand) {
					case cCreate: {

						linestream >> command;
						if (command != "TABLE")
							throw (wrong_command);
						else {
							linestream >> command;

							table_name = command;
							dB1.createTable(table_name);


							linestream >> command;
							if (command != "(")
								throw (wrong_command);


							linestream >> field_name; //bor table_name;
							int k = 0;

							do {

								if (k != 0)
									linestream >> field_name;
								linestream >> type;

								if (field_name == ")" && type == ")") //bor
									break;

								// presa del nome parametro

								linestream >> param[0];

								////parametri aggiuntivi (NOT NULL e/o AUTO_INCREMENT)
								
								comma = ""; //bor

								if (param[0] != "," && param[0] != ")") {
									linestream >> param[1];
									//cout << "parametri" << endl;
									if ((param[1] != "AUTO_INCREMENT" && param[1] != "NULL") || param[1] == "," ||
										param[1] == ")")
										comma = param[1];
									else {
										linestream >> param[2];
										if (param[2] == "," || param[2] == ")")
											comma = param[2];
									}
									if (param[0] == "NOT" && param[1] == "NULL")
										notnull = true;
									else notnull = false;

									if (param[0] == "AUTO_INCREMENT" || param[2] == "AUTO_INCREMENT")
										autoincrement = true;
									else autoincrement = false;
								} else
									comma = param[0];
								// qui creo colonna (tipo dato) tabella usando AddField
								
								if (field_name != "PRIMARY" && type != "KEY") {//bor "ID")
									dB1.addField(table_name, field_name, type, notnull, autoincrement);
									//cout << "create field" << endl; //bor creo record
								}
								else
								{	if (field_name == "PRIMARY" && type == "KEY") {
										//cout << param[0] << endl;
										dB1.setPrimaryKey(table_name, param[0]); //bor param[0]
										//cout << "param 1" << param[1] << endl;
									} else
										throw(wrong_command);
							    }

								if(comma == "") //bor
									linestream >> comma;

								k++;
							} while (comma != ")" && field_name != ")");
						}
						cout <<"created table" <<endl;
					}
					break;

					case cDrop : {

						linestream >> command;
						if (command != "TABLE") {
							cerr << "1" <<endl;
							throw (wrong_command);
						}

						else {
							linestream >> command;
							table_name = command;
							dB1.dropTable(table_name);

							cout << "Dropped table" << endl; //bor

						}
					}
					break;

					case cInsert:{
						linestream >> command;
						//cout << command << endl;

						if (command != "INTO") {
							cerr << "1" << endl;
							//throw (wrong_command);
						}

						else {
							//cout << "else" << endl;

							linestream >> table_name;
							linestream >> command;

							//cout << "1";
							if(command != "(") {
								cerr << "2" << endl;
								//throw (wrong_command);
							}
							vector<string> recordNames;
							vector<string> recordValues;

							//cout <<"vectors creati" << endl;

							do{
								//cout << "loop" <<endl;
								linestream >> command;
								recordNames.push_back(command);
								linestream >> command;
								if(command != "," && command != ")") {
									cerr << "3" << endl;
									cerr << "comando" << command << endl;
									throw (wrong_command);
								}
							}
							while(command != ")");
							//cout << "values" <<endl;
							linestream >> command;
							if(command != "VALUES") {
								cerr << "4" <<endl;
								throw (wrong_command);
							}
							linestream >> command;
							if(command != "(") {
								cerr << "5" << endl;
								throw (wrong_command);
							}

							//cout <<"3";
							do{
								//cout << "loop 2" <<endl;
								linestream >> command;
								recordValues.push_back(command);
								linestream >> command;
								if(command != "," && command != ")") {
									cerr << "6" << endl;
									throw (wrong_command);
								}
							}
							while(command != ")");
							//cout << "inserimento" <<endl;
							dB1.addRecord(table_name, recordNames, recordValues);
							cout << "Inserted values" << endl; //bor
						}
					}
					break;

					case cDelete:{
						string recordName;
						string recordValue;
						linestream >> command;
						if (command != "FROM")
							throw (wrong_command);

							linestream >> table_name;
							linestream >> command;
							if(command != "WHERE")
								throw(wrong_command);


							linestream >> recordName;

							linestream >> command;
								if(command != "=")
									throw(wrong_command);

								linestream >> recordValue;

							dB1.deleteRecord(table_name, recordName, recordValue);

							cout << "Deleted record(s)" << endl;

						}
					break;

					case cTruncate:
					{
						linestream >> command;
						if(command != "TABLE")
							throw(wrong_command);
						linestream >> table_name;
						dB1.truncate(table_name);
					}
					break;

					case cUpdate:
					{
						linestream >> table_name;
						linestream >> command;
						do{
							if(command == "SET") {
								linestream >> param[0];
								linestream >> comma;
								if(comma != "=")
									throw(wrong_command);
								linestream >> param[1];
								linestream >> comma;
								if(comma != "WHERE")
									throw (wrong_command);
								linestream >> param[2];
								linestream >> comma;
								if(comma != "=")
									throw(wrong_command);
								linestream >> param[3];

								dB1.updateRecord(table_name, param[2],param[0],param[3],param[1]);

							}
						}
						while(param[0]=="SET");
					}
						break;

					case cSelect: {
						vector<string> fieldNames;
						string field_to_search;
						string value_to_search;
						string order_field;
						//the verse of the order is meant to be "true" if the order is ASC
						//and to be false if the order is DESC
						bool order_verse = true;
						bool select_all = false;
						int i = 0;
						do {
							linestream >> command;
							if (command == "*")
								select_all = true;
							else {
								linestream >> comma;

								if (comma != ",")
									throw (wrong_command);
								if (command != "FROM")
									fieldNames[i] = command;
							}

						} while (command != "FROM" && select_all == false);
						if(select_all == true) {
							linestream >> command;
							if(command != "FROM")
								throw (wrong_command);
						}
						linestream >> table_name;
						linestream >> command;
						if (command == "WHERE")
						{
							linestream >> field_to_search;
							linestream >> comma;
							if(comma != "=")
								throw (wrong_command);
							linestream >> value_to_search;

							linestream >> command;
							if(command == "ORDER")
							{
								linestream >> command;
								if(command != "BY")
									throw (wrong_command);
								linestream >> command;
								//order_type = typeConverter(command);
								linestream >> command;
								if(command == "ASC")
									order_verse = true;
								if(command == "DESC")
									order_verse = false;

							}
						}

						dB1.select(fieldNames, table_name, select_all, field_to_search, value_to_search, order_field, order_verse);
					}
					break;

					case cQuit:
						linestream >> command;
						if(command == "(")
						{
							linestream >> command;
							if(command == ")")
							return 0;
						}
					break;

					default:
						throw(wrong_command);
				}

			}
			catch (exception wrong_command) {
				cerr << "the command is wrong or not complete" << endl;
				}

			}
	}
		while (s_in != "QUIT()");



	return 0;
}

