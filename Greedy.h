/***************************************************************
Gedd Johnson
Generation.h
Project 4:  Bin Packing

Public functionality of the Greedy algorithms.
***************************************************************/
#ifndef _Greedy_h
#define _Greedy_h
#include"Bin.h"
#include"Item.h"

// global file pointers
FILE *fpBins, *fpBinItems;

/**
* Online First Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to a dynamic array holding all items, size of dynamic array
*/
void OnlineFirstFit(ListP, int*, int);

/**
* Online Next Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to a dynamic array holding all items, size of dynamic array
*/
void OnlineNextFit(ListP, int*, int);

/**
* Online Best Fit algorithm
*
* @params: pointer to the BinList ADT, pointer to a dynamic array holding all items, size of dynamic array
*/
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