#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

#define MAXBINS 1000

/**
* Prints the tables showing the number of Bins used by each of the 5 algorithms
* and prints the contents of each Bin following each table.
* 
* @params: pointer to each BinList corresponding to each of the 5 algorithms used
*/
void printTables(ListP, ListP, ListP, ListP, ListP);

int main(void){
	int i, j, numRuns, itemsInRun, currentBin, currentItem;
	ItemP item1, item2, item3, item4, item5;
	BinP bin, bin2;

	// read bins.txt and binItems.txt
	fpBins = fopen("bins.txt", "r");
	fpBinItems = fopen("binItems.txt", "r");
	fscanf(fpBinItems, "%d", &numRuns);

	// create a BinList structure for each algorithm and init by adding a Bin
	ListP binList1 = createBinList();
	ListP binList2 = createBinList();
	ListP binList3 = createBinList();
	ListP binList4 = createBinList();
	ListP binList5 = createBinList();
	fscanf(fpBins, "%d", &currentBin);
	bin = addBinToList(binList1, currentBin);
	bin2 = addBinToList(binList2, currentBin);
	bin = addBinToList(binList3, currentBin);
	bin = addBinToList(binList4, currentBin);
	bin = addBinToList(binList5, currentBin);

	// start packing!
	for (i = 0; i < numRuns; i++){
		fscanf(fpBinItems, "%d", &itemsInRun); // get number of items in current run
		for (j = 0; j < itemsInRun; j++){
			fscanf(fpBinItems, "%d", &currentItem);
			item1 = createItem(currentItem); // create an item for each of the 5 algorithms
			item2 = createItem(currentItem);
			item3 = createItem(currentItem);
			item4 = createItem(currentItem);
			item5 = createItem(currentItem);

			// perform all 5 algorithms
			OnlineFirstFit(binList1, item1);

			bin2 = OnlineNextFit(binList2, item2, bin2);

			OnlineBestFit(binList3, item3);
		}
		printTables(binList1, binList2, binList3, binList4, binList5);
		
		// reset all binLists
		binList1 = resetBinList(binList1);
		binList2 = resetBinList(binList2);
		bin2 = binList2->head;
		binList3 = resetBinList(binList3);
	}

	// free all BinLists and close files
	binList1 = freeBinList(binList1);
	binList2 = freeBinList(binList2);
	binList3 = freeBinList(binList3);
	binList4 = freeBinList(binList4);
	binList5 = freeBinList(binList5);
	fclose(fpBinItems);
	fclose(fpBins);

	getchar();
	return 0;
}

void printTables(ListP binList1, ListP binList2, ListP binList3, ListP binList4, ListP binList5){
	printf("\n    Policy     Number of Bins\n");
	printf("Online\n");
	printf("  First Fit:        %d\n", binList1->numBins);
	printf("  Next Fit:         %d\n", binList2->numBins);
	printf("  Best Fit:         %d\n", binList3->numBins);
	printf("Offline\n");
	printf("  First Fit:      \n");
	printf("  Best Fit:       \n");
	printf("\n");

	printf("Results of Online First Fit");
	printBins(binList1);
	printf("Results of Online Next Fit");
	printBins(binList2);
	printf("Results of Online Best Fit");
	printBins(binList3);
	printf("----------------------------------------------\n");
}