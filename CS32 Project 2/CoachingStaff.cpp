#include <iostream>
#include "CoachingStaff.h"

CoachingStaff::CoachingStaff() : head(nullptr), tail(nullptr) {}

CoachingStaff::CoachingStaff(const CoachingStaff& obj)
{
	if (obj.head == nullptr) return;

	Node* objptr = obj.head;

	head = tail = new Node;
	head->previous = nullptr;
	head->first_name = objptr->first_name;
	head->last_name = objptr->last_name;
	head->scores = objptr->scores;

	while (objptr->next != nullptr)
	{
		tail->next = new Node;
		tail->next->first_name = objptr->next->first_name;
		tail->next->last_name = objptr->next->last_name;
		tail->next->scores = objptr->next->scores;

		tail = tail->next;
		objptr = objptr->next;
	}
	tail->next = nullptr;
}

CoachingStaff& CoachingStaff::operator=(const CoachingStaff& obj)
{
	if (this == &obj) return *this;
	if (obj.head == nullptr)
	{
		this->head = obj.head;
		return *this;
	}

	else
	{
		if (head != nullptr)
		{
			Node* deleteptr = head;
			Node* temp;

			while (deleteptr != nullptr)
			{
				temp = deleteptr;
				deleteptr = deleteptr->next;
				delete temp;
			}
			head = tail = nullptr;
		}

		Node* objptr = obj.head;

		head = tail = new Node;
		head->first_name = objptr->first_name;
		head->last_name = objptr->last_name;
		head->scores = objptr->scores;
		head->previous = head->next = nullptr;

		while (objptr->next != nullptr)
		{
			Node* addNode = new Node;
			addNode->next = tail->next;
			addNode->previous = tail;
			tail->next = addNode;	
																	// need to double link it
			tail->next->first_name = objptr->next->first_name;
			tail->next->last_name = objptr->next->last_name;
			tail->next->scores = objptr->next->scores;

			tail = tail->next;
			objptr = objptr->next;
		}
	}

	return *this;
}


CoachingStaff::~CoachingStaff()
{
	Node* deleteptr = head;
	Node* temp;

	while (deleteptr != nullptr)
	{
		temp = deleteptr;
		deleteptr = deleteptr->next;
		delete temp;
	}
	head = tail = nullptr;
}

bool CoachingStaff::noCoaches() const
{
	if (head == nullptr || tail == nullptr) return true;
	return false;
}
// Return true if the CoachingStaff list
// is empty, otherwise false.

int CoachingStaff::numberOfCoaches() const
{
	int size = 0;
	Node* headptr = head;

	while (headptr != nullptr)
	{
		headptr = headptr->next;
		size++;
	}
	return size;
}
// Return the number of elements in
// the CoachingStaff list.

bool CoachingStaff::hireCoach(const std::string& firstName, const std::string&
	lastName, const IType& value)
{
	if (coachOnStaff(firstName, lastName)) return false;		// if full name is found

	Node* newNode = new Node;                // Create new node
	newNode->first_name = firstName;
	newNode->last_name = lastName;
	newNode->scores = value;

	if (noCoaches())
	{
		head = tail = newNode;				// if the list is empty
		head->next = nullptr;
		head->previous = nullptr;
		return true;
	}

	Node* headptr = head;
	while (headptr != nullptr)
	{
		if ((lastName + firstName) < (headptr->last_name + headptr->first_name))
		{
			newNode->previous = headptr->previous;
			newNode->next = headptr;
			if (headptr->previous != nullptr)
				headptr->previous->next = newNode;
			headptr->previous = newNode;

			if (headptr == head) head = newNode; // if very first node is greater than the input names, you need to move head pointer
			return true;         // otherwise head pointer stays the same
		}
		headptr = headptr->next;
	}

	if (headptr == nullptr)
	{
		newNode->next = tail->next;      // if the name is larger than all other names
		tail->next = newNode;
		newNode->previous = tail;
		tail = tail->next;
		return true;
	}
}

// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return
// true. Elements should be added according to their last name.
// Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the
// list).


bool CoachingStaff::renameCoach(const std::string& firstName, const std::string&
	lastName, const IType& value)
{
	Node* headptr = head;
	while (headptr != nullptr)
	{
		if (headptr->first_name == firstName && headptr->last_name == lastName) {
			headptr->scores = value;
			return true;
		}
		headptr = headptr->next;
	}
	return false;
}

// If the full name is equal to a full name currently in the
// list, then make that full name no longer map to the value it
// currently maps to, but instead map to the value of the third 
// parameter; return true in this case. Otherwise, make no
// change to the list and return false.
bool CoachingStaff::hireOrRename(const std::string& firstName, const std::string&
	lastName, const IType& value)
{
	bool emptyCoach = coachOnStaff(firstName, lastName);

	if (emptyCoach) {
		renameCoach(firstName, lastName, value);
		return true;
	}
	else {
		hireCoach(firstName, lastName, value);
		return true;
	}
}

