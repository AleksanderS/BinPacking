/**********************
 * File: Online.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/


#include <stdio.h>
#include <stdlib.h>
#include "Bin.h"
#include "Item.h"
#include "Online.h"

BinP runOnlineFirstFit(int *binSizes, int sizeOfBinArray , int *items, int itemsSize){
    BinP theBins = newBin(binSizes[0]);
    BinP head = theBins;
    BinP currentBin = theBins;
    int binCounter = 1;
    int i;
    for(i = 0; i < itemsSize; i++){
        if(items[i] > 100) printf("Item %i is too big. Throwing it away.\n", items[i]);
        else {
            if(items[i] <= currentBin->maxValue - currentBin->currentValue){ // THE ITEM FIT
                ItemP tmp = newItem(items[i]);
                addItemToBin(currentBin, tmp);
            }
            else { // THE ITEM DID NOT FIT
                while(items[i] > currentBin->maxValue - currentBin->currentValue){
                    if(currentBin->nextBin == NULL){ // DID NOT FIT IN ANY BINS
                        currentBin->nextBin = newBin(binSizes[binCounter]);
                        binCounter++;
                        currentBin = currentBin->nextBin;
                        if(items[i] > currentBin->maxValue - currentBin->currentValue) break;
                    }
                    else  currentBin = currentBin->nextBin;
                }
                if(items[i] > currentBin->maxValue - currentBin->currentValue) printf("Item %i is too big. Throwing it away.\n", items[i]);
                else {
                addItemToBin(currentBin, newItem(items[i]));
                currentBin = head;
                }
            }
        } 
    }
    return theBins;
}

BinP runOnlineNextFit(int *binSizes, int sizeOfBinArray , int *items, int itemsSize){
    BinP theBins = newBin(binSizes[0]);
    BinP head = theBins;
    BinP currentBin = head;
    int binCounter = 1;
    int i;
    for(i = 0; i < itemsSize; i++){
        if(items[i] > 100) printf("Item %i is too big. Throwing it away.\n", items[i]);
        else{
            if(items[i] <= currentBin->maxValue - currentBin->currentValue) //ITEM FITS
                addItemToBin(currentBin, newItem(items[i]));
            else{ //ITEM DOESN"T FIT
                BinP tmp = currentBin->nextBin;
                currentBin->nextBin = newBin(binSizes[binCounter]);
                binCounter++;
                currentBin->nextBin->nextBin = tmp;
                if(items[i] > currentBin->nextBin->maxValue - currentBin->nextBin->currentValue){
                    printf("Item %i is too big. Throwing it away.\n" , items[i]);
                    
                }
                else {
                    addItemToBin(currentBin->nextBin, newItem(items[i]));
                    currentBin = currentBin->nextBin;
                }
            } 
        }
    }
    return theBins;
}

BinP runOnlineBestFit(int *binSizes, int sizeOfBinArray , int *items, int itemsSize){
    BinP theBins = newBin(binSizes[0]);
    BinP head = theBins;
    int binCounter = 1;
    int i;
    for(i = 0; i < itemsSize; i++){
        BinP bestBin = findBestBin(theBins, items[i]); //FINDS BEST BIN
        if(bestBin == NULL){ //get a new bin
            bestBin = newBin(binSizes[binCounter]);
            binCounter++;
            bestBin->nextBin = head->nextBin;
            head->nextBin = bestBin;
        }
        if(items[i] > bestBin->maxValue - bestBin->currentValue) printf("Item %i is too big. Throwing it away.\n", items[i]);
        else addItemToBin(bestBin, newItem(items[i]));
    }
    return theBins;
}

BinP findBestBin(BinP theBins, int theItem){
    BinP head = theBins;
    BinP current = theBins;
    BinP bestBin = head;
    double fitness = -1;
    while(current != NULL){
        //if better fitness and it fits
        if((theBins->maxValue - theBins->currentValue + theItem)/theBins->maxValue >= fitness && theItem <= current->maxValue - current->currentValue){
            bestBin = current;
            fitness = (theBins->maxValue - theBins->currentValue + theItem)/theBins->maxValue;
        }
        current = current->nextBin;
    }
    if(theItem > bestBin->maxValue - bestBin->currentValue) return NULL;
    return bestBin;
}