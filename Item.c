/**********************
 * File: Item.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "Bin.h"


ItemP newItem(int itemValue){
    ItemP tmpItem = malloc(sizeof(struct Item));
    tmpItem->itemValue = itemValue;
    tmpItem->nextItem = NULL;
    tmpItem->previousItem = NULL;
    return tmpItem;
}

void freeItem(ItemP itemToFree){
    free(itemToFree);
    return;
}

void printItem(ItemP currentItem){
    printf("%i, ", currentItem->itemValue);
    return;
}