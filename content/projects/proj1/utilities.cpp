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
#include <sstream>
#include <vector>

using namespace std;

process_stats x;

vector <process_stats> p;

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

		stringstream i(s);

		string z;

		int time = 0;
		while(getline(i,z,CHAR_TO_SEARCH_FOR)){
			int y = stoi(z);
			if(time == 0){
				x.process_number = y;
				time++;
			}else if(time == 1){
				x.start_time = y;
				time++;
			}else{
				x.cpu_time = y;
				time = 0;
			}
		}
		p.push_back(x);

	}

	return SUCCESS;
}

int saveData(const char* filename){
	ofstream out;

	out.open(filename);
	if(!out.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	return SUCCESS;
}

void sortData(SORT_ORDER mySortOrder){

}

process_stats getNext(){
	process_stats q = p.front();
	p.pop_back();
	return q;
}







