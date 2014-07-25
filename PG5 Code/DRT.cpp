#include "DRT.h"
#include "Item.h"
#include "Comparable.h"

DRT::DRT (Item *d, Comparable *n, Comparable *p) {

 data = d; next = n; prev = p;
}

Item * DRT::getdata () {return data;}

Comparable * DRT::getnext () {return next;}

Comparable * DRT::getprev () {return prev;}