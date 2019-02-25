#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef string IType;

struct WordNode {
	WordNode(IType data, int count) : m_data(data), count(count) {};
	IType m_data;
	int count;
	WordNode *m_left;
	WordNode *m_right;
};

class WordTree {
private:
	WordNode * HelperFunc(const WordNode * node);
	void deleteTree(WordNode * root);
	int countWords(const WordNode * root) const;
	int numOfDistinctWords(const WordNode * root) const;
	IType printAllData(WordNode * root) const;
	void insertNode(IType word, WordNode *&root);
	WordNode *root;

public:
	// default constructor
	WordTree();

	// copy constructor
	WordTree(const WordTree& rhs);

	// assignment operator
	const WordTree& operator=(const WordTree& rhs);

	// Inserts v into the WordTree
	void add(IType v);

	// Returns the number of distinct words / nodes
	int distinctWords() const;

	// Returns the total number of words inserted, including
	// duplicate values
	int totalWords() const;

	// Prints the LinkedList
	friend ostream& operator<<(ostream &out, const WordTree&
		rhs);

	// Destroys all the dynamically allocated memory in the
	// tree
	~WordTree();
};


#endif 
