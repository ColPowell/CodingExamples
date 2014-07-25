#include "DB.h"
#include "Comparable.h"
#include "Item.h"
#include <iostream>

#define NULL 0

DB::DB () {L = new Tree();}

DB::~DB () {delete L;}

DRT * DB::search (Comparable *key) {

	Item *data = NULL;
	Comparable* left = NULL;
	Comparable* right = NULL;
	Comparable* parent = NULL;
	if (!key) {
		data = NULL;
		left = L->first ();
		right = L->last ();
	} else {
		Item *n = L->searchItem (key);
		if (!n) {
			data = NULL;
			right = L->next (key);
			left = L->prev (key);
		} else {
			data = n;
			right = L->next (key);
			left = L->prev (key);
		}
	}
	return new DRT (data,right,left);
}

DRT * DB::modify (Comparable *key, Item *data) {
	DRT *drt = search (key);

	if (!key) {
	} else {
		TreeNode* n = L->searchnode (key);
		if (!n && !data) {
		} else if ((!n && data) || (n && data)){
			L->add (key, data);
		}
		else if (n && !data){
			L->remove (key);
		}
	}


	return drt;
}