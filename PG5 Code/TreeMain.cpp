#include "Tree.h"
#include "CmpStr.h"
#include "TreeMain.h"
#include <iostream>
using namespace std;

int main () {

	Tree *MyTree = new Tree ();
	MyTree->add (new CmpStr ("HARRY"), new CmpStr(0));
	MyTree->add (new CmpStr ("RON"));
	MyTree->add (new CmpStr ("HERMIONE"));
	MyTree->add (new CmpStr ("FRED"));
	MyTree->add (new CmpStr ("GEORGE"));
	MyTree->add (new CmpStr ("NEVILLE"));
	MyTree->add (new CmpStr ("SEAMUS"));

	cout << "First:  " << ((CmpStr *)(MyTree->first ()))->gets() << endl;

    CmpStr *k = (CmpStr *)(MyTree->first ());
	while (k != NULL) {
		cout << k->gets() << endl;
		k = (CmpStr *)(MyTree->next(k));
	}
	cout << endl;
	MyTree->remove (new CmpStr ("HARRY"));
	MyTree->remove (new CmpStr ("FRED"));
	MyTree->remove (new CmpStr ("HERMIONE"));

	k = (CmpStr *)(MyTree->first ());
	while (k != NULL) {
		cout << k->gets() << endl;
		k = (CmpStr *)(MyTree->next(k));
	}
	cout << endl;

	MyTree->remove (new CmpStr ("HARRY"));
	MyTree->remove (new CmpStr ("RON"));
	MyTree->remove (new CmpStr ("HERMIONE"));
	MyTree->remove (new CmpStr ("FRED"));
	MyTree->remove (new CmpStr ("GEORGE"));
	MyTree->remove (new CmpStr ("SEAMUS"));

	k = (CmpStr *)(MyTree->first ());
	while (k != NULL) {
		cout << k->gets() << endl;
		k = (CmpStr *)(MyTree->next(k));
	}
	cout << endl;

	/*
	while (true) {
		cout << "Enter a name:  ";
		string name;
		getline (cin,name);
		if (MyTree->search (new CmpStr(name)))
			cout << "It's in there!" << endl;
		else
			cout << "It's not in there!" << endl;
	}*/
	system ("pause");
	return 0;
}