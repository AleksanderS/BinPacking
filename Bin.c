/**********************
 * File: Bin.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include "Bin.h"
#include "Item.h"






BinP newBin(int maxValue){
    BinP tmpBin = malloc(sizeof(struct Bin));
    tmpBin->nextBin = NULL;
    tmpBin->currentValue = 0;
    tmpBin->maxValue = maxValue;
    tmpBin->items = NULL;
    return tmpBin;
}

void addItemToBin(BinP bin, ItemP item){
    
    bin->currentValue += item->itemValue;
    item->nextItem = bin->items;
    bin->items = item;
    return;
}

//FREES BIN AND ALL CONTENTS, RETURNS POINTER TO THE NEXT BIN
BinP freeBin(BinP bin){
    ItemP tmp;
    while(bin->items != NULL){
        tmp = bin->items;
        bin->items = bin->items->nextItem;
        freeItem(tmp);
    }
    BinP nextBin = bin->nextBin;
    free(bin);
    return nextBin;
}

//FREES THE ENTIRE RUN
void freeTheBins(BinP bin1, BinP bin2, BinP bin3, BinP bin4, BinP bin5){
    
    while(bin1 != NULL){
        bin1 = freeBin(bin1);
    }
    while(bin2 != NULL){
        bin2 = freeBin(bin2);
    }
    while(bin3 != NULL){
        bin3 = freeBin(bin3);
    }
    while(bin4 != NULL){
        bin4 = freeBin(bin4);
    }
    while(bin5 != NULL){
        bin5 = freeBin(bin5);
    }
    return;
}


//FOR TESTING
int countBins(BinP theBins){
    
    return countBinsR(theBins);
    
}
int countBinsR(BinP currentBin){
    if(currentBin == NULL) return 0;
    return 1 + countBins(currentBin->nextBin);
}

//FOR SHOWING HOW EACH BIN WAS FILLED AT END OF PROGRAM
void printBin(BinP theBin){
    
    printf("%i/%i : ", theBin->currentValue, theBin->maxValue);
    ItemP tmp = theBin->items;
    while(tmp != NULL){
        printItem(tmp);
        tmp = tmp->nextItem;
    }
    printf("\n");
    return;
}

// PRINT THE ENTIRE STRUCTURE
void printAllBins(BinP theBins){
    BinP tmp = theBins;
    while(tmp != NULL){
        printBin(tmp);
        tmp = tmp->nextBin;
    }
    printf("\n");
    return;
}
