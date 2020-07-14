/**************************************************************
 * File:    TestDriver.cpp
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * HashedSplays Class implementation.
 *
 *************************************************************/
#include "HashedSplays.h"
#include "Export.h"


int main(int argc, char* argv[]) {
	const string YES = "Y", NO = "N", MY_OUTPUT_1 = "MyOutput1.txt", MY_OUTPUT_2 = "MyOutput2.txt", 
		DEFAULT_INPUT1 = "input1.txt", DEFAULT_INPUT2 = "input2.txt", SOURCE_OUTPUT_1 = "output1.txt",
		SOURCE_OUTPUT_2 = "output2.txt";

	string usrResponce;

	cout << "*********Welcome to TestDriver.cpp*********" << endl;
	// Test 1: testing given input1.txt
	try {
		cout << "Test 1: Testing input1.txt" << endl;
		cout << "Will export results to "<< MY_OUTPUT_1 << endl;
		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');

		HashedSplays wordFrequency1(ALPHABET_SIZE);
		wordFrequency1.FileReader(DEFAULT_INPUT1);

		Export export1(MY_OUTPUT_1, wordFrequency1);

		export1.ExportHashCountResults();
		export1.ExportTree(19);
		export1.ExportTree("F");
		export1.ExportTree("K");
		export1.ExportAll("The");
		export1.CheckWork(SOURCE_OUTPUT_1);
		
	}

	// Error catching 
	catch (Exceptions& cException) {
		cout << "EXCEPTION: " << cException.GetMessage() << endl;
		return 1;
	}
	
	// Test 2: testing given input2.txt
	try {
		cout << "\nTest 2: Testing input2.txt" << endl;
		cout << "Will export results to " << MY_OUTPUT_2 << endl;

		cout << "\nATTENTION: Expect errors from lines 690-719.\n";
		cout << "All of the node values and frequencies are the same for both .txt files.\n" <<
			"The node's order is different for the two files.\n" << endl;

		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');

		HashedSplays wordFrequency2(ALPHABET_SIZE);
		wordFrequency2.FileReader(DEFAULT_INPUT2);

		Export export2(MY_OUTPUT_2, wordFrequency2);

		export2.ExportHashCountResults();
		export2.ExportTree(19);
		export2.ExportTree("F");
		export2.ExportTree("K");
		export2.ExportAll("The");
		export2.CheckWork(SOURCE_OUTPUT_2);
	}

	catch (Exceptions& cException) {
		cout << "EXCEPTION: " << cException.GetMessage() << endl;
		return 1;
	}
	

	// Test 3: testing hash table  
	try {
	        const string STOP_DELIM = "!"; const char NEGATIVE = '-';
		int indexNum = 0, digitCount = 0, wordCount = 0, findAllCount = 0, responceNum; 
		bool currisDigit = true, currisWord = true; 
		vector<int> digitList; vector<string> wordList, findAllList;
		
		usrResponce.clear();
		cout << "\nTest 3: Testing hash table length using the given .txt file (display only)" << endl;
		while (usrResponce == EMPTY_STR) {
			cout << "How long do you want the hash table: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');
			responceNum = usrResponce.length();
			for (int i = 0; i < responceNum; i++) {
				if (!isdigit(usrResponce[i])) { usrResponce.clear(); break; }
			}
		}
		indexNum = stoi(usrResponce); usrResponce.clear();

		while (usrResponce != STOP_DELIM) {
			currisDigit = false, currisWord = false;
			cout << "Enter any digit/char for the PrintTree function (Enter "
				<< "'" << STOP_DELIM << "'" << " to stop loop): ";

			cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');

			if (usrResponce != STOP_DELIM) { 
				int responceSize = usrResponce.size();
				for (int i = 0; i < responceSize; i++) {
				  // stopped here
				  if ((isdigit(usrResponce[i])) || (usrResponce[i] == NEGATIVE)) { currisDigit = true; }
					else { currisWord = true; }

					// word cannot contain both ints and chars
					if (currisDigit && currisWord) { currisDigit = false, currisWord = false; break; }
				}

				if (currisDigit) {
					digitList.push_back(stoi(usrResponce));
					digitCount++;
				}
				else if (currisWord) {
					wordList.push_back(usrResponce);
					wordCount++;
				}
				usrResponce.clear();
			}	
		}
		usrResponce.clear();
		while (usrResponce != STOP_DELIM) {
			cout << "Enter any value for the FindAll function (Enter "
				<< "'" << STOP_DELIM << "'" << " to stop loop): ";
			cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');
			if (usrResponce != STOP_DELIM) {
				findAllList.push_back(usrResponce);
				findAllCount++;
			}
		}

		digitList.resize(digitCount); wordList.resize(wordCount); findAllList.resize(findAllCount);
		cout << "\nThe HashedSplay object will read from "<< argv[1] <<" and the object's functions will go as follow:\n";
		cout << "1. PrintHashCountResults()\n2. PrintTree(int)\n3. PrintTree(string)\n4. FindAll(string)\n";
		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');

		HashedSplays wordFreq(indexNum);
		wordFreq.FileReader(argv[1]);

		// Implementations
		wordFreq.PrintHashCountResults();

		// PrintTree(int)
		cout << "\nThese values will be entered into PrintTree(int):" << endl;
		for (int i = 0; i < digitCount; i++) { cout << digitList.at(i) << endl; }

		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');
		for (int i = 0; i < digitCount; i++) {
			wordFreq.PrintTree(digitList.at(i));
		}

		// PrintTree (string)
		cout << "\nThese values will be entered into PrintTree(string):" << endl;
		for (int i = 0; i < wordCount; i++) { cout << wordList.at(i) << endl; }

		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');
		for (int i = 0; i < wordCount; i++) {
			wordFreq.PrintTree(wordList.at(i));
		}

		// FindAll(string)
		cout << "\nThese values will be entered into FindAll(string):" << endl;
		for (int i = 0; i < findAllCount; i++) { cout << findAllList.at(i) << endl; }

		cout << "Enter any value to continue: "; cin >> usrResponce; cin.clear(); cin.ignore(10000, '\n');
		for (int i = 0; i < findAllCount; i++) {
			wordFreq.FindAll(findAllList.at(i));
		}
		cout << "End of test 3" << endl;
	}

	catch (Exceptions& cException) {
		cout << "EXCEPTION: " << cException.GetMessage() << endl;
		return 1;
	}

	// End of tests
	usrResponce.clear();
	while (usrResponce != YES && usrResponce != NO) {
		cout << "Would you like to delete the two new export files ('Y' or 'N' ): "; cin >> usrResponce;
		cin.clear(); cin.ignore(10000, '\n');
		
		if (islower(usrResponce[0])) { usrResponce[0] = toupper(usrResponce[0]); }
	}
	if (usrResponce == YES) { 
		ifstream file(MY_OUTPUT_1);
		if (file.good()) {
			file.close();
			remove(MY_OUTPUT_1.c_str());
		}

		file.open(MY_OUTPUT_2);
		if (file.good()) {
			file.close();
			remove(MY_OUTPUT_2.c_str());
		}
		cout << "All files removed" << endl;
	}
	cout << "\n*********End of Tests*********" << endl;
	cout << "Run valgrind for any memory leaks" << endl;
	
	return 0;
}

