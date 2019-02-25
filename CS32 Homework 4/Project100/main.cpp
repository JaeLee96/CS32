#include "tree.h"

void TEST_CASE()
{	
	WordTree w, p;

	w.add("Harry");
	w.add("Niall");
	w.add("Niall");
	w.add("Liam");
	w.add("Louis");
	w.add("Harry");
	w.add("Niall");
	w.add("Zayn");

	w = w;

	assert(w.totalWords() == 8 && w.distinctWords() == 5);
	assert(p.totalWords() == 0 && p.distinctWords() == 0);

	p = w;

	assert(p.totalWords() == 8 && p.distinctWords() == 5);

	p.add("Rachael");
	p.add("Michael");
	p.add("Luyi");

	assert(p.totalWords() == 11 && p.distinctWords() == 8);

	cout << p << endl;
	cout << w << endl;

	WordTree c;
	c.add("Pam");
	c.add("Kevin");
	c.add("Jim");

	c = p;

	assert(c.totalWords() == 11 && c.distinctWords() == 8);
	cout << c << endl;
}

int main()
{
	TEST_CASE();

	return 0;
}
