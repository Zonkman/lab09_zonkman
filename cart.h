#ifndef CART
#define CART

#include "utility.h"
#include "inventory.h"

void InitLLCartNode(LLCartNode *icn, Item *item, LLCartNode *next = NULL);

void InitLLUserCart (LLUserCart *uc);

//transfers quantities from ive to cart
void AddToCart(LLInventory *inv, LLUserCart *cart, Item *item);

void RemoveFromCart(LLInventory *inv, LLUserCart *cart, Item *item, bool putBack = true);

void DeleteCart(LLInventory *inv, LLUserCart *cart, bool putBack);

void PrintCart(LLInventory *inv, LLUserCart *cart);

#endif
