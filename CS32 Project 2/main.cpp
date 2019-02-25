// CS32 Project 2
// Jaehyeong Lee
// Completed on 7/18/2018

#include "CoachingStaff.h"
#include <string>
#include <iostream>
#include <cassert>

void noCoaches_TEST()
{

	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj1.noCoaches() == 1);
	assert(obj2.noCoaches() == 0);
	std::cout << "Passed all tests" << std::endl;
}

void numberOfCoaches_TEST()
{
	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");
	obj2.hireCoach("", "Schoff", "46");
	obj2.hireCoach("Steven", "", "60");
	obj2.hireCoach("David", "Schoff", "46");
	
	assert(obj2.numberOfCoaches() == 4);
	assert(obj1.numberOfCoaches() == 0);
	std::cout << "Passed all tests" << std::endl;
}

void hireCoach_TEST()
{
	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");
	
	assert(obj2.hireCoach("Steven", "Gaby", "56") == 0);
	assert(obj2.hireCoach("Steven", "Gaby", "60") == 0);
	assert(obj1.hireCoach("", "Davidson", "25") == 1);
	std::cout << "Passed all tests" << std::endl;
}

void renameCoach_TEST()
{
	IType value1, value2;
	std::string first, last;

	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj2.renameCoach("Steven", "Gaby", value1) == 1 && obj2.whichCoach(0, first, last, value2) && value1 == value2);
	assert(obj1.renameCoach("Steven", "Gaby", value1) == 0);
	std::cout << "Passed all tests" << std::endl;
}

void hireOrRename_TEST()
{
	IType value1, value2;
	std::string first, last;

	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj2.renameCoach("Steven", "Gaby", value1) == 1 && obj2.whichCoach(0, first, last, value2) && value1 == value2);
	assert(obj1.renameCoach("Steven", "", value1) == 0);
	std::cout << "Passed all tests" << std::endl;
}

void fireCoach_TEST()
{
	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj2.fireCoach("Steven", "Gaby") == 1);
	assert(obj2.fireCoach("David", "Hogg") == 0);
	assert(obj1.fireCoach("", "") == 0);
	std::cout << "Passed all tests" << std::endl;
}

void coachOnStaff_TEST()
{
	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj2.coachOnStaff("Steven", "Gaby") == 1);
	assert(obj2.coachOnStaff("David", "") == 0);
	assert(obj1.coachOnStaff("Jennifer", "Nguyen") == 0);
	std::cout << "Passed all tests" << std::endl;
}

void findCoach_TEST()
{
	IType value;
	IType value2 = "5";

	CoachingStaff obj1, obj2;
	obj2.hireCoach("Steven", "Gaby", "56");

	assert(obj2.findCoach("Steven", "Gaby", value) == 1 && value == "56");
	assert(obj2.findCoach("", "Hawking", value) == 0 && value == "56");
	assert(obj2.findCoach("David", "Hogg", value2) == 0 && value2 == "5");
	std::cout << "Passed all tests" << std::endl;
}

void whichCoach_TEST()
{
	std::string first, last;
	IType value;
	
	CoachingStaff obj1;
	obj1.hireCoach("Gabriel", "Mandez", "26");
	obj1.hireCoach("Jay", "", "27");
	obj1.hireCoach("Chris", "Choi", "26");
	obj1.hireCoach("", " ", "30");

	assert(obj1.whichCoach(-1, first, last, value) == 0);
	assert(obj1.whichCoach(0, first, last, value) && first == "" && last == " " && value == "30");
	assert(obj1.whichCoach(1, first, last, value) && first == "Chris" && last == "Choi" && value == "26");
	assert(obj1.whichCoach(2, first, last, value) && first == "Jay" && last == "" && value == "27");
	assert(obj1.whichCoach(3, first, last, value) && first == "Gabriel" && last == "Mandez" && value == "26");
	assert(obj1.whichCoach(4, first, last, value) == 0);
	std::cout << "Passed all tests" << std::endl;
}

