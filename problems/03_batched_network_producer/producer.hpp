#pragma once
#include <chrono>
#include <cstddef>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

struct Endpoint { virtual ~Endpoint()=default; virtual void send_batch(std::vector<std::string> batch)=0; };

class Producer {
public:
  Producer(Endpoint& endpoint, std::size_t max_count, std::chrono::milliseconds max_hold)
    : endpoint_(endpoint), max_count_(max_count), max_hold_(max_hold) {}

  void send_message(std::string msg) {
    std::vector<std::string> out;
    {
      std::lock_guard lk(mu_);
      pending_.push_back(std::move(msg));
      // Brownfield behavior: only count triggers a flush; max_hold_ is unused.
      if(pending_.size() >= max_count_) out.swap(pending_);
    }
    if(!out.empty()) endpoint_.send_batch(std::move(out));
  }

  void flush() {
    std::vector<std::string> out;
    { std::lock_guard lk(mu_); out.swap(pending_); }
    if(!out.empty()) endpoint_.send_batch(std::move(out));
  }
private:
  Endpoint& endpoint_; std::size_t max_count_; std::chrono::milliseconds max_hold_;
  std::mutex mu_; std::vector<std::string> pending_;
};
