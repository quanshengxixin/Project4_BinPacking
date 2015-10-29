#ifndef _Item_h
#define _Item_h

typedef struct Item *ItemP;

// Item ADT
struct Item{
	int size;
	ItemP nextItem;
};

/**
* Creates a new Item ADT
*
* @param: size of the Item
* return: pointer to the new Item
*/
ItemP createItem(int);

/**
* Frees the memory used by an Item ADT
*
* @params: pointer to the Item ADT
* return: NULL pointer
*/
ItemP freeItem(ItemP);

#endif