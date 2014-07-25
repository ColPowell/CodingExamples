#ifndef _COMPARABLE_
#define _COMPARABLE_

class Comparable {
public:
	virtual int cmp (Comparable *b) = 0;
	virtual int cmp2(Comparable*d) = 0;
	virtual int cmp3(Comparable* e) = 0;
};

#endif