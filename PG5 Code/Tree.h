#ifndef _TREE_
#define _TREE_

#include "TreeNode.h"
#include "Comparable.h"
#include "Item.h"

class Comparable;
class TreeNode;
class Item;
class Tree {
private:
	TreeNode *root;
public:
	Tree ();
	~Tree ();
	void add (Comparable *key, Item* data);
	bool search (Comparable *key);
	void setroot (TreeNode *r);
	Comparable *last();
	Comparable * prev (Comparable *key);
	TreeNode * searchnode (Comparable *key);
	Comparable *first ();
	Comparable *next (Comparable *key);
	void remove (Comparable *key);
	Item* searchItem(Comparable *key);
};

#endif