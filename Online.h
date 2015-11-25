/**********************
 * File: Online.h
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/

#ifndef ONLINE_H
#define	ONLINE_H
#include "Bin.h"
#include "Item.h"

BinP runOnlineFirstFit(int * , int , int *, int );
BinP runOnlineNextFit(int * , int , int *, int );
BinP runOnlineBestFit(int * , int , int *, int );
BinP findBestBin(BinP , int );

#endif	/* ONLINE_H */

