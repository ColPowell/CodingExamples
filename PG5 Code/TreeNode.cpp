#include "TreeNode.h"
#include "Tree.h"
#include "Comparable.h"
#include <iostream>
#include "CmpString.h"

#define NULL 0

TreeNode::TreeNode (Comparable *key, Item* data, TreeNode *l, TreeNode *r, TreeNode *p, Tree *T, bool Color) {
	k = key; left = l; right = r; parent = p; t = T; d = data;
	x = this;
	color = Color;
	gpa = NULL;
	uncle = NULL;
	if(parent)
		gpa = parent->getparent();
	if(gpa)
		uncle = getSibling(gpa, parent);
}
TreeNode* TreeNode::getleft() {return left;}
TreeNode * TreeNode::getright () {return right;}
TreeNode * TreeNode::getparent() {return parent;}
TreeNode* TreeNode::getUncle(TreeNode*n, TreeNode* p){
	if(!n) return NULL;
	else if(!p) return NULL;
	else if(n->getright() == p) return n->getleft();
	else return p->getright();
}
TreeNode * TreeNode::getSibling (TreeNode *n, TreeNode *p){
	if(!n) return NULL;
	else if(!p) return NULL;
	else if(n == p->getleft()) return p->getright();
	else return p->getleft();
}
TreeNode *TreeNode::getDirect (){
	if(this == parent->getleft()) return left;
	if(this == parent->getright()) return right;
	return NULL;
}
bool TreeNode::isDirect(){
	if(this == parent->getDirect()) return true;
	else return false;
}
void TreeNode::setparent (TreeNode *p) {parent = p;}
void TreeNode::setleft (TreeNode *l) {left = l;}
void TreeNode::setright (TreeNode *r) {right = r;}

TreeNode::~TreeNode () {

	delete left;
	delete right;
}

void TreeNode::add (Comparable *key, Item* data) {

	if (k->cmp(key)==0){
		return;	
	}
	else if (key->cmp(k) < 0){
		if (left) left->add (key, data);
		else{
			left = new TreeNode (key,data, NULL,NULL,this,t, false);
			recAdd(left);			
		}
	}
	else{
		if(right){
			right->add (key, data);
		}
		else{
			right = new TreeNode (key,data, NULL,NULL,this,t, false);
			recAdd(right);
		}
	}
}

void TreeNode::setColor(bool Color){
	color = Color;
}

bool TreeNode::getColor(){
	if(this == NULL) return true;
	return color;}

bool TreeNode::search (Comparable *key) {

	if (key->cmp2 (k)==0){
		return true;
	}
	if (key->cmp (k) < 0){ 
		if (left) return left->search (key);
		else return false;
	}
	else{
		if (right) return right->search (key);
		else return false;
	}

}

TreeNode * TreeNode::searchnode (Comparable *key) {

	if (key->cmp2 (k)==0) return this;
	if (key->cmp (k) > 0) 
		if (right) return right->searchnode (key);
		else return NULL;
	else
		if (left) return left->searchnode (key);
		else return NULL;

}

TreeNode * TreeNode::first () {
	if (!left) return this;
	return left->first ();
}

TreeNode * TreeNode::nextb () {

	if (!parent) return NULL;
	if (parent->getright()==this) return parent->nextb();
	return parent;
}

Comparable * TreeNode::getk () {
	if(k) return k;
	else return NULL;
}

Comparable * TreeNode::next (Comparable *key) {

	TreeNode * found = searchnode (key);
	if (!found) return NULL;
	if (found->getright()) return found->getright()->first ()->getk();
	TreeNode *nb = found->nextb();
	if (!nb) return NULL;
	return nb->getk();
}

Comparable * TreeNode::last () {

	if(!right){
		return k;
	}
	else {
		return right->last();
	}
	return NULL;
}

Comparable * TreeNode::Prev (Comparable *key) {
	TreeNode * found = searchnode (key);
	if (!found) return NULL;
	if (found->getleft()) return found->getleft()->last();
	TreeNode *nb = found->Prevb();
	if (!nb) return NULL;
	return nb->getk();
}

TreeNode* TreeNode::Prevb(){
	if (!parent) return NULL;
	if (parent->getleft()==this) return parent->Prevb();
	return parent;
}


