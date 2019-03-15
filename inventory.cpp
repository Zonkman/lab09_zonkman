#include "utility.h"
#include "inventory.h"
//item stuff
void InitItem(Item *it, std::string title, std::string manufacturer) {
  it->title = title;
  it->manufacturer = manufacturer;
}

void ItemPrint(Item *it) {
  std::cout << (it->title) << ", made by " << (it->manufacturer) << std::endl;
}

//inventory stuff

void InitLLInvNode(LLInvNode *inn ,Item *item, int quantity, double price, LLInvNode *next) {
  inn->item = item;
  inn->quantity = quantity;
  inn->price = price;
  inn->next = next;
}

void InitLLInventory (LLInventory *inv) {
  inv->head = NULL;
  inv->tail = NULL;
}

//adds item to the end of inventory.
void InvAddItem(LLInventory *inv, Item *item, int quantity, double price) {
  
  LLInvNode *newNode = new LLInvNode;
  InitLLInvNode(newNode, item, quantity, price); //last item, so it won't point to a next item

  if (inv->head == NULL) { //blank linked list then
    inv->head = newNode;
    inv->tail = newNode;
  }
  else {
    inv->tail->next = newNode;
    inv->tail = newNode;
  }
}

//finds the info from LLInvNode by item pointer
LLInvNode* InvFindNode(LLInventory *inv, Item *item) {
  for (LLInvNode *n = inv->head; n != NULL; n = n->next) {
    if (n->item == item) { //point to same place: equal
      return n;
    }
  }
  return NULL;
}

void InvNodePrint(LLInvNode *stuff) {
  ItemPrint(stuff->item);
  std::cout << "\tQuantity: " << (stuff->quantity) << std::endl;
  std::cout << "\tPrice: " << (stuff->price) << " USD" << std::endl;
}

//deletes item from inventory, searching through linked list to find it
void InvRemoveItem(LLInventory *inv, Item *item) {
  for (LLInvNode *n = inv->head; n != NULL; n = n->next) {
    if (n == inv->head && n->item == item) {
      inv->head = n->next;
      delete n;
      return;
    }	  
    else if (n->next != NULL && n->next->item == item) {
      LLInvNode *nodeToDelete = n->next;
      n->next = nodeToDelete->next;
      if (nodeToDelete == inv->tail) { //changes tail of the linked list
        inv->tail = n;
      }
      delete nodeToDelete;
      return;
    }
  }
  std::cerr << "Couldn't find that item to remove, nothing changed.";
}

void InvShowOutOfStock(LLInventory *inv) {
  std::cout << "Items which are out of stock:" << std::endl;
  for (LLInvNode *n = inv->head; n != NULL; n = n->next) {
    if (n->quantity == 0) {
      InvNodePrint(n);
    }
  }
}

void InvPrint(LLInventory *inv) {
  std::cout << "Current inventory:"<<std::endl;
  for (LLInvNode *n = inv->head; n != NULL; n = n->next) {
    InvNodePrint(n);
  }
}


