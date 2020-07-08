#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include <vector>
#include "SplayTree.h"
#include "Node.h"
#include "Util.h"
#include "Exceptions.h"

const int ALPHABET_SIZE = 26, INVALID_INDEX = -1;

class HashedSplays{
public:

	HashedSplays();

	// Name: HashedSplays (overloaded constructor) 
	// Description: Creates an empty splay table of size n
	// Pre-Conditions: None  
	// Post-Conditions: Creates an empty splay table object
	HashedSplays(int);

	// Name: HashedSplays Destructor
	// Description: Deletes any variables associated with HashedSplays 
	// Pre-Conditions: Object exists  
	// Post-Conditions: Deletes the HashedSplays object
	~HashedSplays();

	vector<SplayTree<Node>>& GetTable();

	int GetNumTrees();

	// Name: FileReader 
	// Description: Opens a file and filters the given words 
	// Pre-Conditions: FileName exists  
	// Post-Conditions: Splits and filteres the .txt file into distinct words 
	void FileReader(string);

	// Name: PrintTree (string)
	// Description: Displays a single splay tree from 
	// the table based on the given parameter 
	// Pre-Conditions: Table exists and given value is valid   
	// Post-Conditions: Displays a single splay tree
	void PrintTree(string);
	
	// Name: PrintTree (int)
	// Description: Displays a single splay tree from 
	// the table based on the given parameter 
	// Pre-Conditions: Table exists and given value is valid   
	// Post-Conditions: Displays a single splay tree
	void PrintTree(int);

	// Name: printHashCountResults 
	// Description: Displays the entire table by 
	// displaying the root of each index and the number of nodes 
	// Pre-Conditions: Table exists    
	// Post-Conditions: Displays the entire table
	void PrintHashCountResults();

	// Name: FindAll
	// Description: Displays words in a splays that 
	// start with the given parameter 
	// Pre-Conditions: Splay tree is full and table exists  
	// Post-Conditions: Displays words from a splay tree
	// that start with the given parameter 
	void FindAll(string);

	// Name: GetIndex
	// Description: Returns the index from the 
	// table based on the given parameters 
	// Pre-Conditions: Table exists and given value is valid   
	// Post-Conditions: Returns an index from the table
	int GetIndex(string);

	void FilterLine(string& line);

	void InsertWord(string& word);

private:
	int m_trees; // number of trees   
	vector<SplayTree<Node>> table; // contains all of the splay trees
};
#endif // !HASHEDSPLAYS_H
