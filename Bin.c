#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

ListP createBinList(){
	ListP listPtr = malloc(sizeof(struct BinList));
	listPtr->numBins = 0;
	listPtr->head = NULL;
	listPtr->lastBinChecked = 0;
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
		binPtr->binIndex = listPtr->numBins-1;
		return binPtr;
	}
	
	// else not the first bin
	BinP tmp = listPtr->head; // use for traversing the Bins
	while (tmp->nextBin != NULL){
		tmp = tmp->nextBin; // traverse list of Bins
	}

	tmp->nextBin = binPtr;
	listPtr->numBins++;
	binPtr->binIndex = listPtr->numBins-1;

	return binPtr;
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
		currentBin = currentBin->nextBin;
		printf("\n");
	}
	return;
}

ListP freeBinList(ListP listPtr){ // FUNCTION NOT COMPLETE!

	listPtr = NULL;
	return listPtr;
}