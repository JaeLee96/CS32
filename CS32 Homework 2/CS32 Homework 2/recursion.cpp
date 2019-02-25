#include <iostream>
#include <string>
using namespace std;

// Returns the product of two positive integers, m and n,
// using only repeated addition.
int mult(unsigned int m, unsigned int n)
{
	if (m == 0) return 0;
	return mult(m - 1, n) + n;
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.

int countDigit(int num, int digit)
{
	if (digit < 0 || digit > 9) return 0;

	if (num == 0)
		return 0;

	return countDigit(num / 10, digit) + (num % 10 == digit);
}

// Returns a string where the same characters next each other in
// string n are separated by "**"
//
// Pseudocode Example:
// pairStars("goodbye") => "go**odbye"
// pairStars("yyuu") => "y**yu**u"
// pairStars("aaaa") => "a**a**a**a"
//

string pairStars(std::string n)
{
	std::string s = "";

	s += n[0];

	if (n.length() >= 2) {
		if (n[0] == n[1])
			s += "**";
	} 
	else return s;
	
	return s + pairStars(n.erase(0,1));
}

// str contains a single pair of brackets, return a new string
// made of only the brackets and whatever those brackets contain
//
// Pseudocode Example:
// subBrackets("abc[ghj]789") => "[ghj]"
// subBrackets("[x]7") => "[x]"
// subBrackets ("4agh[y]") => "[y]"
//

string subBrackets(std::string str)
{
	if (str == "") return "";

	if (str[0] == '[') {
		if (str.back() == ']')
			return str;
		else
		{
			str.pop_back();
			return subBrackets(str); 
		}
	}

	return subBrackets(str.substr(1));
}

// Return true if the sum of any combination of elements in the
// array a equals the value of the target.
//
// Pseudocode Example:
// comboSum([2, 4, 8], 3, 10) => true
// comboSum([2, 4, 8], 3, 12) => true
// comboSum([2, 4, 8], 3, 11) => false
// comboSum([], 0, 0) => true
//

bool comboSum(const int a[], int size, int target)
{
	if (size == 0 && target == 0) return true;

	else if (target == 0) return true;

	else if (size == 0) return false;

	else
		return comboSum(a, size-1, target) || comboSum(a, size-1, target - a[size-1]);
}

bool pathExists(string maze[], int nRows, int nCols,
	int sr, int sc, int er, int ec)
{
	if (sr == er && sc == ec) return true;

	maze[sr][sc] = '#';

	if (maze[sr-1][sc] == '.')
		if (pathExists(maze, nRows, nCols, sr-1, sc, er, ec))
			return true;
	
	if (maze[sr+1][sc] == '.')
		if (pathExists(maze, nRows, nCols, sr+1, sc, er, ec))
			return true;
	
	if (maze[sr][sc-1] == '.')
		if (pathExists(maze, nRows, nCols, sr, sc-1, er, ec))
			return true;
		
	if (maze[sr][sc+1] == '.')
		if (pathExists(maze, nRows, nCols, sr, sc+1, er, ec))
			return true;

	return false;
}

int main()
{
	// Pseudocode Example:
	cout << countDigit(18838, 8) << endl; // 3
	cout << countDigit(55555, 3) << endl; // 0
	cout << countDigit(0, 0) << endl;
	cout << endl;

	cout << pairStars("goodbye") << endl; // "go**odbye"
	cout << pairStars("yyuu") << endl; // "y**yu**u"
	cout << pairStars("aaaa") << endl;
	cout << endl;

	cout << subBrackets("abc[ghj]789") << endl; // "[ghj]"
	cout << subBrackets("[x]7") << endl; // "[x]"
	cout << subBrackets("4agh[y]") << endl; // [y]
	cout << endl;
	
	system("pause");
	return 0;
}
