#pragma once
#include <array>
#include <atomic>
#include <cstddef>
#include <optional>

template<class T, std::size_t Capacity>
class SpscRing {
  static_assert(Capacity>=2);
  std::array<T,Capacity> slots_{};
  std::atomic<std::size_t> head_{0}; // next element consumer reads
  std::atomic<std::size_t> tail_{0}; // next slot producer writes
public:
  bool try_push(const T& x){
    auto t=tail_.load(std::memory_order_relaxed);
    auto n=(t+1)%Capacity;
    // BUG: relaxed load does not synchronize with consumer's read/destruction.
    if(n==head_.load(std::memory_order_relaxed)) return false;
    slots_[t]=x;
    tail_.store(n,std::memory_order_relaxed); // BUG: publishes before payload is synchronized.
    return true;
  }
  std::optional<T> try_pop(){
    auto h=head_.load(std::memory_order_relaxed);
    if(h==tail_.load(std::memory_order_relaxed)) return {};
    T x=slots_[h];
    head_.store((h+1)%Capacity,std::memory_order_relaxed);
    return x;
  }
};
