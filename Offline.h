/**********************
 * File: Offline.h
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#ifndef OFFLINE_H
#define	OFFLINE_H

#include "Bin.h"
#include "Item.h"


BinP runOfflineFirstFit(int *, int  , int *, int );
BinP runOfflineBestFit(int *, int  , int *, int );

void merge(int *,int *,int ,int *,int );
void mergeSort(int *,int );

#endif	/* OFFLINE_H */

