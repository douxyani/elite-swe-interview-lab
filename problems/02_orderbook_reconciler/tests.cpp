#include "order_book.hpp"
#include <cassert>
#include <iostream>
int main(){
  OrderBook b; assert(b.add({10,'B',10025,7})); assert(b.add({11,'B',10025,4}));
  assert(!b.add({10,'B',10000,1})); assert(b.best_bid()==10025); assert(b.cancel(11)); assert(!b.cancel(11));
  std::cout << "baseline ok; implement TRADE next\n";
}
