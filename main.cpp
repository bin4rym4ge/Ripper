#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <regex>
#include "ripper.h"

using namespace std;

string fnumstr4(int num);

int main(int argc, char* argv[]){

	// file stream declarations
	ifstream infile((string)argv[1]);
	ifstream regfile((string)argv[2]);

	// string declarations
	string temp;
	string instr;
	string regstr;


	// regfile to string
	while(getline(regfile, temp)) regstr = regstr + temp;
	regfile.close(); // don't need the regfile anymore

	temp = "";

	// regex declarations
	regex r(regstr + "(.*)"); // make global... pseudo global
	smatch sm;

	// vectors
	vector<string> vin;
	vector<string> vurl;
	vector<string> vfname;


	// infile to vector
	while(getline(infile, temp)) vin.push_back(temp);

	// invec regex matches to string
	for(string in : vin){

		regex_search(in, sm, r);

		instr = instr + sm[1].str();
	}

	// test instr matches
	// cout << instr << endl;


	// urls to vec
	do{
		regex_search(instr, sm, r);

		vurl.push_back(sm[1].str());

		instr = sm[2].str();

	}while( (instr != "") || (instr != "\0") );

	infile.close();

	// cout << vurl[0] << endl;




	if(!argv[3]){
		for(string url : vurl){
			cout << url << endl;
		}
	}

	//system("echo hello");

	if(argv[3]){
		
		ofstream outfile((string)argv[3]);

		for(string url : vurl){
			outfile << url << endl;
		}
	}

	// set file names
	regex fnr("\\/([^/]+\\.\\w+$)");
	for(int i = 0; i < vurl.size(); i++){

		regex_search(vurl.at(i), sm, fnr);

		vfname.push_back(fnumstr4(i + 1) + "_" + sm[1].str());
	}

	// sequential download
	if(argv[4]) seqdl(vurl, vfname, (string)argv[4]);


	return 0;
}

