#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "dsexceptions.h"
#include "Node.h"
#include <iostream>        // For NULL
using namespace std;

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class SplayTree
{
public:
    SplayTree()
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
        m_numNodes = 0;
        m_splayCount = 0;
    }

    SplayTree(const SplayTree& rhs)
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
        *this = rhs;
        m_numNodes = rhs.m_numNodes;
        m_splayCount = rhs.m_splayCount;
    }

    ~SplayTree()
    {
        makeEmpty();
        delete nullNode;
    }

    /**
     * Find the smallest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     smaller than any item in the tree, then call findMin.
     * Return the smallest item or throw UnderflowException if empty.
     */
    const Comparable& findMin()
    {
        if (isEmpty())
            throw UnderflowException();

        BinaryNode* ptr = root;

        while (ptr->left != nullNode)
            ptr = ptr->left;

        splay(ptr->element, root);
        return ptr->element;
    }

    /**
     * Find the largest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     larger than any item in the tree, then call findMax.
     * Return the largest item or throw UnderflowException if empty.
     */
    const Comparable& findMax()
    {
        if (isEmpty())
            throw UnderflowException();

        BinaryNode* ptr = root;

        while (ptr->right != nullNode)
            ptr = ptr->right;

        splay(ptr->element, root);
        return ptr->element;
    }


    bool contains(const Comparable& x)
    {
        if (isEmpty())
            return false;
        splay(x, root);
        return root->element == x;
    }

    bool isEmpty() const
    {
        return root == nullNode;
    }

    void printTree() const
    {
        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printTree(root);
    }

    void makeEmpty()
    {
        /******************************
         * Comment this out, because it is prone to excessive
         * recursion on degenerate trees. Use alternate algorithm.

            reclaimMemory( root );
            root = nullNode;
         *******************************/
        while (!isEmpty())
        {
            findMax();        // Splay max item to root
            remove(root->element);
        }
    }

    void insert(const Comparable& x)
    {
        static BinaryNode* newNode = NULL;

        if (newNode == NULL) {
            newNode = new BinaryNode;
            SetNumNodes(++m_numNodes);
        }
        newNode->element = x;

        if (root == nullNode)
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay(x, root);
            if (x < root->element)
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else
                if (root->element < x)
                {
                    newNode->right = root->right;
                    newNode->left = root;
                    root->right = nullNode;
                    root = newNode;
                }
                else
                    return;
        }
        newNode = NULL;   // So next insert will call new
    }

   
    void remove(const Comparable& x)
    {
        BinaryNode* newTree;

        // If x is found, it will be at the root
        if (!contains(x))
            return;   // Item not found; do nothing

        if (root->left == nullNode)
            newTree = root->right;
        else
        {
            // Find the maximum in the left subtree
            // Splay it to the root; and then attach right child
            newTree = root->left;
            splay(x, newTree);
            newTree->right = root->right;
        }
        delete root;
        root = newTree;
        SetNumNodes(--m_numNodes);
    }

    const SplayTree& operator=(const SplayTree& rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }

        return *this;
    }
    /*****************************************EXTRA FUNCTIONS*****************************************/
    void IncrementFreq(const Comparable& x) {
        // Desired node will always be at the root of the tree 
        root->element.IncrementFrequency();
        nullNode->element.IncrementFrequency();
    }

    /**************************BACKUPS*************************
    void PrintRoot() {
        if (m_numNodes != 0) {
            cout << "This tree starts with Node [word=" << root->element.GetWord()
                << ", frequency=" << root->element.GetFrequency() << "] and has " << m_numNodes << " nodes" << endl;
        }
        else { cout << "This tree has no Nodes" << endl; }
    }

      void ExportRoot(ofstream& file) {
        if (m_numNodes != 0) {
        file << "This tree starts with Node [word=" << root->element.GetWord()
            << ", frequency=" << root->element.GetFrequency() << "] and has " << m_numNodes << " nodes" << endl;
        }
        else { file << "This tree has no Nodes" << endl; }

    }
    **************************BACKUPS**************************/

    void PrintRoot() const {
        if (m_numNodes != 0) {
            cout << "This tree starts with Node " << PrintRoot(root) <<
                " and has " << m_numNodes << " nodes" << endl;
        }
        else { cout << "This tree has no Nodes" << endl; }
    }

    void ExportRoot(ofstream& file) {
        if (m_numNodes != 0) {
            file << "This tree starts with Node " << ExportRoot(root) <<
                " and has " << m_numNodes << " nodes" << endl;
        }
        else { file << "This tree has no Nodes" << endl; }
    }

    void FindAll(string val) {
        FindAll(root, val);
    }

    void ExportAll(string val, ofstream& file) {
        ExportAll(root, val, file);
    }

    int GetNumNodes() { return m_numNodes; }

    int GetSplayCount() { return m_splayCount; }
   
    void ExportTree(ofstream& file) {
        if (isEmpty()) {
            file << "Empty tree" << endl;
        }
        else {
            ExportTree(root, file);
        }
    }
    /*****************************************EXTRA FUNCTIONS*****************************************/


