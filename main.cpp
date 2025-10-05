#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <regex>
#include <map>
#include "ripper.h"
#include "./libargmage/argmage.h"

using namespace std;

string fnumstr4(int num);
void helpscrn();

int main(int argc, char* argv[]){

	// help
	if( ((string)argv[1] == "-h") || ((string)argv[1] == "--help") ){

		helpscrn();

		return 0;
	}

	// parse argv into a map
	auto args = argmage::argvtomap(argc, argv, 1);

	// check if files args given and give necessary feedback
	if( (args["-f"] == "") && (args["-r"] == "") ){

		cout << "No files given\n";
		// display help screen
		helpscrn();
		return 0;

	}
	if( (args["-f"] == "") || (args["-f"] == "\0") ){

		cout << "No html file given\n";
		// display help screen
		helpscrn();
		return 0;

	} else if( (args["-r"] == "") || (args["-r"] == "\0") ){

		cout << "No regex file given\n";
		// display help screen
		helpscrn();
		return 0;
	}

	// add directory validation for all files... later.

	// file stream declarations
	ifstream infile(args["-f"]);
	ifstream regfile(args["-r"]);

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
	infile.close();

	// invec regex matches to string
	for(string in : vin){

		regex_search(in, sm, r);

		instr = instr + sm[1].str();
	}

	// urls to vec
	do{
		regex_search(instr, sm, r);

		vurl.push_back(sm[1].str());

		instr = sm[2].str();

	}while( (instr != "") && (instr != "\0") ); //changed from || to &&

	// infile.close();


	// if -x don't display urls in stdout or save to file
	// check if url save file given
	// if not display to std out
	if( (args["-x"] != "") && (args["-x"] != "\0") ){

	} else if( (args["-s"] == "") || (args["-s"] == "\0") ){

		for(string url : vurl){
			cout << url << endl;
		}

	} else {

		ofstream outfile(args["-s"]);

		for(string url : vurl){
			outfile << url << endl;
		}
		
		outfile.close();
	}

	// set file names
	regex fnr("\\/([^/]+\\.\\w+$)");

	for(int i = 0; i < vurl.size(); i++){

		regex_search(vurl.at(i), sm, fnr);

		vfname.push_back(fnumstr4(i + 1) + "_" + sm[1].str());
	}

	// sequential download
	if( ((args["-o"] != "") && (args["-o"] != "\0")) && ((args["-m"] == "") || (args["-m"] == "\0")) ) seqdl(vurl, vfname, args["-o"]);

	// parallel downloading
	if( ((args["-o"] != "") && (args["-o"] != "\0")) && ((args["-m"] != "") && (args["-m"] != "\0")) ){

	}else if( (args["-m"] != "") && (args["-m"] != "\0") ){

	}

	return 0;
}

void helpscrn(){

	cout << "\n\t+===================================================================+\n";
	cout << "\n";
	cout << "\t\t--help (-h)\n";

	cout << "\n";
	cout << "\t\t    -f file.html (or url savefile. depends on your regex)\n";

	cout << "\n";
	cout << "\t\t    -r regex_file.txt\n";

	cout << "\n";
	cout << "\t\t    -s url_save_file.txt\n";

	cout << "\n";
	cout << "\t\t    -x (no url save file or output)\n";

	cout << "\n";
	cout << "\t\t    -o /download/path/\n";

	cout << "\n";
	cout << "\t+===================================================================+\n\n";

}

