#include "memo_cache.hpp"
#include <cassert>
#include <iostream>
int main(){
    int calls=0;
    MemoCache c([&](int x){++calls; return x*x;}, 2);
    assert(c.get(3)==9); assert(c.get(3)==9); assert(calls==1);
    assert(c.get(4)==16); assert(c.size()==2);
    std::cout << "baseline ok; Stage 1 should add eviction tests\n";
}
