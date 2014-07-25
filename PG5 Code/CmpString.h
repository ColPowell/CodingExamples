#ifndef _CMPSTRING_
#define _CMPSTRING_

#include "Comparable.h"
#include "Item.h"
#include <string>
using namespace std;

class Comparable;
class Item;
class CmpString : public Comparable, public Item {

private:
	string s;
	int c;
public:
	CmpString (string s, int c);
	string gets ();
	int getc ();
	void setc(int C);
	virtual int cmp (Comparable *b);
	virtual int cmp2(Comparable*d);
	virtual int cmp3(Comparable* e);
};

#endif