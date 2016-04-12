#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include "Store.h"
#include "Customer.h"
#include "Product.h"
//#include "source.h"
using namespace std;

ifstream ifs;
ofstream ofs;

istream& getInputStream(string filename);
ostream& getOutputStream(string filename);
void processSelection(char selection, Store& store, istream& is, ostream& os);
void printMenu();

int main(int argc, char* argv[]) {
	string infile;  // automatically initialized to empty string, size 0
	string outfile; // automatically initialized to empty string, size 0
	if (argc >= 2) { // have an input file
		infile = argv[1];
		if (argc >= 3) { // also have an output file
			outfile = argv[2];
		}
		else
			outfile = "output.txt";
	}

	istream &is = getInputStream(infile);
	ostream &os = getOutputStream(outfile);

	Store store;

	char selection = ' ';
	do {
		processSelection(selection, store, is, os);
		// does nothing first time through loop		
		if (infile.size()==0) { // interactive mode
			printMenu();
			os << endl << "Enter Choice: ";
		}
		is >> selection;
		selection = tolower(selection);
		if (infile.size() == 0) os << endl;
	} while (selection != 'q' && is.good()); 
	// quit is not entered or have not reached end of input file
}

void printMenu() {
	cout << endl << "Menu: " << endl;
	cout << "  1: Create Product " << endl;
	cout << "  2: Create Store" << endl;
	cout << "  3: Create Customer" << endl;
	cout << "  4:  " << endl;
	cout << "  5:  " << endl;
	cout << "  6:  " << endl;
	cout << "  7:  " << endl;
	cout << "  8:  " << endl;
	cout << "  Q:  Quit" << endl;
}

void processSelection(char selection, Store& store, istream& is, ostream& os)
{
	string prompt = "";
	bool addBlankLine = true;
	int selectedVector = 0;
	switch (selection) {
	case '1':

		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	}

}

istream& getInputStream(string filename) {
	if (filename.size() != 0) { // set input stream to be a file
		ifs.open(filename);
		if (!ifs.is_open()) {
			cout << "Unable to open " << filename << endl;
		}
		else
			return ifs;
	}
	// otherwise set input stream to be the keyboard
	return cin;
}

ostream& getOutputStream(string filename) {
	if (filename.size() != 0) { // set set output stream to be a file
		ofs.open(filename);
		if (!ofs.is_open()) {
			cout << "Unable to open " << filename << endl;
		}
		else 
			return ofs;
	}
	// otherwise output stream to be the console/screen
	return cout;
}
