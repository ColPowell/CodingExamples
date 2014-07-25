#ifndef _DATABASE_
#define _DATABASE_

#include "DRT.h"
#include "Comparable.h"
#include "Item.h"

class DRT;
class Comparable;
class Item;
class Database {

 public:

  virtual DRT * search (Comparable *key) = 0;

  virtual DRT * modify (Comparable *key, Item *data) = 0;

};

#endif

/*

Both search and modify return DRT's (Database Return Types).  Neither
method EVER returns a value of NULL; they always return DRT's.  However,
some of the fields in the returned DRT might be NULL.

search (Comparable *key):

if key is NULL, then set the following fields in the DRT:
  data = NULL
  next = the first key in the database (or NULL if empty)
  prev = the last key in the database (or NULL if empty)

if key is not NULL but is not present in the database:
  data = NULL
  next = the first key in the database following key (or NULL)
  prev = the last key in the database preceding key (or NULL)

if key is present in the database:
  data = the data corresponding to key
  next = the first key in the database following key (or NULL)
  prev = the last key in the database preceding key (or NULL)

modify (Comparable *key, Item *data):

At all times, modify returns the DRT that search would have returned 
JUST PRIOR to the modification made by modify.  Discussed below are
the modifications made by modify.

if key is NULL, do nothing.

if key is not NULL but not present in the database and data is NULL, do
nothing.

if key is not NULL but not present in the database and data is not NULL,
add <key,data> to the database.

if key is present in the database and data is NULL, remove key from the
database.

if key is present in the database and data is not NULL, replace the data
associated with key with the new data.

*/