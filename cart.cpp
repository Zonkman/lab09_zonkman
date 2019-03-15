#include "utility.h"
#include "inventory.h"
#include "cart.h"
//cart stuff

void InitLLCartNode(LLCartNode *icn, Item *item, LLCartNode *next) {
  icn->item = item;
  icn->next = next;
}

void InitLLUserCart (LLUserCart *uc) {
  uc->head = NULL;
  uc->tail = NULL;
}

//transfers quantities from ive to cart
void AddToCart(LLInventory *inv, LLUserCart *cart, Item *item) {
   LLInvNode *whatToBuy = InvFindNode(inv, item);
   if (whatToBuy->quantity == 0) {
     std::cout << "Failed to add, " << (item->title) <<" is not in stock right now :(" << std::endl;
   }
   else
   {
     whatToBuy->quantity -= 1;
     std::cout << "Adding " << (item->title) << " to your cart"<< std::endl;
     
     //this part adds the item to cart
     LLCartNode *newInCart = new LLCartNode;
     InitLLCartNode(newInCart, item); //last item, so it won't point to a next item

     if (cart->head == NULL) { //blank cart
       cart->head = newInCart;
       cart->tail = newInCart;
     }
     else {
       cart->tail->next = newInCart;
       cart->tail = newInCart;
     }
   }
}

void RemoveFromCart(LLInventory *inv, LLUserCart *cart, Item *item, bool putBack) {
  for (LLCartNode *n = cart->head; n != NULL; n = n->next) {
    if (n == cart->head && n->item == item) {
      cart->head = n->next;
      if (n->next == NULL) {
        cart->tail = NULL;
      }
      //make sure to put the item back in stock
      if (putBack) {
        LLInvNode *whatToPutBack = InvFindNode(inv, item);
        whatToPutBack->quantity += 1; 
      }
      delete n;
      return;
    }	  
    else if (n->next != NULL && n->next->item == item) {
      LLCartNode *nodeToDelete = n->next;
      n->next = nodeToDelete->next;
      if (nodeToDelete == cart->tail) { //changes tail of the linked list
        cart->tail = n;
      }
      //make sure to put the item back in stock
      if (putBack) {
        LLInvNode *whatToPutBack = InvFindNode(inv, item);
        whatToPutBack->quantity += 1;
      }
      delete nodeToDelete;
      return;
    }
  }
  std::cerr << "Couldn't find that item to remove, nothing changed." << std::endl;
}

void DeleteCart(LLInventory *inv, LLUserCart *cart, bool putBack) {
  
  LLCartNode *n = cart->head;
  while (n != NULL) {
    LLCartNode *toDelete = n;
    n = n->next;
    RemoveFromCart(inv, cart, toDelete->item, putBack);
  }
  //all items are gone, byebye cart
  delete cart;
}

void PrintCart(LLInventory *inv, LLUserCart *cart) {
  std::cout << "Cart:" << std::endl;

  for (LLCartNode *n = cart->head; n != NULL; n = n->next) {
    ItemPrint(n->item);
    //to get price
    LLInvNode *info = InvFindNode(inv, n->item);
    std::cout << "\tPrice: "<< (info->price) << std::endl;
  }
}


