#include "cart.h"

//testing

int main()
{
  std::cout << std::endl;
  std::cout << "Tests of inventory system" << std::endl;
  std::cout << std::endl;

  LLInventory *inventory = new LLInventory;
  InitLLInventory(inventory);

  std::cout << std::endl;
  std::cout << "creating 3 items" << std::endl;
  std::cout << std::endl;

  Item *ps5 = new Item;
  InitItem(ps5, "PlayZtation 5", "Zony");

  Item *xphone = new Item;
  InitItem(xphone, "xPhone XII", "Quince Inc.");

  Item *nins = new Item;
  InitItem(nins, "Nintondo Shuffle","Nintondo");

  std::cout << std::endl;
  std::cout << "add them to inventory" << std::endl;
  std::cout << std::endl;

  InvAddItem(inventory, ps5, 0, 499.5);
  InvAddItem(inventory, xphone, 3, 810.0);
  InvAddItem(inventory, nins, 1, 249.99);

  InvPrint(inventory);

  std::cout << std::endl;
  std::cout << "test out of stock, pz5 should be out of stock" << std::endl;
  std::cout << std::endl;

  InvShowOutOfStock(inventory);

  std::cout << std::endl;
  std::cout << "add things to cart" << std::endl;
  std::cout << std::endl;

  LLUserCart *cart = new LLUserCart;
  InitLLUserCart(cart);

  AddToCart(inventory, cart, nins);
  AddToCart(inventory, cart, xphone);
  AddToCart(inventory, cart, xphone);

  std::cout << std::endl;
  std::cout << "try to buy pz5 and get error" <<std::endl;
  std::cout << std::endl;

  AddToCart(inventory, cart, ps5);

  std::cout << std::endl;

  PrintCart(inventory, cart);

  std::cout << std::endl;
  std::cout << "buy more xPhones" << std::endl;
  std::cout << std::endl;

  AddToCart(inventory, cart, xphone);
  AddToCart(inventory, cart, xphone);
  
  std::cout << std::endl;
  std::cout << "xphones are now out of stock" << std::endl;
  std::cout << std::endl;

  PrintCart(inventory, cart);

  std:: cout << std::endl;

  InvShowOutOfStock(inventory);

  std::cout << std::endl;
  std::cout << "they only want two xphones now, they will put one back" << std::endl;
  std::cout << std::endl;

  RemoveFromCart(inventory, cart, xphone, true);

  PrintCart(inventory, cart);

  std::cout << std::endl;
  std::cout << "also they're more of a y-box fan, no nintondo" << std::endl;
  std::cout << std::endl;

  RemoveFromCart(inventory, cart, nins, true);

  PrintCart(inventory, cart);

  std::cout << std::endl;
  std::cout << "now they checked out so their cart is meaningless, delete it" << std::endl;
  std::cout << std::endl;

  DeleteCart(inventory, cart, false); //the false means items aren't put back in stock 

  std::cout << std::endl;
  std::cout << "let's stock 79x hydroflux, print whole inventory" << std::endl;
  std::cout << std::endl;

  Item *hfl = new Item;
  InitItem(hfl, "Hydroflux Thermos","Whoever Makes Thermoses Ltd.");
  InvAddItem(inventory, hfl, 79, 10.0);  

  InvPrint(inventory);

  std::cout << std::endl;

  return 0;
}



