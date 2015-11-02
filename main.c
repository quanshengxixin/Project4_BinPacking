#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

#define MAXBINS 1000

int main(void){
	int i, j, numRuns, itemsInRun, currentBin, currentItem;
	ItemP item;
	BinP bin;

	// read bins.txt and binItems.txt
	fpBins = fopen("bins.txt", "r");
	fpBinItems = fopen("binItems.txt", "r");
	fscanf(fpBinItems, "%d", &numRuns);

	// create binList structure and init by adding a Bin
	ListP binList = createBinList();
	fscanf(fpBins, "%d", &currentBin);
	bin = addBinToList(binList, currentBin);

	// start packing!
	for (i = 0; i < numRuns; i++){
		fscanf(fpBinItems, "%d", &itemsInRun); // get number of items in current run
		for (j = 0; j < itemsInRun; j++){
			fscanf(fpBinItems, "%d", &currentItem);

			// create item and place in Bin
			item = createItem(currentItem);
			//OnlineFirstFit(binList, item);
			bin = OnlineNextFit(binList, item, bin);
			//OnlineBestFit(binList, item);
		}
	}
	printBins(binList);
	printf("\nBins used: %d\n", binList->numBins);

	getchar();
	return 0;
}