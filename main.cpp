#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

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
	regex r(regstr + "(.*)"); // make global... sudo global
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

	// download test
	// temp = "curl " + vurl.at(0) + " -o ./" + vfname.at(0);
	// cout << temp << endl;
	// system(temp.c_str());
	

	// sequential download
	for(int i = 0; i < vurl.size(); i++){

		if(argv[4]){
			temp = "curl --create-dirs " + vurl.at(i) + " -o ./" + (string)argv[4] + vfname.at(i);
		} else {
			temp = "curl " + vurl.at(i) + " -o ./" + vfname.at(i);
		}
		system(temp.c_str());
	}

	infile.close();
	return 0;
}


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


