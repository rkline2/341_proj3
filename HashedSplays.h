/**************************************************************
 * File:    HashedSplays.h
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * HashedSplays Class definition.
 *
 * This class stores splay trees in the member variable table 
 * and provides displays functions based on the table's data
 *
 *************************************************************/
#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include <vector>
#include "SplayTree.h"
#include "Node.h"
#include "Util.h"
#include "Exceptions.h"

const int ALPHABET_SIZE = 26, INVALID_INDEX = -1; // Index values for table

class HashedSplays{
public:

	// Name: HashedSplays (default constructor) 
	// Description: Creates an empty splay table of size 0 (used for Export.h)
	// Pre-Conditions: None  
	// Post-Conditions: Creates an empty splay table object
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

	// Name: CpyTable
	// Description: Creates a deepcopy of table  
	// Pre-Conditions: Passes in a valid vector pointer   
	// Post-Conditions: Creates a deep copy of table 
	void CpyTable(vector<SplayTree<Node>>*&);

	// Name: GetNumTrees
	// Description: Returns the maximum amount of trees in the splay table 
	// Pre-Conditions: Object exists  
	// Post-Conditions: Returns m_trees
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
	// Description: Displays words in a splay tree that 
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

protected:
	void SetNumTrees(int num) { m_trees = num; }

private:
	
	// Name: FilterLine
	// Description: Given a line from a .txt file, splits and 
	// lowercases every word from the line and removes punctuation 
	// Pre-Conditions: .txt file exists
	// Post-Conditions: Splits and filters a line from a .txt file
	void FilterLine(string& line);

	// Name: InsertWord
	// Description: Inserts a Word into the splay table
	// Pre-Conditions: Table exists and index is valid
	// Post-Conditions: Inserts word into splay table
	void InsertWord(string& word);

	vector<SplayTree<Node>> table; // contains all of the splay trees
	int m_trees; // maximum number of trees in the table   
	
};
#endif // !HASHEDSPLAYS_H