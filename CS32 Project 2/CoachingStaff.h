#ifndef COACHINGSTAFF_H
#define COACHINGSTAFF_H

#include <iostream>
#include <string>
typedef std::string IType;

class CoachingStaff
{
private:
	struct Node
	{
		Node* previous;
		Node* next;
		std::string first_name;
		std::string last_name;
		IType scores;
	};

	Node* head;
	Node* tail;

public:
	CoachingStaff(); // Create an empty CoachingStaff list
	CoachingStaff(const CoachingStaff& obj);
	CoachingStaff& operator=(const CoachingStaff& obj);

	~CoachingStaff();

	bool noCoaches() const; // Return true if the CoachingStaff list
							// is empty, otherwise false.

	int numberOfCoaches() const; // Return the number of elements in
								 // the CoachingStaff list.

	bool hireCoach(const std::string& firstName, const std::string&
		lastName, const IType& value);

	bool renameCoach(const std::string& firstName, const std::string&
		lastName, const IType& value);

	bool hireOrRename(const std::string& firstName, const std::string&
		lastName, const IType& value);

	bool fireCoach(const std::string& firstName, const std::string&
		lastName);

	bool coachOnStaff(const std::string& firstName, const std::string&
		lastName) const;

	bool findCoach(const std::string& firstName, const std::string&
		lastName, IType& value) const;

	bool whichCoach(int i, std::string& firstName, std::string&
		lastName, IType& value) const;

	void changeStaff(CoachingStaff& other);
};

bool mergeStaffs(const CoachingStaff & csOne,
	const CoachingStaff & csTwo,
	CoachingStaff & csMerged);

void searchStaff(const std::string& fsearch,
	const std::string& lsearch,
	const CoachingStaff& csOne,
	CoachingStaff& csResult);

#endif // !
