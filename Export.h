#ifndef EXPORT_H
#define EXPORT_H
#include "HashedSplays.h"
#include <fstream>
class Export : public HashedSplays {
public:
	Export(string filename, HashedSplays& splay) {
		m_file.open(filename);
		if (m_file.fail()) { throw Exceptions("Export filename is not valid"); }
		m_ExportTable = &splay.GetTable();
		m_fileName = filename;
		m_file << "Building hashed splay..." << endl;
	}

	~Export() {
		m_file.close();
		m_ExportTable = nullptr;
	}

	void ExportHashCountResults() {
		for (int i = 0; i < m_ExportTable->size(); i++) {
			m_ExportTable->at(i).ExportResults(m_file);
		}
	}

	void ExportTree(string index_str) {
		int indexNum = GetIndex(index_str);
		if (indexNum != INVALID_INDEX) {
			m_ExportTable->at(indexNum).ExportTree(m_file);
			m_file << "This tree has " << m_ExportTable->at(indexNum).GetSplayCount() << " splays" << endl;
		}
		else { m_file << "Entered index is not valid" << endl; }
	}

	void ExportTree(int indexNum) {
		if (indexNum >= 0 && indexNum <= m_ExportTable->size()) {
			m_ExportTable->at(indexNum).ExportTree(m_file);
			m_file << "This tree has " << m_ExportTable->at(indexNum).GetSplayCount() << " splays" << endl;
		}
		else { m_file << "Entered index is not valid" << endl; }
	}

	void ExportAll(string val) {
		int indexVal = GetIndex(val);
		if (indexVal != INVALID_INDEX) {
		m_file << "Printing the results of nodes that start with \'" <<
			val << "\'" << endl;
		m_ExportTable->at(indexVal).ExportAll(val, m_file);
		}
		else { m_file << "Invalid input" << endl; }
	}

	void CheckWork(string sourceFileName) {
		m_file.close(); int lineNum = 1; bool isValid = true;
		ifstream myFile(m_fileName), validFile(sourceFileName);
		string myOutput, sourceOutput;
		cout << "Checking work..." << endl;

		while (getline(myFile, myOutput) && getline(validFile, sourceOutput)) {
			if (myOutput != sourceOutput) { 
				cout << "Error lines do not match: " << endl;
				cout << "Line number: " << lineNum << endl;
				cout << "My output: " << myOutput << endl;
				cout << "Source output: " << sourceOutput << endl << endl;
				isValid = false;
			}
			if (isValid) { lineNum++; }
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
	ofstream m_file;
	vector<SplayTree<Node>>* m_ExportTable;
	string m_fileName;
};

#endif
