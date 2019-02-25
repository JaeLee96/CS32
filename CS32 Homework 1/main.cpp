// CS32 HW1 
// Created by Jaehyeong Lee
// 7/11/2018

#include <cassert>
#include <iostream>
#include "linkedlist.h"
using namespace std;

void TEST1()
{
	LinkedList ls;
	ls.insertToFront("Steve");
	ls.insertToFront("Judy");
	ls.insertToFront("Laura");
	ls.insertToFront("Eddie");
	ls.insertToFront("Hariette");
	ls.insertToFront("Carl");
	for (int k = 0; k < ls.size(); k++)
	{
		std::string x;
		ls.get(k, x);
		std::cout << x << std::endl;
	}
}

void TEST2()
{

	LinkedList ls;
	ls.insertToFront("Eric");
	ls.insertToFront("Shawn");
	ls.insertToFront("Topanga");
	ls.insertToFront("Cory");
	ls.printList();
	ls.printReverse();

}

void TEST3()
{
	LinkedList e1;
	e1.insertToFront("bell");
	e1.insertToFront("biv");
	e1.insertToFront("devoe");
	LinkedList e2;
	e2.insertToFront("Andre");
	e2.insertToFront("Big Boi");
	e1.append(e2); // adds contents of e2 to the end of e1
	std::string s;
	assert(e1.size() == 5 && e1.get(3, s) && s == "Big Boi");
	assert(e2.size() == 2 && e2.get(1, s) && s == "Andre");

}
void TEST4()
{
	LinkedList e1;
	e1.insertToFront("Sam");
	e1.insertToFront("Carla");
	e1.insertToFront("Cliff");
	e1.insertToFront("Norm");
	e1.reverseList(); // reverses the contents of e1
	std::string s;
	assert(e1.size() == 4 && e1.get(0, s) && s == "Sam");
}
void TEST5()
{
	LinkedList e1;
	e1.insertToFront("A");
	e1.insertToFront("B");
	e1.insertToFront("C");
	e1.insertToFront("D");
	LinkedList e2;
	e2.insertToFront("X");
	e2.insertToFront("Y");
	e2.insertToFront("Z");
	e1.swap(e2); // exchange contents of e1 and e2
	string s;
	assert(e1.size() == 3 && e1.get(0, s) && s == "Z");
	assert(e2.size() == 4 && e2.get(2, s) && s == "B");

}

// ALWAYS REMEMBER TO HAVE THE LAST NODE POINT TO NULLPTR !!

int main()
{ 
	TEST1();
	TEST2();
	TEST3();
	TEST4();
	TEST5();

	system("pause");
	return 0;
}