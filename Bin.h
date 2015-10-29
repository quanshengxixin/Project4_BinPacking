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
*/
void addBinToList(ListP, int);

/**
* Frees the memory used by the BinList including all Bins and Items
*
* @params: pointer to the BinList
* return: NULL pointer
*/
ListP freeBinList(ListP);

#endif