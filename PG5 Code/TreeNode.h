#ifndef _TREENODE_
#define _TREENODE_

#include "Tree.h"
#include "Comparable.h"
#include "Item.h"

class Comparable;
class Tree;
class Item;
class TreeNode {
private:
	Comparable *k;
	TreeNode *left, *right, *parent, *x, *gpa, *uncle;
	Tree *t;
	bool color;
	Item* d;
public:
	TreeNode (Comparable *key, Item* data, TreeNode *l, TreeNode *r, TreeNode *p, Tree *T, bool Color);
	~TreeNode ();
	void add (Comparable *key, Item* data);
	void Rotate(TreeNode*x);
	void remove (TreeNode *dd);
	void DelProcess(TreeNode* x, TreeNode* p);
	void AddProcess(TreeNode* x);
	TreeNode * getSibling (TreeNode *n, TreeNode *p); 
	TreeNode * getDirect ();
	bool isDirect();
	bool getColor();
	TreeNode* getUncle(TreeNode* n, TreeNode* p);
	void setColor(bool Color);
	bool search (Comparable *key);
	TreeNode * searchnode (Comparable *key);
	TreeNode* getleft();
	TreeNode * first ();
	Comparable * getk ();
	TreeNode *getright ();
	TreeNode * nextb ();
	Comparable *next (Comparable *key);
	Comparable *last();
	Comparable * Prev (Comparable *key);
	TreeNode* Prevb();
	Item* searchitem(Comparable* key);
	TreeNode * TreeNode::getparent();
	void recAdd (TreeNode * x);
	void setparent (TreeNode *p);
	void setleft (TreeNode *l);
	void setright (TreeNode *r);
};

#endif