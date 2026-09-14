#include "producer.hpp"
#include <cassert>
#include <iostream>
struct Fake: Endpoint { int calls=0; std::vector<std::string> got; void send_batch(std::vector<std::string> b) override {++calls; for(auto &x:b) got.push_back(x);} };
int main(){ Fake f; Producer p(f,2,std::chrono::milliseconds(100)); p.send_message("a"); assert(f.calls==0); p.send_message("b"); assert(f.calls==1); assert(f.got.size()==2); std::cout<<"baseline ok\n"; }
