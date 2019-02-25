#include "linkedlist.h"
#include <iostream>


// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
	head = nullptr;
	int size = this->size();
	const Node* p = rhs.head;

	while (p != nullptr)
	{
		insertToFront(p->value);
		p = p->next;
	}

	this->reverseList();
}

// Destroys all the dynamically allocated memory
// in the list.
LinkedList::~LinkedList()
{
	if (head == nullptr) return;

	Node* temp = head;
	Node* n;

	while (temp != nullptr)
	{
		n = temp;
		temp = temp->next;
		delete n;
	}

	head = nullptr;
}

// assignment operator
const LinkedList&LinkedList::operator=(const LinkedList& rhs)
{
	if (&rhs == this) return *this;
	else if (rhs.head == nullptr) {
		this->~LinkedList();
		return *this;
	}
	else
	{
		this->~LinkedList();

		for (const Node* it = rhs.head; it != nullptr; it = it->next)
			insertToFront(it->value);

		this->reverseList();

		return *this;
	}
}

// Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType &val)
{
	Node* newNode;

	if (this->size() == 0)
	{
		newNode = new Node;
		newNode->value = val;
		newNode->next = nullptr;
		head = newNode;
		return;
	}
	if (this->size() != 0)
	{
		newNode = new Node;
		newNode->value = val;
		newNode->next = head;
		head = newNode;
	}
}

// Prints the LinkedList
void LinkedList::printList() const
{
	if (head == nullptr) return;

	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

// Sets item to the value at position i in this
// LinkedList and return true, returns false if
// there is no element i
bool LinkedList::get(int i, ItemType& item) const
{
	// Position starting from 0
	const int size = this->size();
	if (i < 0 || i >= size) return false;
	else
	{
		Node* nodeptr = head;
		while (i--)
			nodeptr = nodeptr->next;
		item = nodeptr->value;
		return true;
	}
}

// Reverses the LinkedList
void LinkedList::reverseList()
{
	if (size() == 1) return;

	int i = 0;
	const int size = this->size();
	ItemType* p = new ItemType[size];

	for (Node* temp = head; temp != nullptr; temp = temp->next, i++)
		p[i] = temp->value;

	i = size - 1;

	for (Node* temp = head; temp != nullptr; temp = temp->next, i--)
		temp->value = p[i];

	delete[]p;
}

// Prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
	LinkedList temp = *this;
	temp.reverseList();
	temp.printList();
}

// Appends the values of other onto the end of this
// LinkedList.
void LinkedList::append(const LinkedList &other)
{
	if (other.head == nullptr) return;
	if (head == nullptr)
	{
		*this = other;
		return;
	}

	else
	{
		const int size = other.size();

		Node* headptr = other.head;
		Node* tail = head;
		
		while (tail->next != nullptr) // create tail pointer
			tail = tail->next;
		
		ItemType s;

		for (int i = 0; i < size; i++)
		{
			tail->next = new Node;
			tail->next->value = headptr->value;
	
			tail = tail->next;
			headptr = headptr->next;
		}

		tail->next = nullptr;
	}
}

// Exchange the contents of this LinkedList with the other
// one.
void LinkedList::swap(LinkedList &other)
{
	if (this == &other) return;

	Node *temp = head;
	head = other.head;
	other.head = temp;
}

// Returns the number of items in the Linked List.
int LinkedList::size() const
{
	int size = 0;
	const Node* temp = head;

	while (temp != nullptr)
	{
		temp = temp->next;
		size++;
	}

	return size;
}
