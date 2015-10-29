#include<stdlib.h>
#include"Bin.h"
#include"Item.h"
#include"Greedy.h"

void OnlineFirstFit(ListP listPtr, ItemP itemPtr){

}

void OnlineNextFit(ListP listPtr, ItemP itemPtr){

}

void OnlineBestFit(ListP listPtr, ItemP itemPtr){

}

void OfflineFirstFit(ListP listPtr, ItemP itemPtr){

}

void OfflineBestFit(ListP listPtr, ItemP itemPtr){

}

/* // example to traverse Multi Linked List
void addItemToBin(ListP listPtr, ItemP newItem){
// testing purposes
if (listPtr->head->firstItem == NULL){
listPtr->head->firstItem = newItem;
return;
}

// else traverse the list of Items
ItemP tmp = listPtr->head->firstItem;
while (tmp->nextItem != NULL){
tmp = tmp->nextItem;
}

tmp->nextItem = newItem;
return;
}
*/
