#ifndef INVENTORY
#define INVENTORY


#include "utility.h"


void InitItem(Item *it, std::string title, std::string manufacturer);

void ItemPrint(Item *it);

//inventory stuff

void InitLLInvNode(LLInvNode *inn ,Item *item, int quantity, double price, LLInvNode *next = NULL);

void InitLLInventory (LLInventory *inv);

//adds item to the end of inventory.
void InvAddItem(LLInventory *inv, Item *item, int quantity, double price);

//finds the info from LLInvNode by item pointer
LLInvNode* InvFindNode(LLInventory *inv, Item *item);

void InvNodePrint(LLInvNode *stuff);

//deletes item from inventory, searching through linked list to find it
void InvRemoveItem(LLInventory *inv, Item *item);

void InvShowOutOfStock(LLInventory *inv);

void InvPrint(LLInventory *inv);

#endif
