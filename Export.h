/**************************************************************
 * File:    Export.h
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * Export Class definition.
 *
 * This class provides export functions based on what 
 * HashedSplays.h's functions would normally display
 *
 * void ExportHashCountResults() - Export the root of each index and number of nodes
 * void ExportTree(string index_str) - Exports a single splay tree from the table 
 * void ExportTree(int indexNum) - Exports a single splay tree from the table 
 * void ExportAll(string val) - Exports words in a splay tree that start with the given parameter 
 * void CheckWork(string sourceFileName) - Checks if the programs output is the same as the given output 
 *
 *************************************************************/

#ifndef EXPORT_H
#define EXPORT_H
#include "HashedSplays.h"
#include <fstream>
class Export : private HashedSplays {
public:

	// Name: Export (constructor) 
	// Description: Create a file with the given filename and
	// deep copies the table at HashedPlays.h to m_ExportTable
	// Pre-Conditions: Given filename and splay are valid  
	// Post-Conditions: Creates a new splay table and sets m_fileName 
	Export(string filename, HashedSplays& splay) {
		m_file.open(filename); const int SOURCE_NUM_TREES = splay.GetNumTrees();
		
		// Given values must be valid
		if (m_file.fail() || (SOURCE_NUM_TREES <= 0 || SOURCE_NUM_TREES > ALPHABET_SIZE) ) { 
			throw Exceptions("Given values for Export object are not valid");
		}

		splay.CpyTable(m_ExportTable);
		m_fileName = filename;

		// Need to initalize m_numtrees for empty HashedSplay for GetIndex()  
		SetNumTrees(splay.GetNumTrees());
		m_file << "Building hashed splay..." << endl;
	}

	// Name: ~Export (destructor)
	// Description: Deletes m_ExportTable and closes m_file
	// Pre-Conditions: m_file and m_ExportTable exists
	// Post-Conditions: Closes m_file and deletes m_ExportTable 
	~Export() {
		m_file.close();
		m_ExportTable->clear();

		delete m_ExportTable;
		m_ExportTable = nullptr;
	}

	// Name: ExportHashCountResults
	// Description: Export the root of each index and the number of nodes
	// Pre-Conditions: m_file and m_ExportTable exists
	// Post-Conditions: Export the root of each index and the number of nodes
	void ExportHashCountResults() {
		const int MAX_SIZE = m_ExportTable->size();
		for (int i = 0; i < MAX_SIZE; i++) {
			m_ExportTable->at(i).ExportRoot(m_file);
		}
	}

	// Name: ExportTree (string)
	// Description: Exports a single splay tree from the table based on the given parameter
	// Pre-Conditions: m_file and m_ExportTable exists. Parameter is valid
	// Post-Conditions: Exports a single splay tree from the table based on the given parameter
	void ExportTree(string index_str) {
		int indexNum = GetIndex(index_str);

		if (indexNum != INVALID_INDEX) {
			m_ExportTable->at(indexNum).ExportTree(m_file);
			m_file << "This tree has had " << m_ExportTable->at(indexNum).GetSplayCount() << " splays." << endl;
		}
		else {
			cout << "-----Invalid Argument for ExportTree-----" << endl;
			m_file << "-----ExportTree Function Did Not Run Here-----" << endl;
		}
	}

	// Name: ExportTree (int)
	// Description: Exports a single splay tree from the table based on the given parameter
	// Pre-Conditions: m_file and m_ExportTable exists. Parameter is valid
	// Post-Conditions: Exports a single splay tree from the table based on the given parameter
	void ExportTree(int indexNum) {
		int tableSize = m_ExportTable->size();
		if (indexNum >= 0 && indexNum <= tableSize) {
			m_ExportTable->at(indexNum).ExportTree(m_file);
			m_file << "This tree has had " << m_ExportTable->at(indexNum).GetSplayCount() << " splays." << endl;
		}
		else { 
			cout << "-----Invalid Argument for ExportTree-----" << endl;
			m_file << "-----ExportTree Function Did Not Run Here-----" << endl;
		}
	}

	// Name: ExportAll
	// Description: Exports words in a splay tree that start with the given parameter
	// Pre-Conditions: m_file and m_ExportTable exists
	// Post-Conditions: Export words in a splay tree that start with the given parameter
	void ExportAll(string val) {
		int indexVal = GetIndex(val);

		if (indexVal != INVALID_INDEX) {
		m_file << "Printing the results of nodes that start with \'" <<
			val << "\'" << endl;
		m_ExportTable->at(indexVal).ExportAll(val, m_file);
		}
		else {
			cout << "-----Invalid Argument for ExportAll-----" << endl;
			m_file << "-----ExportAll Function Did Not Run Here-----" << endl;
		}
	}

	// Name: CheckWork
	// Description: Checks if the programs output is the same as the given output
	// Pre-Conditions: m_filename and given file names are valid 
	// Post-Conditions: Checks if the programs output is the same as the given output
	void CheckWork(string sourceFileName) {
		m_file.close(); int lineNum = 1; bool isValid = true;
		ifstream myFile(m_fileName), validFile(sourceFileName);
		string myOutput, sourceOutput;

		cout << "Checking work..." << endl;
		if (myFile.fail() || validFile.fail()) { throw Exceptions("Export filename(s) is/are not valid"); }

		while (getline(myFile, myOutput) && getline(validFile, sourceOutput)) {
			if (myOutput != sourceOutput) { 
				cout << "Error lines do not match: " << endl;
				cout << "Line number: " << lineNum << endl;
				cout << "My output: " << myOutput << endl;
				cout << "Source output: " << sourceOutput << endl << endl;
				isValid = false;
			}
			lineNum++; 
		}
		
		if (getline(myFile, myOutput)) {
			cout << "Error: My output file is larger than source's output file" << endl;
			isValid = false;
		}
		if (getline(validFile, sourceOutput)) {
			cout << "Error: Source's output file is larger than my output file" << endl;
			isValid = false;
		}

		cout << "End of test: ";
		if (isValid) { cout << "All values are valid" << endl; }
		else { cout << "Values are not valid" << endl; }

		cout << "Stopped at line number: " << lineNum << endl;

		myFile.close(); validFile.close();
	}

private:
  ofstream m_file; // Where all of the exported data will go
  vector<SplayTree<Node>>* m_ExportTable; // Deep copy of table in HashedSplays.h
  string m_fileName; // File name
};

#endif
