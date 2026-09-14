#include "risk.hpp"
#include <cassert>
#include <iostream>
int main(){ assert(approve_trade("AAPL,100,100,USD")); assert(!approve_trade("AAPL,20000,100,USD")); assert(!approve_trade("AAPL,10,10,XYZ")); std::cout<<"characterization baseline ok; add more before refactor\n"; }
