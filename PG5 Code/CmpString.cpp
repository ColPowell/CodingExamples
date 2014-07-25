#include "CmpString.h"
#include "Comparable.h"
#include <iostream>
#include <string>
using namespace std;

int CmpString::cmp (Comparable *b) {

	CmpString *bb = (CmpString *)b;
	if(s == bb->gets()){
		c++;
		return 0;
	}
	else if (s < bb->gets()) return -1;
	else if (s > bb->gets()) return 1;
	else return 0;
}

int CmpString::cmp2(Comparable*d){
	CmpString *dd = (CmpString *)d;
	if(s == dd->gets()){
		return 0;
	}
	else if (s < dd->gets()) return -1;
	else if (s > dd->gets()) return 1;
	else return 0;
}

int CmpString::cmp3(Comparable* e){
	CmpString* ee = (CmpString*)e;
	if(s == ee->gets()){
		if(c > 1){
			c--;
			return 0;
		}
	}
	return -1;
}

void CmpString::setc(int C){
	c = C;
}

CmpString::CmpString (string s2, int c2) {
	s = s2;
	c = c2;
}

int CmpString::getc() {return c;}

string CmpString::gets () {return s;}