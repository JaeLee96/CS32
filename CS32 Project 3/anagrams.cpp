#include <iostream>
#include <cassert>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int stringPermutation(string prefix, string rest, const string dict[],
	int dictSize, string results[]);

int helpDictionaryReader(istream &dictfile, string dict[]) // helper function for dictionary reader
{
	string temp;

	if (dictfile.eof()) return -1;

	dictfile >> temp;
	int i = 1 + helpDictionaryReader(dictfile, dict);
	if (i >= MAXDICTWORDS) return i - 1;
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

bool duplicateCheck(string rest, int beginning, int current) // check if same word combination is repeated due to duplicate letter
{
	if (beginning >= current)
		return false;

	if (rest[beginning] == rest[current])
		return true;

	return duplicateCheck(rest, beginning + 1, current);
}

bool searchWordFromDict(string word, const string dict[], int size) // search if combination of words are in dictionary
{
	if (size < 1) return false;

	if (word == dict[size - 1]) return true;

	return searchWordFromDict(word, dict, size - 1);
}

bool loadIntoResults(string word, string results[], int size) // load the matched word into the results array if its size did not exceed MAXRESULTS
{
	if (size >= MAXRESULTS) return false;

	if (results[size] != "")
		return loadIntoResults(word, results, size + 1);

	results[size] = word;
	return true;
}

int loop(bool flag, string rest, int count, int i, string nextPrefix, string prefix,
	string nextRest, const string dict[], int dictSize, string results[])        // helper for loop function for string permutation
{
	if (i >= rest.size()) 
		return count;
	
	flag = duplicateCheck(rest, 0, i);

	if (flag)
		return loop(flag, rest, count, i + 1, nextPrefix, prefix, nextRest, dict, dictSize, results);

	nextPrefix = prefix + rest[i];
	nextRest = rest.substr(0, i) + rest.substr(i + 1);
	
	count += stringPermutation(nextPrefix, nextRest, dict, dictSize, results);
	return loop(flag, rest, count, i + 1, nextPrefix, prefix, nextRest, dict, dictSize, results);
}


int stringPermutation(string prefix, string rest, const string dict[], // permute the string and if combinations of word is found in dictionary, load them
	int dictSize, string results[])										// helper function for recurCombos
{
	if (rest == "") {
		if (searchWordFromDict(prefix, dict, dictSize)) {
			if (loadIntoResults(prefix, results, 0))
				return 1;
		}
		else return 0;
	}
	return loop(false, rest, 0, 0, "", prefix, "", dict, dictSize, results);
}


int recurCombos(string word, const string dict[], int size,
	string results[])
{
	return stringPermutation("", word, dict, size, results);
}

// Places all the combinations of word, which are found in dict into results. Returns
// the number of matched words found. This number should not be larger than
// MAXRESULTS since that is the size of the array. The size is the number of words
// inside the dict array.

void recursiveDispHelper(const string results[], int index, int size) // helper function for recursiveDisp
{
	if (index == size) return;

	cout << results[index] << endl;

	recursiveDispHelper(results, index + 1, size);
}

void recursiveDisp(const string results[], int size) // display the results, if there's none, display "No Match Found"
{
	if (size == 0)
	{
		cout << "No Match Found!" << endl;
		return;
	}

	(size >= MAXRESULTS ? size = MAXRESULTS : size);
	
	recursiveDispHelper(results, 0, size);
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

	dictfile.open("words.txt");
	if (!dictfile) {
		cout << "File not found!" << endl;
		return (1);
	}

	nwords = dictionaryReader(dictfile, dict);

	string exampleDict[] = { "hello", "helol", "heoll", "hlelo", "hleol", "hlleo", "hlloe", "hloel", "hlole",
		"hoell", "holel", "holle", "ehllo", "ehlol", "eholl", "elhlo", "elhol", "ellho", "elloh", "elohl", "elolh",
		"eohll", "eolhl", "eollh" };
		
	int numResults = recurCombos("hello", exampleDict, 24, results);
	
	for (int i = 0; i < 20; i++)
		cerr << results[i] << endl;
	cout << endl;

	string results2[MAXRESULTS];

	string exampleDict2[] = { "loop", "pool", "opol", "elephant" };

	int numResults2 = recurCombos("loop", exampleDict2, 4, results2);

	for (int i = 0; i < 20; i++)
		cerr << results2[i] << endl;

	string exampleDict3[] = { "" };

	string results3[MAXRESULTS];

	int numResults3 = recurCombos("", exampleDict3, 1, results3);

	for (int i = 0; i < 20; i++)
		cerr << results3[i] << endl;

	system("pause");
	return 0;
}