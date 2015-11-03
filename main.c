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
	int i, j, numRuns, itemsInRun, currentItem;
	int *items; // use for holding the size of all items in a run

	// read bins.txt and binItems.txt
	fpBins = fopen("bins.txt", "r");
	fpBinItems = fopen("binItems.txt", "r");
	fscanf(fpBinItems, "%d", &numRuns);

	// create a BinList structure for each algorithm
	ListP binList1 = createBinList();
	ListP binList2 = createBinList();
	ListP binList3 = createBinList();
	ListP binList4 = createBinList();
	ListP binList5 = createBinList();

	// start packing!
	for (i = 0; i < numRuns; i++){
		fscanf(fpBinItems, "%d", &itemsInRun); // get number of items in current run
		items = malloc(sizeof(int) * itemsInRun);
		for (j = 0; j < itemsInRun; j++){
			fscanf(fpBinItems, "%d", &currentItem);
			items[j] = currentItem;
		}
		// perform all 5 algorithms
		OnlineFirstFit(binList1, items, itemsInRun);
		OnlineNextFit(binList2, items, itemsInRun);
		OnlineBestFit(binList3, items, itemsInRun);
		OfflineFirstFit(binList4, items, itemsInRun);
		OfflineBestFit(binList5, items, itemsInRun);

		// print results
		printf("Run %d\n", i+1);
		printTables(binList1, binList2, binList3, binList4, binList5);
		
		// reset all binLists and data
		binList1 = resetBinList(binList1);
		binList2 = resetBinList(binList2);
		binList3 = resetBinList(binList3);
		binList4 = resetBinList(binList4);
		binList5 = resetBinList(binList5);
		free(items);
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
	printf("  First Fit:        %d\n", binList4->numBins);
	printf("  Best Fit:         %d\n", binList5->numBins);
	printf("\n");
	
	printf("Results of Online First Fit");
	printBins(binList1);
	printf("Results of Online Next Fit");
	printBins(binList2);
	printf("Results of Online Best Fit");
	printBins(binList3);
	printf("Results of Offline First Fit");
	printBins(binList4);
	printf("Results of Offline Best Fit");
	printBins(binList5);
	printf("----------------------------------------------\n");
}