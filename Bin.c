/***************************************************************
Gedd Johnson
Generation.h
Project 4:  Bin Packing

Private implementation of the BinList and Bin ADTs.
***************************************************************/
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

ListP resetBinList(ListP listPtr){
	freeBinList(listPtr); // free all memory used by BinList
	listPtr = createBinList(); // create a new BinList and init with a Bin
	return listPtr;
}


void printBins(ListP listPtr){
	int i;
	BinP currentBin = listPtr->head;
	ItemP item;
	printf("\n");
	for (i = 0; i < listPtr->numBins; i++){ // iterate through bins
		item = currentBin->firstItem;
		printf("Bin %d: ", currentBin->capacity);
		while (item != NULL){ // iterate through items in each bin
			printf("%d ", item->size);
			item = item->nextItem;
		}
		currentBin = currentBin->nextBin; // next Bin
		printf("\n");
	}
	printf("Bins used: %d\n\n", listPtr->numBins);
	return;
}

ListP freeBinList(ListP listPtr){
	int i;
	BinP currentBin = listPtr->head, tmpBin;
	ItemP item, tmpItem; // use tmp for freeing

	for (i = 0; i < listPtr->numBins; i++){ // iterate through bins
		item = currentBin->firstItem;

		while (item != NULL){ // iterate through items in each bin
			tmpItem = item;
			item = item->nextItem;
			freeItem(tmpItem);
		}
		tmpBin = currentBin;
		currentBin = currentBin->nextBin; // next Bin
		free(tmpBin);
	}
	free(listPtr);
	listPtr = NULL;
	return listPtr;
}