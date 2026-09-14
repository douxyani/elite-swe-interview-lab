#pragma once
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
struct Trade { long long ts; std::string symbol; long long id; long long qty; long long price; };
inline std::vector<Trade> canonicalize(std::vector<Trade> xs){
  std::sort(xs.begin(),xs.end(),[](auto const&a,auto const&b){return std::tie(a.ts,a.symbol,a.id)<std::tie(b.ts,b.symbol,b.id);});
  // Brownfield: duplicate IDs/conflicts are not handled.
  return xs;
}