private:
    struct BinaryNode
    {
        Comparable  element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode() : left(NULL), right(NULL) { }
        BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt) { }
    };

    BinaryNode* root;
    BinaryNode* nullNode;
    int m_numNodes;
    int m_splayCount;

    /**
     * Internal method to reclaim internal nodes in subtree t.
     * WARNING: This is prone to running out of stack space.
     */
    void reclaimMemory(BinaryNode* t)
    {
        if (t != t->left)
        {
            reclaimMemory(t->left);
            reclaimMemory(t->right);
            delete t;
        }
    }

    /**
     * Internal method to print a subtree t in sorted order.
     * WARNING: This is prone to running out of stack space.
     */
    void printTree(BinaryNode* t) const
    {
        if (t != t->left)
        {
            printTree(t->left);
            cout << t->element << endl;
            printTree(t->right);
        }
    }

    /************************EXTRA FUNCTIONS****************************/

    void ExportTree(BinaryNode* t, ofstream& file) const {
        
        if (t != t->left) {
            ExportTree(t->left, file);
            file << t->element << endl;
            ExportTree(t->right, file);
        }
    }

    Comparable& PrintRoot(BinaryNode*t) const {
        return t->element;
    }

    Comparable& ExportRoot(BinaryNode* t) const {
        return t->element;
    }

    /************************EXTRA FUNCTIONS****************************/


    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     */
    BinaryNode* clone(BinaryNode* t) const
    {
        if (t == t->left)  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new BinaryNode(t->element, clone(t->left), clone(t->right));
    }

    // Tree manipulations
    void rotateWithLeftChild(BinaryNode*& k2)
    {
        BinaryNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild(BinaryNode*& k1)
    {
        BinaryNode* k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }

    /**
     * Internal method to perform a top-down splay.
     * The last accessed node becomes the new root.
     * This method may be overridden to use a different
     * splaying algorithm, however, the splay tree code
     * depends on the accessed item going to the root.
     * x is the target item to splay around.
     * t is the root of the subtree to splay.
     */
    void splay(const Comparable& x, BinaryNode*& t)
    {
        BinaryNode* leftTreeMax, * rightTreeMin;
        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x;   // Guarantee a match
        SetSplayCount(++m_splayCount);
        for (; ; )
            if (x < t->element)
            {
                if (x < t->left->element)
                    rotateWithLeftChild(t);
                if (t->left == nullNode)
                    break;
                // Link Right
                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if (t->element < x)
            {
                if (t->right->element < x)
                    rotateWithRightChild(t);
                if (t->right == nullNode)
                    break;
                // Link Left
                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
    }
    /*************************EXTRA FUNCTIONS******************************/
    
    void SetNumNodes(int num) {
        if (num >= 0) {
            m_numNodes = num;
        }
    }


    void SetSplayCount(int num){
        if (num >= 0) {
            m_splayCount = num;
        }
    }
    void FindAll(BinaryNode*& t, string val) {
        if (t != t->left) {
            FindAll(t->left, val);
            if (IsSimilar(t, val)) {
                cout << t->element << endl;
            }
            FindAll(t->right, val);
        }
    }

    void ExportAll(BinaryNode*& t, string val, ofstream& file) {
        if (t != t->left) {
            ExportAll(t->left, val, file);
            if (IsSimilar(t, val)) {
                file << t->element << endl;
            }
            ExportAll(t->right, val, file);
        }
    
    }

    bool IsSimilar(BinaryNode*& t, string val) {
        string wordcpy = t->element.GetWord(); 
        const int VAL_SIZE = val.size(), WORD_SIZE = wordcpy.size();

        // only runs for the values less than or equal to the element's word 
        if (VAL_SIZE <= WORD_SIZE) {
            for (int i = 0; i < VAL_SIZE; i++) {
                if (tolower(wordcpy[i]) != tolower(val[i])) { return false; }
            }
            return true;
        }
        return false;
    }
    /*************************EXTRA FUNCTIONS******************************/
};

#endif
