#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

ListP createBinList(){
	ListP listPtr = malloc(sizeof(struct BinList));
	listPtr->numBins = 0;
	listPtr->head = NULL;
	return listPtr;
}

BinP addBinToList(ListP listPtr, int capacity){
	BinP binPtr = malloc(sizeof(struct Bin));
	binPtr->capacity = capacity;
	binPtr->currentSize = 0;
	binPtr->nextBin = NULL;
	binPtr->firstItem = NULL;

	if (listPtr->numBins == 0){ // if first bin
		listPtr->head = binPtr;
		listPtr->numBins++;
		return binPtr;
	}
	
	// else not the first bin
	BinP tmp = listPtr->head; // use for traversing the Bins
	while (tmp->nextBin != NULL){
		tmp = tmp->nextBin; // traverse list of Bins
	}

	tmp->nextBin = binPtr;
	listPtr->numBins++;

	return binPtr;
}

void printBins(ListP listPtr){

	return;
}


ListP freeBinList(ListP listPtr){ // FUNCTION NOT COMPLETE!

	listPtr = NULL;
	return listPtr;
}