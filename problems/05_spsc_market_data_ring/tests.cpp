#include "spsc_ring.hpp"
#include <cassert>
#include <iostream>
int main(){ SpscRing<int,4> q; assert(!q.try_pop()); assert(q.try_push(1)); assert(q.try_push(2)); assert(*q.try_pop()==1); assert(*q.try_pop()==2); std::cout<<"single-thread baseline passes; concurrency semantics are the task\n"; }
