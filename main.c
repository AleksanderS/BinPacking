/**********************
 * File: main.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include "Bin.h"
#include "Item.h"
#include "FileIO.h"
#include "Online.h"
#include "Offline.h"

void printItemsRecursively(ItemP );
void printRunItems(ItemP );
void copyArray(int *, int *, int );
void printStats(int , BinP , BinP , BinP , BinP , BinP);


int main(int argc, char** argv) {

    ItemP runItems = getRunItems();
    BinP binSizes = getBinSizes();
    int numberOfRuns = runItems->itemValue;
    int numberOfBins = countBins(binSizes);
    int binSizesArray[numberOfBins];
    int i;
    BinP currentBin = binSizes;
    
    //LINKED LIST TO ARRAY FOR EASY INDEXING
    for(i = 0; i < numberOfBins; i++){
        binSizesArray[i] = currentBin->maxValue;
        currentBin = currentBin->nextBin;
    }
    
    
    ItemP currentItem = runItems->nextItem;
    for(i = 0; i < numberOfRuns; i++){
        int tmpBins[numberOfBins];
        copyArray(tmpBins, binSizesArray, numberOfBins);
        int numberOfItemsInRun = currentItem->itemValue;
        int items[numberOfItemsInRun];
        int j;
        for(j = 0; j < numberOfItemsInRun; j++){ //POPULATE ITEMS FOR THIS RUN
            currentItem = currentItem->nextItem;
            items[j] = currentItem->itemValue;
        }
        printf("Run %i\n", i + 1);
         BinP OLFF = runOnlineFirstFit(tmpBins, numberOfBins, items, numberOfItemsInRun);  //do online first fit and print, save how bins were packed (save pointer to structure)
         BinP OLNF = runOnlineNextFit(tmpBins, numberOfBins, items, numberOfItemsInRun); // do online next fit and print, save how bins were packed (save pointer to structure)
         BinP OLBF = runOnlineBestFit(tmpBins, numberOfBins, items, numberOfItemsInRun);// do online best fit and print, save how bins were packed (save pointer to structure)
         BinP OFFF = runOfflineFirstFit(tmpBins, numberOfBins, items, numberOfItemsInRun);// do offline first fit and print, save how bins were packed (save pointer to structure)
         BinP OFBF = runOfflineBestFit(tmpBins, numberOfBins, items, numberOfItemsInRun);// do offline best fit and print, save how bins were packed (save pointer to structure)
         //PRINT STATISTICS
         printStats(i, OLFF, OLNF, OLBF, OFFF, OFBF);

         freeTheBins(OLFF, OLNF, OLBF, OFFF, OFBF); // FREES THE STRUCTURES SO NO MEMORY LEAK
         currentItem= currentItem->nextItem; //GETS CORRECT NUMBER OF ITEMS IN THE NEXT RUN
   }
    
    
    return (0);
}






//FOR MAKING SURE THE ITEMS LOADED CORRECTLY
void printRunItems(ItemP items){
    printItemsRecursively(items);
    
}
void printItemsRecursively(ItemP currentItem){
    if(currentItem == NULL){
        return;
    }
    fprintf(stderr, "%i\n", currentItem->itemValue);
    printItemsRecursively(currentItem->nextItem);
    return;
}
//END


void copyArray(int *dest, int *src, int size){
    int i;
    for(i = 0; i <= size; i++)
        dest[i] = src[i];
}

void printStats(int i, BinP OLFF, BinP OLNF, BinP OLBF, BinP OFFF, BinP OFBF){
    
         
         printf("____________________________________");
         printf("\n");
         printf("|Policy            |Total Bins Used|\n");
         printf("|Online Algorithm  |               |\n");
         printf("| First Fit        |     %.2i        |\n",   countBins(OLFF));
         printf("| Next  Fit        |     %.2i        |\n",   countBins(OLNF));
         printf("| Best  Fit        |     %.2i        |\n",   countBins(OLBF));
         printf("|Offline Algorithm |               |\n");
         printf("| First Fit        |     %.2i        |\n",   countBins(OFFF));
         printf("| Best  Fit        |     %.2i        |\n",   countBins(OFBF));
         printf("------------------------------------\n");
       
         
         printf("Online Algorithm\nFirst Fit\n");
         printAllBins(OLFF);
         printf("Next Fit\n");
         printAllBins(OLNF);
         printf("Best Fit\n");
         printAllBins(OLBF);
         printf("Offline Algorithm\n");
         printf("First Fit\n");
         printAllBins(OFFF);
         printf("Best Fit\n");
         printAllBins(OFBF);
         return;
}
