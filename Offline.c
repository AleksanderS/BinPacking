/**********************
 * File: Offline.c
 * Name: Alex Lindemann
 * Date: 11/7/2015
 * Bin Packing Problem
 **********************/


#include <stdio.h>
#include <stdlib.h>
#include "Bin.h"
#include "Item.h"
#include "Offline.h"
#include "Online.h"


void reverseArray(int *, int *, int);

BinP runOfflineFirstFit(int *binSizes, int sizeOfBinArray , int *items, int itemsSize){
    
    mergeSort(items, itemsSize);
    BinP theBins = runOnlineFirstFit(binSizes, sizeOfBinArray, items, itemsSize);
    
    
    return theBins;
}

BinP runOfflineBestFit(int *binSizes, int sizeOfBinArray , int *items, int itemsSize){
    
    mergeSort(items, itemsSize);
    int itemsReverse[itemsSize];
    reverseArray(itemsReverse, items, itemsSize);
    BinP theBins = runOnlineBestFit(binSizes, sizeOfBinArray, itemsReverse, itemsSize);
    
    return theBins;
}

void merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void mergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	mergeSort(L,mid);  // sorting the left subarray
	mergeSort(R,n-mid);  // sorting the right subarray
	merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}

void reverseArray(int *dest, int *src, int size){
    int i;
    for(i = 0; size > 0; size--, i++){
        dest[i] = src[size - 1];
    }
}

