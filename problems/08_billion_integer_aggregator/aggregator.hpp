#pragma once
#include <fstream>
#include <stdexcept>
#include <string>

inline long long sum_file(const std::string& path){
  std::ifstream in(path); if(!in) throw std::runtime_error("open failed");
  long long x=0, sum=0;
  // Brownfield: formatted IO may be slow and signed overflow is undefined behavior.
  while(in>>x) sum += x;
  if(!in.eof()) throw std::runtime_error("malformed input");
  return sum;
}
