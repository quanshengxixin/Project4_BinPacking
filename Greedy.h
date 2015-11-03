#ifndef _Greedy_h
#define _Greedy_h
#include"Bin.h"
#include"Item.h"

FILE *fpBins, *fpBinItems;

void OnlineFirstFit(ListP, int*, int);

void OnlineNextFit(ListP, int*, int);

void OnlineBestFit(ListP, int*, int);

/**
* Offline First Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to a dynamic array holding all items, size of dynamic array
*/
void OfflineFirstFit(ListP, int*, int);

/**
* Offline Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to a dynamic array holding all items, size of dynamic array
*/
void OfflineBestFit(ListP, int*, int);

#endif