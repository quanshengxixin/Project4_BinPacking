#define _CRT_SECURE_NO_DEPRECATE

#include<stdlib.h>
#include<stdio.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

void OnlineFirstFit(ListP listPtr, ItemP itemPtr){
	int i;
	BinP currentBin = listPtr->head;
	ItemP q; // use for traversing list of Items in each Bin

	// find the first Bin that the Item will fit in
	for (i = 0; i < listPtr->numBins; i++){
		if (itemPtr->size <= currentBin->capacity - currentBin->currentSize){ // if item fits in Bin
			// update currentSize in Bin and place Item in Bin
			if (currentBin->firstItem == NULL){	// if first Item in Bin
				currentBin->firstItem = itemPtr;
				currentBin->currentSize += itemPtr->size;
			}
			else{ // else place Item at the end of the list
				q = currentBin->firstItem;
				currentBin->currentSize += itemPtr->size;
				while (q->nextItem != NULL){
					q = q->nextItem; // traverse Item list
				}
				q->nextItem = itemPtr;
			}
			return; // item has been placed in Bin
		}
		currentBin = currentBin->nextBin; // if item does NOT fit in currentBin, go to nextBin
	}

	// Item could not fit in any Bin; create new Bin
	int newBinSize;
	fscanf(fpBins, "%d", &newBinSize);
	currentBin = addBinToList(listPtr, newBinSize);

	// Ensure Item can fit in newly created Bin
	if (itemPtr->size <= currentBin->capacity){
		currentBin->currentSize += itemPtr->size;
		currentBin->firstItem = itemPtr;
	}
	else{ // if Item is still too big, report and throw away!
		fprintf(stderr, "Item of size %d has been thrown away\n", itemPtr->size);
		freeItem(itemPtr);
	}
	return;
}

void OnlineNextFit(ListP listPtr, ItemP itemPtr, int index){
	int i;
	BinP currentBin = listPtr->head;
	ItemP q; // use for traversing list of Items in each Bin

	// get to last Bin checked
	for (i = 0; i < listPtr->lastBinChecked; i++){
		if (currentBin->nextBin == NULL) break;
		currentBin = currentBin->nextBin;
	}

	// find the next Bin that the Item will fit into
	for (i = 0; i < listPtr->numBins - listPtr->lastBinChecked; i++){
		if (itemPtr->size <= currentBin->capacity - currentBin->currentSize){ // if item fits in Bin
			// update currentSize in Bin and place Item in Bin
			if (currentBin->firstItem == NULL){	// if first Item in Bin
				currentBin->firstItem = itemPtr;
				currentBin->currentSize += itemPtr->size;
			}
			else{ // else place Item at the end of the list
				q = currentBin->firstItem;
				currentBin->currentSize += itemPtr->size;
				while (q->nextItem != NULL){
					q = q->nextItem; // traverse Item list
				}
				q->nextItem = itemPtr;
			}
			listPtr->lastBinChecked = currentBin->binIndex;
			return; // item has been placed in Bin
		}
		if (currentBin->nextBin == NULL) break;
		currentBin = currentBin->nextBin; // if item does NOT fit in currentBin, go to nextBin
	}

	// Item could not fit in any Bin; create new Bin
	int newBinSize;
	fscanf(fpBins, "%d", &newBinSize);
	currentBin = addBinToList(listPtr, newBinSize);

	// Ensure Item can fit in newly created Bin
	if (itemPtr->size <= currentBin->capacity){
		currentBin->currentSize += itemPtr->size;
		currentBin->firstItem = itemPtr;
		}

	else{ // if Item is still too big, report and throw away!
		fprintf(stderr, "Item of size %d has been thrown away\n", itemPtr->size);
		freeItem(itemPtr);
	}
	listPtr->lastBinChecked = currentBin->binIndex;
	return;
}

void OnlineBestFit(ListP listPtr, ItemP itemPtr){

}

void OfflineFirstFit(ListP listPtr, ItemP itemPtr){

}

void OfflineBestFit(ListP listPtr, ItemP itemPtr){

}