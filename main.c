#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"

#define MAXBINS 1000

int main(void){
	int i, j, numRuns, itemsInRun, currentBin, currentItem;
	ItemP item;

	// read bins.txt and binItems.txt
	FILE *fpBins = fopen("bins.txt", "r");
	FILE *fpBinItems = fopen("binItems.txt", "r");
	fscanf(fpBinItems, "%d", &numRuns);

	// create binList structure and init by adding a Bin
	ListP binList = createBinList();
	fscanf(fpBins, "%d", &currentBin);
	addBinToList(binList, currentBin);

	// start packing!
	for (i = 0; i < numRuns; i++){
		fscanf(fpBinItems, "%d", &itemsInRun); // get number of items in current run
		for (j = 0; j < itemsInRun; j++){
			fscanf(fpBinItems, "%d", &currentItem);
			item = createItem(currentItem);
			// call Online First Fit Here!
		}
	}

	getchar();
	return 0;
}