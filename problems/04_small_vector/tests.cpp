#include "small_vector.hpp"
#include <cassert>
#include <iostream>
int main(){ SmallVector<int,3> v; v.push_back(1);v.push_back(2);v.push_back(3); assert(v.capacity()==3); v.push_back(4); assert(v.size()==4); assert(v[3]==4); assert(v.capacity()>=4); std::cout<<"baseline int test ok\n"; }
