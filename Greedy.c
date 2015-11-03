#define _CRT_SECURE_NO_DEPRECATE

#include<stdlib.h>
#include<stdio.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

/**
* First Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void FirstFit(ListP, ItemP);

/**
* Next Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT, pointer to the current Bin
* return: pointer to the last Bin an item was placed in
*/
BinP NextFit(ListP, ItemP, BinP);

/**
* Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void BestFit(ListP, ItemP);

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


/**
* Mergesort function to sort the items in descending order. Used for offline algorithms.
*
*
*/
void mergeSort(int *originalArray, int total);
void mergeBack(int *sortedArray, int *array1, int total1, int *array2, int total2);

void OnlineFirstFit(ListP listPtr, int* allItems, int itemsInRun){
	int j, currentBin, currentItem;
	ItemP item;
	rewind(fpBins); // ensure every algorithm starts with the same Bin
	fscanf(fpBins, "%d", &currentBin);
	addBinToList(listPtr, currentBin);
	for (j = 0; j < itemsInRun; j++){
		currentItem = allItems[j];
		item = createItem(currentItem);
		FirstFit(listPtr, item);
	}
}

void OnlineNextFit(ListP listPtr, int* allItems, int itemsInRun){
	int j, currentBin, currentItem;
	BinP bin;
	ItemP item;
	rewind(fpBins);
	fscanf(fpBins, "%d", &currentBin);
	bin = addBinToList(listPtr, currentBin);
	for (j = 0; j < itemsInRun; j++){
		currentItem = allItems[j];
		item = createItem(currentItem);
		bin = NextFit(listPtr, item, bin);
	}
}

void OnlineBestFit(ListP listPtr, int* allItems, int itemsInRun){
	int j, currentBin, currentItem;
	ItemP item;
	rewind(fpBins); // ensure every algorithm starts with the same Bin
	fscanf(fpBins, "%d", &currentBin);
	addBinToList(listPtr, currentBin);
	for (j = 0; j < itemsInRun; j++){
		currentItem = allItems[j];
		item = createItem(currentItem);
		BestFit(listPtr, item);
	}
}

void OfflineFirstFit(ListP listPtr, int *allItems, int itemsInRun){
	int j, currentItem, currentBin;
	ItemP item;

	// sort allItems
	mergeSort(allItems, itemsInRun);

	// create items and pack
	rewind(fpBins); // ensure every algorithm starts with the same Bin
	fscanf(fpBins, "%d", &currentBin);
	addBinToList(listPtr, currentBin);
	for (j = 0; j < itemsInRun; j++){
		currentItem = allItems[j];
		item = createItem(currentItem);
		FirstFit(listPtr, item);
	}
	return;
}

void OfflineBestFit(ListP listPtr, int *allItems, int itemsInRun){
	int j;
	int currentItem, currentBin;
	ItemP item;

	// sort allItems
	mergeSort(allItems, itemsInRun);

	// create items and pack
	rewind(fpBins); // ensure every algorithm starts with the same Bin
	fscanf(fpBins, "%d", &currentBin);
	addBinToList(listPtr, currentBin);
	for (j = 0; j < itemsInRun; j++){
		currentItem = allItems[j];
		item = createItem(currentItem);
		BestFit(listPtr, item);
	}
	return;
}

void FirstFit(ListP listPtr, ItemP itemPtr){
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

BinP NextFit(ListP listPtr, ItemP itemPtr, BinP binPtr){
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

void BestFit(ListP listPtr, ItemP itemPtr){
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
		//fprintf(stderr, "Item of size %d has been thrown away\n", itemPtr->size);
		freeItem(itemPtr);
	}
	return currentBin;
}

void mergeSort(int *originalArray, int total){
	if (total <= 1) // array has been sorted
		return;
	int i; // counter 
	int newTotal1 = total / 2; // get half of the elements
	int newTotal2 = total - newTotal1;  // get the rest of the elements
	int *newArray1 = malloc(sizeof(int) * newTotal1); // dynamically create new arrays to fit elements
	int *newArray2 = malloc(sizeof(int) * newTotal2);
	if (newArray1 == NULL || newArray2 == NULL){
		fprintf(stderr, "ERROR -> Ran out of memory\n");
		return;
	}

	// copy data from old array into new arrays
	for (i = 0; i < newTotal1; i++)
		newArray1[i] = originalArray[i];

	for (i = 0; i < newTotal2; i++)
		newArray2[i] = originalArray[i + newTotal1]; // need to add newTotal1 to get to the second half of old array

	mergeSort(newArray1, newTotal1);
	mergeSort(newArray2, newTotal2);
	mergeBack(originalArray, newArray1, newTotal1, newArray2, newTotal2);
	free(newArray1);
	free(newArray2);
	return;
}

void mergeBack(int *sortedArray, int *array1, int total1, int *array2, int total2){
	int sortedIndex = 0; // corresponds to the final sorted array
	int index1 = 0; // corresponds to newArray1
	int index2 = 0; // corresponds to newArray2
	while (index1 < total1 && index2 < total2){
		if (array1[index1] >= array2[index2]){ // sort descending
			sortedArray[sortedIndex] = array1[index1];
			index1++;
			sortedIndex++;
		}
		else{
			sortedArray[sortedIndex] = array2[index2];
			index2++;
			sortedIndex++;
		}
	}
	while (index1 < total1){ // is array1 empty?
		sortedArray[sortedIndex] = array1[index1];
		index1++;
		sortedIndex++;
	}
	while (index2 < total2){ // is array2 empty?
		sortedArray[sortedIndex] = array2[index2];
		index2++;
		sortedIndex++;
	}
	return;
}