#ifndef _DRT_
#define _DRT_

#include "Item.h"
#include "Comparable.h"

class Item;
class Comparable;
class DRT {

 private:
  Item *data;
  Comparable *next;
  Comparable *prev;

 public:

  DRT (Item *d, Comparable *n, Comparable *p);
  Item *getdata ();
  Comparable *getnext ();
  Comparable *getprev ();

};



#endif

/* DRT.h is the Database Return Type.  It contains three fields:

   The data from the location in the database we're examining.

   The next key field in sequential order after the one we're examining.

   The prev key field in sequential order before the one we're examining.

*/