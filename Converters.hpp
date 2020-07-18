//
// Created by Riccardo Carità on 23/06/2020.
//

#ifndef HOMEWORK_4_0_CONVERTERS_HPP
#define HOMEWORK_4_0_CONVERTERS_HPP

#include <iostream>
#include "data.h"

using namespace std;


	enum Commands {
		cCreate,
		cDrop,
		cInsert,
		cDelete,
		cTruncate,
		cUpdate,
		cSelect,
		cQuit,
		cUndefined
	};

	inline Commands commandConverter (string &s){
		if (s == "CREATE")
			return cCreate;

		if (s == "DROP")
			return cDrop;

		if (s == "INSERT")
			return cInsert;

		if(s == "DELETE")
			return cDelete;

		if(s == "TRUNCATE")
			return cTruncate;

		if (s == "UPDATE")
			return cUpdate;

		if (s == "SELECT")
			return cSelect;

		if(s == "QUIT")
			return cQuit;

		return cUndefined;
	}

	enum Types {
		tInt,
		tFloat,
		tChar,
		tText,
		tDate,
		tTime
	};

inline Types typeConverter (string &type){
	if(type == "INT")
		return tInt;

	if(type == "FLOAT")
		return tFloat;

	if(type == "CHAR")
		return tChar;

	if(type == "TEXT")
		return tText;

	if(type == "DATE")
		return tDate;

	if(type == "TIME")
		return tTime;
}

inline string stringAdapter(string& to_adapt){
	string s_temp = to_adapt;
	string s_temp1;

	s_temp.erase(remove(s_temp.begin(), s_temp.end(), '\n'), s_temp.end());
	s_temp1 = s_temp;

	int mod=0;
	for (int i = 0; i < s_temp1.length(); i++) {

		if (s_temp1[i] == '(') {
			s_temp.insert(i+mod, " ");
			s_temp.insert(i + 2 +mod, " ");
			mod=mod+2;
		}
	}
	s_temp1 = s_temp;

	mod=0;
	for (int i = 0; i < s_temp1.length(); i++) {

		if (s_temp1[i] == ',') {
			s_temp.insert(i + mod, " ");
			s_temp.insert(i+2+mod," ");
			mod=mod+2;
		}
	}

	//bor
	s_temp1 = s_temp;

	mod = 0;
	for (int i = 0; i < s_temp1.length(); i++) {

		if (s_temp1[i] == '=') {
			s_temp.insert(i + mod, " ");
			s_temp.insert(i + 2 + mod, " ");
			mod = mod + 2;
		}
	}
	//end bor

	s_temp1 = s_temp;
	mod = 0;
	for (int i = 0; i < s_temp1.length(); i++) {

		if (s_temp1[i] == ')') {
			s_temp.insert(i + mod, " ");
			//TODO: valutare se ha senso lo spazio dopo parentesi chiusa, aggiunto per l'insert
			s_temp.insert(i+2+mod," ");
			mod = mod +2;
		}

	}

	return s_temp;
};

#endif //HOMEWORK_4_0_CONVERTERS_HPP
