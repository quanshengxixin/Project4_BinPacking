#define _CRT_SECURE_NO_DEPRECATE

#include<stdlib.h>
#include<stdio.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

/**
* Places an Item in the appropriate Bin and updates 
* currentSize of Bin. Will not place if Item does not fit any Bins
*
* @params: pointer to the current Bin, pointer to the Item
*/
void placeItemInBin(BinP, ItemP);

/**
* Places an Item in the appropriate Bin after all other Bin have been checked.  
* If Item still does not fit, throws Item away by freeing it.
*
* @params: BinList pointer, pointer to the current Bin, pointer to the Item
* return: pointer to the newly created Bin
*/
BinP itemTooLarge(ListP, BinP, ItemP);

void OnlineFirstFit(ListP listPtr, ItemP itemPtr){
	int i;
	BinP currentBin = listPtr->head;

	// find the first Bin that the Item will fit in
	for (i = 0; i < listPtr->numBins; i++){
		if (itemPtr->size <= currentBin->capacity - currentBin->currentSize){ // if item fits in Bin
			placeItemInBin(currentBin, itemPtr);
			return; // item has been placed in Bin
		}
		currentBin = currentBin->nextBin; // if item does NOT fit in currentBin, go to nextBin
	}
	// Item could not fit in any Bin; create new Bin
	itemTooLarge(listPtr, currentBin, itemPtr);
	return;
}

BinP OnlineNextFit(ListP listPtr, ItemP itemPtr, BinP binPtr){
	BinP currentBin = binPtr;

	// find the next Bin that the Item will fit into
	while (currentBin != NULL){
		if (itemPtr->size <= currentBin->capacity - currentBin->currentSize){ // if item fits in Bin
			placeItemInBin(currentBin, itemPtr);
			return currentBin; // item has been placed in Bin
		}
		if (currentBin->nextBin == NULL) break;
		currentBin = currentBin->nextBin; // if item does NOT fit in currentBin, go to nextBin
	}
	// Item could not fit in any Bin; create new Bin
	currentBin = itemTooLarge(listPtr, currentBin, itemPtr);
	return currentBin;
}

void OnlineBestFit(ListP listPtr, ItemP itemPtr){
	int i;
	int best = 101, current; // init best and current, used for checking space left in a Bin; best is now higher than any Bin size
	BinP currentBin = listPtr->head, bestBin = currentBin; // init bestBin

	// find the best Bin that the Item will fit in
	for (i = 0; i < listPtr->numBins; i++){
		if (itemPtr->size <= currentBin->capacity - currentBin->currentSize){ // if item fits in Bin
			current = currentBin->capacity - currentBin->currentSize - itemPtr->size; // space left in currentBin
			if (best >= current){ // check the space left in the Bin
				best = current; // update best and bestBin
				bestBin = currentBin;
			}
		}
		if (currentBin->nextBin == NULL) break;
		currentBin = currentBin->nextBin; // if item does NOT fit in currentBin, go to nextBin
	}
	if (best != 101){ // best Bin was found
		placeItemInBin(bestBin, itemPtr);
		return; // item has been placed in Bin
	}

	// Item could not fit in any Bin; create new Bin
	itemTooLarge(listPtr, currentBin, itemPtr);
	return;
}

void OfflineFirstFit(ListP listPtr, ItemP itemPtr){

}

void OfflineBestFit(ListP listPtr, ItemP itemPtr){

}

void placeItemInBin(BinP currentBin, ItemP itemPtr){
	ItemP q;
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
	return;
}

BinP itemTooLarge(ListP listPtr, BinP currentBin, ItemP itemPtr){
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
		freeItem(itemPtr); // throw away Item
	}
	return currentBin;
}