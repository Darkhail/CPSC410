/*
 * utilities.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: travi
 */

#include "utilities.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

process_stats x;

int loadData(const char* filename){
	x = {};

	ifstream infile;

	infile.open(filename);
	if(!infile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	while(infile.good()){
		string s;
		getline(infile,s);
	}

	return SUCCESS;
}

int saveData(const char* filename){
	return 0;
}

void sortData(SORT_ORDER mySortOrder){

}

process_stats getNext(){
	return x;
}