Item* TreeNode::searchitem(Comparable* key){
	if (key->cmp2 (k)==0){
		return d;
	}
	if (key->cmp (k) < 0) {
		if (left){
			return left->searchitem (key);
		}
		else{
			return NULL;
		}
	}
	else{
		if (right){
			return right->searchitem (key);
		}
		else{
			return NULL;
		}
	}
}

void TreeNode::remove (TreeNode *dd){

	if(dd->getk()->cmp3(k) == 0){
		return;
	}

	if(dd->getleft() == NULL || dd->getright() == NULL){
		TreeNode* p = dd->getparent();
		TreeNode* x = dd->getright();
		if(!x) x = dd->getleft();
		if(p){
			if(p->getleft() == dd) p->setleft(x);
			else if(p->getright() == dd) p->setright(x);
		}
		else{
			t->setroot(x);
		}
		if(x)
			x->setparent(p);

		//delete dd;
		if(dd->getColor() == true){
			DelProcess(x,p);
		//	delete dd;
			return;
		}
		delete dd;
	}
	else{
		TreeNode*f = searchnode(next(k));
		k = next(k);
		CmpString* kk = (CmpString*)k;
		d = f->d;
		f->remove (f);
	}
}


void TreeNode::DelProcess(TreeNode* x, TreeNode* p){
	if(!x && !p){
		t->setroot(NULL);
		return;
	}
	if(x->getColor() == false){
		x->setColor(true); 
		return;
	}
	if(!p){ 
		x->setColor(true);
		t->setroot(x);
		return;
	}
	TreeNode* w = NULL;
	TreeNode* gp = p->getparent();
	TreeNode* z = NULL;
	w = getSibling(x, p);
	if(w->getColor() == false){
		Rotate(w);
		DelProcess(x,p);
		return;
		//rotate w up once, RESTART
	}
	else if(w->getleft()->getColor() == true && w->getright()->getColor() == true){
		w->setColor(false);
		DelProcess(p, gp);
		return;
		//reassign x to p, and p to p's parent, RESTART.
	}
	else if(w->getDirect()->getColor() == false){
		w->getDirect()->setColor(true);
		Rotate(w);
		return;
	}
	else{
		if(w == p->getleft()) z = w->getright();
		else z = w->getleft();
		Rotate(z);
		Rotate(z);
		//rotate w's zigzag child up twice
		w->setColor(true);
		return;
	}
}

void TreeNode::Rotate(TreeNode*x){
	TreeNode* p = x->getparent();
	TreeNode* gp = NULL;
	if(p) gp = p->getparent();
	TreeNode* z = NULL;
	if(x == p->getleft()) z = x->getright();
	else if(x == p->getright()) z = x->getleft();

	if(gp){
		x->setparent(gp);
		if(p == gp->getright()){gp->setright(x);}
		else if(p == gp->getleft()) gp->setleft(x);
		p->setparent(x);
		if(x == p->getleft()) x->setright(p);
		else if(x == p->getright()) x->setleft(p);
		if(x == p->getleft()) p->setleft(z);
		else if(x == p->getright()) p->setright(z);
		if(z) z->setparent(p);
		bool tempColor = x->getColor();
		x->setColor(p->getColor());
		p->setColor(tempColor);
	}
	else{
		bool tempColor = x->getColor();
		//t->setroot(x);
		x->setColor(true);
		p->setparent(x);
		if(z) z->setparent(p);
		if(x == p->getleft()){
			x->setright(p);
			p->setleft(z);
		}
		else if(x == p->getright()){
			x->setleft(p);
			p->setright(z);
		}
		t->setroot(x);
		p->setColor(tempColor);
	}
}

void TreeNode::AddProcess(TreeNode* x){
	TreeNode* p = x->getparent();
	TreeNode* gp = NULL;
	if(!p){
		x->setColor(true);
		t->setroot(x);
		return;
	}
	if (p->getColor() == true){
		return;
	}
	gp = p->getparent();
	TreeNode* unc = NULL;
	if(gp)
		unc = getSibling(p, gp);
	if(unc){
		if(unc->getColor() == false){
			p->setColor(true);
			unc->setColor(true);
			gp->setColor(false);
			AddProcess(gp);
			return;
		}
	}
	if(x->isDirect()){
		Rotate(p); 
		//rotate parent up once
		return;
	}
	Rotate(x);
	Rotate(x);
	return;
	
}

void TreeNode::recAdd(TreeNode* x){

	x->setColor(false);
	AddProcess(x);
	return;
}