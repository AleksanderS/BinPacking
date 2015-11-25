/**********************
 * File: Bin.h
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#ifndef BIN_H
#define	BIN_H
#include "Item.h"

typedef struct Bin{
    struct Bin * nextBin;
    int maxValue;
    int currentValue;
    ItemP items;
} *BinP;

typedef struct BinSizes{
    int *binSizes;
} *BinSizesP;

BinP newBin(int);

void addItemToBin(BinP, ItemP);

BinP freeBin(BinP); //returns the next Bin in the list. If there is no next bin, NULL is returned.

int countBins(BinP);
int countBinsR(BinP);
void printAllBins(BinP);
void printBin(BinP);

void freeTheBins(BinP , BinP, BinP, BinP, BinP);


#endif	/* BIN_H */

