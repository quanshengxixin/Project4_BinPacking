#ifndef _Bin_h
#define _Bin_h
#include"Item.h"

typedef struct BinList *ListP;
typedef struct Bin *BinP;

// BinList ADT
struct BinList{
	int numBins;
	BinP head;
};

// Bin ADT
struct Bin{
	int capacity;
	int currentSize;
	BinP nextBin;
	ItemP firstItem;
};

/**
* Creates a bin list ADT
*
* return: pointer to the BinList ADT
*/
ListP createBinList();

/**
* Creaes a new Bin ADT and adds it to the BinList
*
* @params: pointer to the BinList, capacity of new Bin
* return: pointer to the new Bin
*/
BinP addBinToList(ListP, int);

/**
* Prints all Bins and Items in each Bin
*
* @params: pointer to the BinList
*/
void printBins(ListP);

/**
* Frees the memory used by the BinList including all Bins and Items
*
* @params: pointer to the BinList
* return: NULL pointer
*/
ListP freeBinList(ListP);

#endif