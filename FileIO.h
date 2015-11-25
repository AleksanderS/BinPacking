/**********************
 * File: FileIO.h
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#ifndef FILEIO_H
#define	FILEIO_H

#include "Item.h"
#include "Bin.h"
ItemP getRunItems();
BinP getBinSizes();
int getRunItemsSize(ItemP);
int getRunItemsSizeR(ItemP);


#endif	/* FILEIO_H */

