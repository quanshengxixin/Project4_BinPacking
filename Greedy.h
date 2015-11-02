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
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OnlineNextFit(ListP, ItemP);

/**
* Online Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OnlineBestFit(ListP, ItemP);

/**
* Offline First Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OfflineFirstFit(ListP, ItemP);

/**
* Offline Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to the Item ADT
*/
void OfflineBestFit(ListP, ItemP);

#endif