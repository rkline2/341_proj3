#include "HashedSplays.h"

HashedSplays::HashedSplays() { m_trees = 0; table.resize(0); }

HashedSplays::HashedSplays(int num) {
    if (num < 0 || num > ALPHABET_SIZE) { throw Exceptions("Table index out of bounds"); }
    m_trees = num;
	table.resize(num);
}

HashedSplays::~HashedSplays() {
	table.clear();
}

vector<SplayTree<Node>>& HashedSplays::GetTable() { return table; }

int HashedSplays::GetNumTrees() { return m_trees; }

void HashedSplays::FileReader(string filename) {
    Util helpUtil; ifstream file; string line;

    cout << "Building hashed splay..." << endl;
    // checks if file exists
	if (!helpUtil.FileExists(filename.c_str())) { throw Exceptions("Filename does not exist"); }
    file.open(filename);
    while (getline(file, line)) {
        // only passes in non-blank lines

        if (line.size() > 0) {
            FilterLine(line);
        }
    }
    file.close();
}

void HashedSplays::PrintTree(string indexVal) {
    int indexNum = GetIndex(indexVal);
    if (indexNum != INVALID_INDEX) { 
        table.at(indexNum).printTree();
        cout << "This tree has " << table.at(indexNum).GetSplayCount() << " splays" << endl;
    }
    else { cout << "Entered index is not valid" << endl; }
}

void HashedSplays::PrintTree(int indexNum) {
    if (indexNum >= 0 && indexNum <= m_trees) { 
        table.at(indexNum).printTree(); 
        cout << "This tree has " << table.at(indexNum).GetSplayCount() << " splays" << endl;
    }
    else { cout << "Entered index is not valid" << endl; }
}

void HashedSplays::PrintHashCountResults() {
    for (int i = 0; i < m_trees; i++) {
        table.at(i).PrintResults();
    }
}

void HashedSplays::FindAll(string val) {
    int indexVal = GetIndex(val);
    if (indexVal != INVALID_INDEX) {
        cout << "Printing the results of nodes that start with \'" << val << "\'" << endl;
        table.at(indexVal).FindAll(val);
    }
    else { cout << "Invalid input" << endl; }
}

int HashedSplays::GetIndex(string val) {
    char topVal = val[0];

    if (islower(topVal)) { topVal = toupper(topVal); }

    // indexVal must be a value from A-Z 
    if (!isalpha(topVal)) { return INVALID_INDEX; }

    return topVal - MIN_UPPER;
}


// Name: FilterLine
// Given a string, splits and filters a line from a .txt file
void HashedSplays::FilterLine(string& line) {
    // line must contain at least one character
    if (line.size() != 0) {
        char* currChar = &line[0]; string word = "";
        int maxVal = line.size();

        while (currChar != &line[maxVal]) {
            // must be a valid char
            if (*currChar >= ASCII_MIN_CHAR && *currChar <= ASCII_MAX_CHAR) {
                
                /**************************************BACKUPS**************************************
                // lowercase curr char
                if (!ispunct(*currChar) && isupper(*currChar)) {
                    *currChar = tolower(*currChar);
                }

                if (*currChar != DELIM && (!ispunct(*currChar) || (*currChar == DASH && currChar != &line[maxVal]))
                    && !isdigit(*currChar)) {
                    word.push_back(*currChar);
                }
               
                else if ((*currChar == DELIM || *currChar == APOST) && word != WORD_SP && word != EMPTY_STR) {
                    InsertWord(word);
                }
                **************************************BACKUPS**************************************/
                // build word
                if (isalpha(*currChar) || *currChar == DASH || *currChar == APOST) { word.push_back(*currChar); }
                
                // word is created
                else if ( ((*currChar < MAX_ESCAPE_SEQ) || (*currChar == DEL_ESCAPE_SEQ))
                    && word != WORD_SP && word != EMPTY_STR) {
                    InsertWord(word);
                }
            }
            currChar++;
        }

        if (word != EMPTY_STR) {
           
            InsertWord(word);
        }

    }
}

// Name: InsertWord
// Given a string, inserts a word into the vector table 
void HashedSplays::InsertWord(string& word) {
    int frontIndex = 0, endIndex, tableIndex; 
    char* frontVal = &word[frontIndex], * endVal = nullptr;

    // removes any unwanted puncts at the front the word
    while (frontVal != nullptr && ispunct(*frontVal)) {
        word.erase(frontIndex, frontIndex + 1);
        frontVal = &word[frontIndex];
    }

    if (word.length() != 0) {
        endIndex = word.length() - 1; endVal = &word[endIndex];

        // removes any unwanted punct at the end the word
        while (endVal != nullptr && ispunct(*endVal)) {
            word.erase(endIndex);
            endIndex = word.length() - 1; endVal = &word[endIndex];
        }
                
        // retrieve index number 
        tableIndex = GetIndex(word);

        // determines if tableIndex is valid or not 
        if (tableIndex != INVALID_INDEX) {
            Node temp(word, 1);

            // current word is not found in the splay tree 
            if (!table.at(tableIndex).contains(temp)) {
                table.at(tableIndex).insert(temp);
            }

            // current word is found in the splay tree
            else { table.at(tableIndex).IncrementFreq(temp); }
        
        }
    }
    word.clear();
}
