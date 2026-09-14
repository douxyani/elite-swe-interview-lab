#pragma once
#include <cassert>
#include <cstddef>
#include <memory>
#include <new>
#include <utility>

template<class T, std::size_t N>
class SmallVector {
  alignas(T) std::byte inline_[sizeof(T) * (N ? N : 1)];
  T* data_ = reinterpret_cast<T*>(inline_);
  std::size_t size_=0, cap_=N;
  bool heap_=false;
public:
  SmallVector()=default;
  ~SmallVector(){ clear(); if(heap_) ::operator delete(data_, std::align_val_t(alignof(T))); }
  SmallVector(const SmallVector&)=delete; // later stage
  SmallVector& operator=(const SmallVector&)=delete;

  std::size_t size() const {return size_;} std::size_t capacity() const {return cap_;}
  T& operator[](std::size_t i){assert(i<size_); return data_[i];}
  const T& operator[](std::size_t i) const {assert(i<size_); return data_[i];}

  void push_back(const T& x){ if(size_==cap_) grow(); std::construct_at(data_+size_,x); ++size_; }
  void clear(){ while(size_) std::destroy_at(data_ + --size_); }
private:
  void grow(){
    std::size_t next = cap_ ? cap_*2 : 1;
    T* p = static_cast<T*>(::operator new(sizeof(T)*next, std::align_val_t(alignof(T))));
    std::size_t made=0;
    try { for(; made<size_; ++made) std::construct_at(p+made, data_[made]); }
    catch(...) { while(made) std::destroy_at(p+--made); ::operator delete(p,std::align_val_t(alignof(T))); throw; }
    for(std::size_t i=0;i<size_;++i) std::destroy_at(data_+i);
    if(heap_) ::operator delete(data_,std::align_val_t(alignof(T)));
    data_=p; cap_=next; heap_=true;
  }
};