// If full name is equal to a name currently in the list, then
// make that full name no longer map to the value it currently
// maps to, but instead map to the value of the third parameter;
// return true in this case. If the full name is not equal to
// any full name currently in the list then add it and return
// true. In fact, this function always returns true.
bool CoachingStaff::fireCoach(const std::string& firstName, const std::string&
	lastName)
{
	if (head == nullptr) return false;

	Node* headptr = head;
	while (headptr != nullptr)
	{
		if (headptr->first_name == firstName && headptr->last_name == lastName)
		{
			if (numberOfCoaches() == 1) {
				delete head;
				head = tail = nullptr;
				return true;
			}

			if (headptr->next != nullptr)
				headptr->next->previous = headptr->previous;

			if (headptr->previous != nullptr)
				headptr->previous->next = headptr->next;

			if (headptr->previous == nullptr)
				head = headptr->next;

			delete headptr;
			return true;
		}
		headptr = headptr->next;
	}
	return false;
}

// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return
// true. Otherwise, make no change to the list and return
// false.
bool CoachingStaff::coachOnStaff(const std::string& firstName, const std::string&
	lastName) const
{
	Node* headptr = head;
	while (headptr != nullptr) {
		if (headptr->first_name == firstName && headptr->last_name == lastName) return true;
		headptr = headptr->next;
	}
	return false;
}

// Return true if the full name is equal to a full name
// currently in the list, otherwise false.
bool CoachingStaff::findCoach(const std::string& firstName, const std::string&
	lastName, IType& value) const
{
	Node* headptr = head;
	while (headptr != nullptr) {
		if (headptr->first_name == firstName && headptr->last_name == lastName) {
			value = headptr->scores;
			return true;
		}
		headptr = headptr->next;
	}
	return false;
}

// If the full name is equal to a full name currently in the
// list, set value to the value in the list that that full name
// maps to, and return true. Otherwise, make no change to the
// value parameter of this function and return false.
bool CoachingStaff::whichCoach(int i, std::string& firstName, std::string&
	lastName, IType& value) const
{
	int index = i;
	if (head == nullptr || index < 0 || index >= numberOfCoaches()) return false;
	Node* headptr = head;

	for (int i = 0; i < index; i++)
		headptr = headptr->next;

	firstName = headptr->first_name;
	lastName = headptr->last_name;
	value = headptr->scores;

	return true;
}

// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the
// parameters unchanged and return false. (See below for details
// about this function.)

void CoachingStaff::changeStaff(CoachingStaff& other)
{
	if (this == &other) return;

	if (head == nullptr && other.head == nullptr) return;
	else if (head == nullptr && other.head != nullptr)
	{
		*this = other;
		return;
	}
	else if (head != nullptr && other.head == nullptr)
	{
		other = *this;
		return;
	}
	else
	{
		CoachingStaff temp = *this;
		*this = other;
		other = temp;
		return;
	}
}

// Exchange the contents of this list with the other one.

bool mergeStaffs(const CoachingStaff & csOne,
	const CoachingStaff & csTwo,
	CoachingStaff & csMerged)
{
	if (csOne.noCoaches() && !csTwo.noCoaches())
	{
		csMerged = csTwo;
		return true;
	}

	if (!csOne.noCoaches() && csTwo.noCoaches())
	{
		csMerged = csOne;
		return true;
	}
	
	else if (csOne.noCoaches() && csTwo.noCoaches())
	{
		csMerged = csOne;
		return true;
	}

	csMerged = csOne;

	int csMergedSize = csMerged.numberOfCoaches();
	int csOneSize = csOne.numberOfCoaches();
	int csTwoSize = csTwo.numberOfCoaches();

	std::string first1, last1;
	IType value1;

	std::string first2, last2;
	IType value2;

	bool T = true;

	for (int i = 0; i < csTwoSize; i++)				// before adding new item to merged, the item has to be checked with every element in csOne
	{
		csTwo.whichCoach(i, first2, last2, value2);
		int flag = 2;

		for (int j = 0; j < csOneSize; j++)
		{
			csOne.whichCoach(j, first1, last1, value1);
			
			if (((first1 + last1) == (first2 + last2)) && (value1 == value2))	// if same item is found do not add 
			{
				flag = 0;
				break;
			}
			else if (((first1 + last1) == (first2 + last2)) && (value1 != value2))	// if item with same name but different value is found, delete
			{
				flag = 1;
				T = false;
				break;
			}
		}

		switch (flag)
		{
		case 0:
			break;										
		case 1:
			csMerged.fireCoach(first2, last2);	
			break;
		default:
			csMerged.hireCoach(first2, last2, value2);	
		}
	}

	return T;
}

void searchStaff(const std::string& fsearch,
	const std::string& lsearch,
	const CoachingStaff& csOne,
	CoachingStaff& csResult)
{
	std::string first, last;
	IType value;
	int csOneSize = csOne.numberOfCoaches();

	csResult = csOne;

	if (fsearch == "*" && lsearch != "*")
	{
		for (int i = 0; i < csOneSize; i++)
		{
			csResult.whichCoach(i, first, last, value);
			if (last != lsearch)
				csResult.fireCoach(first, last);
		}
		return;
	}

	if (fsearch != "*" && lsearch == "*")
	{
		for (int i = 0; i < csOneSize; i++)
		{
			csResult.whichCoach(i, first, last, value);
			if (first != fsearch)
				csResult.fireCoach(first, last);
		}
		return;
	}
	else if (fsearch == "*" && lsearch == "*") return;
	else
	{
		for (int i = 0; i < csOneSize; i++)
		{
			csResult.whichCoach(i, first, last, value);
			if (first != fsearch || last != lsearch)
				csResult.fireCoach(first, last);
		}
		return;
	}
}

