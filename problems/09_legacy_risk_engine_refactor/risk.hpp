#pragma once
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

// Intentionally awkward legacy globals.
inline double g_usd_limit = 1'000'000.0;
inline std::unordered_map<std::string,double> g_fx{{"USD",1.0},{"GBP",1.25},{"EUR",1.10}};

inline bool approve_trade(const std::string& csv){
  // format: symbol,qty,price,currency
  std::stringstream ss(csv); std::string sym,qtys,prices,ccy;
  if(!std::getline(ss,sym,',')||!std::getline(ss,qtys,',')||!std::getline(ss,prices,',')||!std::getline(ss,ccy,',')) return false;
  int qty=std::atoi(qtys.c_str()); double price=std::atof(prices.c_str());
  auto f=g_fx.find(ccy); if(f==g_fx.end()) return false;
  double usd=std::abs(static_cast<double>(qty))*price*f->second;
  return usd <= g_usd_limit;
}
