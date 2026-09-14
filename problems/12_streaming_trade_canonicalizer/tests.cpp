#include "trade.hpp"
#include <cassert>
#include <iostream>
int main(){ std::vector<Trade> x{{2,"A",2,1,10},{1,"B",1,1,20},{1,"A",3,1,30}}; auto y=canonicalize(x); assert(y[0].symbol=="A"&&y[0].id==3); assert(y[1].symbol=="B"); std::cout<<"sort baseline ok; add duplicate/conflict policy\n"; }
