/**********************
 * File: Item.h
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#ifndef ITEM_H
#define	ITEM_H

typedef struct Item {
    struct Item * nextItem;
    struct Item * previousItem;
    int itemValue;
} *ItemP;


ItemP newItem(int);
void freeItem(ItemP);
void printItem(ItemP);


#endif	/* ITEM_H */

