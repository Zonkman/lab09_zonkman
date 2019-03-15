#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <cstdlib>
#include <iostream>

//Properties of a kind of item
struct Item {
  std::string title;
  std::string manufacturer;
};

//A node for the inventory, contains price and quantity information as well as item info
struct LLInvNode {
  Item* item;
  int quantity;
  double price;

  LLInvNode *next;
};

//Linked list that contains the whole inventory
struct LLInventory {
  LLInvNode *head;
  LLInvNode *tail;
};

//for users' carts
struct LLCartNode {
  Item* item;
  LLCartNode *next;
};

struct LLUserCart {
  LLCartNode *head;
  LLCartNode *tail;
};

#endif