void changeStaff_TEST()
{
	std::string first, last;
	IType value;

	CoachingStaff obj1, obj2;
	obj1.hireCoach("Gabriel", "Mandez", "26");
	obj1.hireCoach("Jay", "", "27");
	obj1.hireCoach("Chris", "Choi", "26");
	obj1.hireCoach("", " ", "30");

	obj2.hireCoach("Steven", "Gaby", "56");
	obj2.hireCoach("Steven", "Gaby", "60");
	obj2.hireCoach("", "Davidson", "25");

	obj1.changeStaff(obj2);

	assert(obj1.whichCoach(0, first, last, value) && first == "" && last == "Davidson" && value == "25");
	assert(obj1.whichCoach(1, first, last, value) && first == "Steven" && last == "Gaby" && value == "56");

	assert(obj2.whichCoach(0, first, last, value) && first == "" && last == " " && value == "30");
	assert(obj2.whichCoach(1, first, last, value) && first == "Chris" && last == "Choi" && value == "26");
	assert(obj2.whichCoach(2, first, last, value) && first == "Jay" && last == "" && value == "27");
	assert(obj2.whichCoach(3, first, last, value) && first == "Gabriel" && last == "Mandez" && value == "26");
	std::cout << "Passed all tests" << std::endl;
}

void mergeStaffs_TEST()
{
	std::string first, last;
	IType value;

	CoachingStaff obj1, obj2, merged;
	obj1.hireCoach("Gabriel", "Mandez", "26");
	obj1.hireCoach("Jay", "", "27");
	obj1.hireCoach("Chris", "Choi", "26");
	obj1.hireCoach("", " ", "30");

	obj2.hireCoach("Gabriel", "Mandez", "30");
	obj2.hireCoach("Jay", "", "27");
	obj2.hireCoach("", "Davidson", "25");

	mergeStaffs(obj1, obj2, merged);
	
	assert(merged.numberOfCoaches() == 4);
	assert(merged.whichCoach(0, first, last, value) && first == "" && last == " " && value == "30");
	assert(merged.whichCoach(1, first, last, value) && first == "Chris" && last == "Choi" && value == "26");
	assert(merged.whichCoach(2, first, last, value) && first == "" && last == "Davidson" && value == "25");
	assert(merged.whichCoach(3, first, last, value) && first == "Jay" && last == "" && value == "27");
	std::cout << "Passed all tests" << std::endl;
}

void searchStaffs_TEST()
{
	std::string first, last;
	IType value;

	CoachingStaff obj1, obj2, result;
	obj1.hireCoach("Gabriel", "Mandez", "26");
	obj1.hireCoach("Jennifer", "Nguyen", "27");
	obj1.hireCoach("Chris", "Mandez", "26");
	obj1.hireCoach("Peter", "David", "30");

	obj2.hireCoach("Gibb", "David", "30");
	obj2.hireCoach("Jennifer", "Kim", "40");
	obj2.hireCoach("Gibb", "Nguyen", "26");

	searchStaff("*", "Mandez", obj1, result);
	assert(result.whichCoach(0, first, last, value) && first == "Chris" && last == "Mandez");
	assert(result.whichCoach(1, first, last, value) && first == "Gabriel" && last == "Mandez");

	searchStaff("Gibb", "*", obj2, result);

	assert(result.whichCoach(0, first, last, value) && first == "Gibb" && last == "David");
	assert(result.whichCoach(1, first, last, value) && first == "Gibb" && last == "Nguyen");

	result.hireCoach("Jordan", "Peter", "62");

	searchStaff("*", "*", obj2, result);

	assert(result.whichCoach(0, first, last, value) && first == "Gibb" && last == "David");
	assert(result.whichCoach(1, first, last, value) && first == "Jennifer" && last == "Kim");
	assert(result.whichCoach(2, first, last, value) && first == "Gibb" && last == "Nguyen");

	std::cout << "Passed all tests" << std::endl;
}

int main()
{ 

	noCoaches_TEST();
	numberOfCoaches_TEST();
	hireCoach_TEST();
	renameCoach_TEST();
	fireCoach_TEST();
	coachOnStaff_TEST();
	findCoach_TEST();
	whichCoach_TEST();
	changeStaff_TEST();
	mergeStaffs_TEST();
	searchStaffs_TEST();

	return 0;
}