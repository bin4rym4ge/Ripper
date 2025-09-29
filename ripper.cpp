#include <iostream>
#include <vector>
#include <thread>
#include "ripper.h"

using namespace std;

string fnumstr4(int num){

	if(num < 10){

		return "000" + to_string(num);

	} else if(num < 100){

		return "00" + to_string(num);

	} else if(num < 1000){

		return "0" + to_string(num);

	} else {

		return to_string(num);
	}
}

vector<vector<string>> mdiv(vector<string> in, int x){

	vector<vector<string>> out;

	int indx = 0;
	int indmax = in.size();

	// init. out with x vectors
	for(int i = 0; i < x; i++) out.push_back(vector<string>());

	// push in elements to x number out vectors sequentially one to each out vector
	// push first element to out[0] the next to out[1]
	for(int i = 0; i < indmax; i++){
			for(int j = 0; j < x; j++){

				out[j].push_back(in[indx]);

				indx++;

				if( indx >= (indmax) ) break;

			}

		if( indx >= (indmax) ) break;

	}

	return out;
}

void seqdl(vector<string> vurl, vector<string> vfname, string dlpath){

	if(dlpath.back() != '/') dlpath.push_back('/');

	string temp;

	for(int i = 0; i < vurl.size(); i++){

		temp = "curl --create-dirs " + vurl.at(i) + " -o " + dlpath + vfname.at(i);

		system(temp.c_str());
	}
}

void multidl(vector<vector<string>> inurl, vector<vector<string>> inname, string dlpath){

	if(dlpath.back() != '/') dlpath.push_back('/');

}

