#include<stdio.h>
#include<stdlib.h>
#include"Bin.h"
#include"Item.h"

ItemP createItem(int size){
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