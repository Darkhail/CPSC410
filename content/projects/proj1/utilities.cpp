/*
 * utilities.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: travi
 */

#include "utilities.h"
#include <iostream>
#include <algorithm>
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
	infile.close();
	return SUCCESS;
}

int saveData(const char* filename){
	ofstream out;

	out.open(filename);
	if(!out.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	out.clear();
	process_stats y;

	if(!p.empty()){
		y = getNext();

		out << y.process_number + ',' + y.start_time + ',' + y.cpu_time;
	}







	out.close();
	return SUCCESS;
}

bool compareB(const process_stats &a, process_stats &b){
	if(a.cpu_time == b.cpu_time){
		if(a.process_number == b.process_number){
			return a.start_time<b.start_time;
		}else{
			return a.process_number<b.process_number;
		}
	}else{
		return a.cpu_time < b.cpu_time;
	}

	return true;
}

void sortData(SORT_ORDER mySortOrder){
	sort(p.begin(), p.end(), compareB);
}



process_stats getNext(){
	process_stats q = p.front();
	p.pop_back();
	return q;
}







