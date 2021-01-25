# Hashed Word Frequency Splay Tree
## Objective:  
The objective of this programming assignment is to have you practice using recursion and iteration in your programs 
and to familiarize you with the Splay tree data structure.

## Application Setup:  
Using a loosely hashed Splay Tree and a file with sample text, you will organize a tree with the data given. 
The hashed portion with contain 26 individual Splay Trees, for each of the letters. ‘A’ and ‘a’ will be stored in index 0,’B’ and 
‘b’ in index 1, and so forth. The order of whatever text in the file read in will determine the structure of the tree. 

Since the text many contain the same word several times, the tree will also contain how many times the word appears, it will NOT 
contain the same word in multiple nodes and case must be preserved. Any methods added to the Splay Tree will need to be generic. The features we 
will ask you to create will be used test how efficient your tree is. 

## Hashed Table Data Structure  
The base data structure that will hold all of the Splay Trees will be an Array called “table”. The size of the table will be 26 
(one for each letter A/a, B/b, etc…) for our application, but notice you should set the length from whatever is creating in instance 
of the array. (In our example, Driver.cpp will be creating the instance of the HashedSplay called wordFrequency.) 

Within each index of the array, a Splay Tree will be created. That lone Splay Tree will contain only the words that start 
with a particular letter.  Again, all words starting with “A” or “a” will go into the 0 index.

## Print HashTable Results Application  
This will be used as a grading test. Using the entire array “table” and named printHashCountResults(), this will 
print the root value (to the screen) at each index in order and display how many nodes each tree contains. 
The results will look like below:

This tree starts with Node [word=a, frequency=7] and has 22 nodes<br>
This tree starts with Node [word=be, frequency=7] and has 12 nodes<br>
This tree starts with Node [word=Contributors, frequency=2] and has 18 nodes<br>
This tree starts with Node [word=Donate, frequency=1] and has 16 nodes<br>
This tree starts with Node [word=eliminate, frequency=1] and has 8 nodes<br>
This tree starts with Node [word=following, frequency=1] and has 14 nodes<br>
This tree starts with Node [word=GPLv, frequency=1] and has 4 nodes<br>
This tree starts with Node [word=httpexamplecom, frequency=1] and has 11 nodes<br>
This tree starts with Node [word=is, frequency=19] and has 16 nodes<br>
This tree starts with Node [word=just, frequency=1] and has 3 nodes<br>
This tree starts has no nodes<br>
This tree starts with Node [word=list, frequency=5] and has 12 nodes<br>
