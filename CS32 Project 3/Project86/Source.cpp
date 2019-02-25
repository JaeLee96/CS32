#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int helpDictionaryReader(istream &dictfile, string dict[]) // helper function
{
	string temp;

	if (dictfile.eof()) return -1;

	dictfile >> temp;
	int i = 1 + helpDictionaryReader(dictfile, dict);
	if (i >= MAXDICTWORDS) return i-1;
	else
	{
		dict[i] = temp;
		return i;
	}
}

int dictionaryReader(istream &dictfile, string dict[])
{
	return 1 + helpDictionaryReader(dictfile, dict);
}

// Places each string in dictfile into the array dict. Returns the number of
// words read into dict. This number should not be larger than MAXDICTWORDS since
// that is the size of the array.

bool duplicateCheck(string rest, int beginning, int current)
{
	if (beginning >= current)
		return false;

	if (rest[beginning] == rest[current])
		return true;

	return duplicateCheck(rest, beginning + 1, current);
}

bool searchWordFromDict(string word, const string dict[], int size)
{
	if (size < 1) return false;

	if (word == dict[size-1]) return true;

	return searchWordFromDict(word, dict, size-1);
}

int stringPermutationCount(string prefix, string rest)
{

	int count = 0;
	bool flag = false;
	string nextPrefix;
	string nextRest;

	if (rest == "") 
		return 1;

	for (int i = 0; i < rest.size(); i++)
	{
		flag = duplicateCheck(rest, 0, i);
		if (flag) continue;
		else
		{
			nextPrefix = prefix + rest[i];
			nextRest = rest.substr(0, i) + rest.substr(i+1);
		}
		count += stringPermutationCount(nextPrefix, nextRest);
	}

	return count;
}

bool loadIntoDict(string word, string results[], int size)
{
	if (size < 1) return false;

	if (results[size-1] != "")
		return loadIntoDict(word, results, size-1);

	else results[size-1] = word;

	return true;
}

int stringPermutation(string prefix, string rest, const string dict[], 
	int dictSize, string results[], int resultSize)
{
	int count = 0;
	bool flag = false;
	string nextPrefix;
	string nextRest;

	if (rest == "") {
		if (searchWordFromDict(prefix, dict, dictSize)) {
			if (loadIntoDict(prefix, results, resultSize))
				return 1;
			else
				return 0;
		}
	
	}

	for (int i = 0; i < rest.size(); i++)
	{
		flag = duplicateCheck(rest, 0, i);
		if (flag) continue;
		else
		{
			nextPrefix = prefix + rest[i];
			nextRest = rest.substr(0, i) + rest.substr(i+1);
		}
		count += stringPermutation(nextPrefix, nextRest, dict, dictSize, results, resultSize);
	}

	return count;
}

int recurCombos(string word, const string dict[], int size,
	string results[])
{
	return stringPermutation("", word, dict, size, results, numOfPermu);
}

// Places all the combinations of word, which are found in dict into results. Returns
// the number of matched words found. This number should not be larger than
// MAXRESULTS since that is the size of the array. The size is the number of words
// inside the dict array.

void recursiveDispHelper(const string results[], size)
{
	if (size <= 0) return;

	cout << results[size-1] << endl;

	recursiveDispHelper(results, size - 1);
}

void recursiveDisp(const string results[], int size)
{
	if (size == 0) return;
	else recursiveDispHelper(results, size);
}

// Displays size number of strings from results. The results can be printed in any
// order.

// For words with double letters you may find that different permutations match the same
// word in the dictionary. For example, if you find all the permutations of the string kloo
// using the algorithm we've discussed you may find that the word look is found twice. The
// o's in kloo take turns in front. Your program should ensure that matches are unique, in
// other words, the results array returned from the recurCombos function should have no
// duplicates. A nice way to test this, and your function in general, might be to use the
// assert facility from the standard library. If done properly the following code should run
// without a runtime error being generated.

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1

int main()
{
	string results[MAXRESULTS];
	string dict[MAXDICTWORDS];
	ifstream dictfile;         // file containing the list of words
	int nwords;                // number of words read from dictionary
	string word;

	dictfile.open("project3.txt");
	if (!dictfile) {
		cout << "File not found!" << endl;
		return (1);
	}

	nwords = dictionaryReader(dictfile, dict);

	cout << "Please enter a string for an anagram: ";
	cin >> word;

	int numOfMatch = recurCombos;
	recursiveDisp(results, numOfMatch);

	system("pause");
	return 0;
}