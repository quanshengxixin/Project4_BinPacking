#ifndef _Greedy_h
#define _Greedy_h
#include"Bin.h"
#include"Item.h"

FILE *fpBins, *fpBinItems;

/**
* Online First Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OnlineFirstFit(ListP, ItemP);

/**
* Online Next Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT, pointer to the current Bin
* return: pointer to the last Bin an item was placed in
*/
BinP OnlineNextFit(ListP, ItemP, BinP);

/**
* Online Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OnlineBestFit(ListP, ItemP);

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