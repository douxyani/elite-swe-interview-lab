#include "aggregator.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
int main(){ const char* p="tiny_numbers.txt"; {std::ofstream o(p); o<<"10 -3 5\n";} assert(sum_file(p)==12); std::remove(p); std::cout<<"baseline ok\n"; }
