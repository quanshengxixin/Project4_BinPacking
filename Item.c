/***************************************************************
Gedd Johnson
Generation.h
Project 4:  Bin Packing

Private implementation of the Item ADT.
***************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"

ItemP createItem(int size){
	if (size < 0){ // ensure size is > 0
		fprintf(stderr, "Item size was < 0\n");
		return NULL;
	}

	ItemP itemPtr = malloc(sizeof(struct Item));
	itemPtr->size = size;
	itemPtr->nextItem = NULL;
	return itemPtr;
}

ItemP freeItem(ItemP itemPtr){
	free(itemPtr);
	itemPtr = NULL;
	return itemPtr;
}