/**********************
 * File: FileIO.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/


#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"
#include "Item.h"
#include "Bin.h"

//CREATS LINKED LIST BECAUSE PROGRAM MUST WORK FOR ANY NUMBER OF ITEMS. LINKED LIST WILL BE CONVERTED TO AN ARRAY FOR EACH RUN.
ItemP getRunItems(){
    FILE *in = fopen("binItems.txt", "r");
    ItemP head = malloc(sizeof(struct Item));
    
    head->nextItem = NULL;
    head->previousItem = NULL;
    fscanf(in, "%i", &(head->itemValue));
    ItemP tail = head;
    
    int tmp;
    while(fscanf(in, "%i", &tmp) == 1){
        //READ IN
        ItemP tmpItem = malloc(sizeof(struct Item));
        tmpItem->itemValue = tmp;
        tmpItem->previousItem = tail;
        tail->nextItem = tmpItem;
        tail = tmpItem;
    }
	fclose(in);
    return head;
}

//KEEP TOGETHER
int getRunItemsSize(ItemP items){
    return getRunItemsSizeR(items);
}
int getRunItemsSizeR(ItemP item){
    if(item == NULL) return 0;
    return getRunItemsSizeR(item->nextItem) + 1;
}
// KEEP TOGETHER

//CREATS LINKED LIST, LINKED LIST IS BECAUSE PROGRAM MUST WORK FOR ANY NUMBER OF BINS. LINKED LIST WILL BE CONVERTED TO ARRAY FOR EACH RUN.
BinP getBinSizes(){
    FILE *in = fopen("bins.txt", "r");
    BinP head = malloc(sizeof(struct Bin));
    
    head->nextBin = NULL;
    head->items = NULL;
    head->currentValue = -1;
    BinP tail = head;
    
    int tmp;
    fscanf(in, "%i", &(head->maxValue));
    while(fscanf(in, "%i", &tmp) == 1){
        //READ IN
        BinP tmpBin = malloc(sizeof(struct Bin));
        tmpBin->items = NULL;
        tmpBin->currentValue = -1;
        tmpBin->maxValue = tmp;
       
        tail->nextBin = tmpBin;
        tail = tmpBin;
    }
	fclose(in);
    return head;
}
