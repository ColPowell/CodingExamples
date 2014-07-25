#ifndef _DB_
#define _DB_

#include "Database.h"
#include "Comparable.h"
#include "Item.h"
#include "Tree.h"

class Database;
class Comparable;
class Item;
class Tree;
class DB : public Database {
private:
	Tree * L;
	int count;
public:
	virtual DRT * search (Comparable *key);
	virtual DRT * modify (Comparable *key, Item *data);
	DB ();
	~DB ();

};


#endif