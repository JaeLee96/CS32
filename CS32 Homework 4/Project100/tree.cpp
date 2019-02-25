#include "tree.h"


// default constructor
WordTree::WordTree() : root(nullptr)
{}

// copy constructor
WordTree::WordTree(const WordTree& rhs)
{
	root = HelperFunc(rhs.root);
}

// assignment operator
const WordTree& WordTree::operator=(const WordTree& rhs)
{
	if (this == &rhs) return *this;

	deleteTree(root);
	root = HelperFunc(rhs.root);
	return *this;
}

// Inserts v into the WordTree
void WordTree::add(IType v)
{
	insertNode(v, root);
}

// Returns the number of distinct words / nodes
int WordTree::distinctWords() const
{
	return numOfDistinctWords(root);
}


// Returns the total number of words inserted, including
// duplicate values
int WordTree::totalWords() const
{
	return countWords(root);
}


// Prints the LinkedList
ostream& operator<<(ostream &out, const WordTree&
	rhs)
{
	out << rhs.printAllData(rhs.root);
	return out;
}

// Destroys all the dynamically allocated memory in the
// tree

WordTree::~WordTree()
{
	deleteTree(root);
}


// -------------------------------HELPER FUNCTIONS------------------------------------//

WordNode * WordTree::HelperFunc(const WordNode * node)
{
	if (node == nullptr) return nullptr;

	WordNode * newNode = new WordNode(node->m_data, node->count);

	newNode->m_left = HelperFunc(node->m_left);
	newNode->m_right = HelperFunc(node->m_right);

	return newNode;

}

void WordTree::insertNode(IType word, WordNode *&root)		// ** YOU DO NOT USE AMPERSAND THEY WILL NOT POINT TO SAME ADDRESS BECAUSE POINTER PASSED
{															//	AS AN ARGUMENT POINTS TO NULL POINTER AND YOU CAN'T DYNAMICALLY ALLOCATE TO NULL ADDRESS
															//	AND REMEMBER ROOT IS A LOCAL POINTER 
	if (root == nullptr)
	{
		root = new WordNode(word, 1);
		root->m_left = nullptr;
		root->m_right = nullptr;
		return;
	}

	if (root->m_right == nullptr && root->m_left == nullptr)
	{

		if (word < root->m_data) {

			WordNode * p = new WordNode(word, 1);
			p->m_left = root->m_left;
			p->m_right = root->m_right;
			root->m_left = p;
		}
		else if (word > root->m_data) {

			WordNode * p = new WordNode(word, 1);
			p->m_left = root->m_left;
			p->m_right = root->m_right;
			root->m_right = p;
		}
		else root->count++;

		return;
	}

	if (word < root->m_data)
		insertNode(word, root->m_left);
	else if (word > root->m_data)
		insertNode(word, root->m_right);
	else
	{
		root->count++;
		return;
	}
}

IType WordTree::printAllData(WordNode * root) const
{
	IType s = "";

	if (root == nullptr) return s;

	return s = s + printAllData(root->m_left) + root->m_data + " " +
		to_string(root->count) + "\n" + printAllData(root->m_right);
}


int WordTree::numOfDistinctWords(const WordNode * root) const
{
	if (root == nullptr) return 0;

	int count = 1;

	return count = count + numOfDistinctWords(root->m_left) +
		numOfDistinctWords(root->m_right);
}

void WordTree::deleteTree(WordNode * root)
{
	if (root == nullptr) return;

	deleteTree(root->m_left);
	deleteTree(root->m_right);

	delete root;
	root = nullptr;
}


int WordTree::countWords(const WordNode * root) const
{
	if (root == nullptr) return 0;

	int totalN = root->count;

	return totalN = totalN + countWords(root->m_left) + countWords(root->m_right);
}
