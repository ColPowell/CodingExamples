#include "Tree.h"
#include "Comparable.h"
#include <iostream>

#define NULL 0

Tree::Tree () {

	root = NULL;
}

Tree::~Tree () {
	delete root;
}

void Tree::setroot (TreeNode *r) {
	root = r; 
	if(r)
		r->setparent(NULL);
}

Item* Tree::searchItem(Comparable* key){
	if(!root){
		return NULL;
	}
	root->searchitem(key);
}

void Tree::add (Comparable *key, Item* data) {

	if (!root){
		root = new TreeNode(key,data, NULL,NULL,NULL,this, true);	
	}
	else{
		root->add (key, data);
	}
}

bool Tree::search (Comparable *key) {

	if (!root) return false;
	return root->search (key);
}

TreeNode * Tree::searchnode (Comparable *key) {

	if (!root) return NULL;
	return root->searchnode (key);
}



Comparable * Tree::last () {
	if (root==NULL) return NULL;
	return root->last();
}
Comparable * Tree::prev (Comparable *key) {
	if (root==NULL) return NULL;
	return root->Prev (key);
}

Comparable * Tree::first () {

	if (!root) return NULL;
	return root->first ()->getk ();
}

Comparable * Tree::next (Comparable *key) {

	if (!root) return NULL;
	return root->next (key);
}

void Tree::remove (Comparable *key) {

	if (!root) return;
	TreeNode *found = searchnode (key);
	if (!found) return;
	found->remove(found);
}