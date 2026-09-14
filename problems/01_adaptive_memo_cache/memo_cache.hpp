#pragma once
#include <functional>
#include <unordered_map>

class MemoCache {
public:
    using ExpensiveFn = std::function<int(int)>;
    explicit MemoCache(ExpensiveFn fn, std::size_t capacity = 1024)
        : fn_(std::move(fn)), capacity_(capacity) {}

    int get(int key) {
        auto it = values_.find(key);
        if (it != values_.end()) return it->second;
        int v = fn_(key);
        // Brownfield issue: capacity_ is currently ignored.
        values_.emplace(key, v);
        return v;
    }

    std::size_t size() const { return values_.size(); }
    std::size_t capacity() const { return capacity_; }

private:
    ExpensiveFn fn_;
    std::size_t capacity_;
    std::unordered_map<int,int> values_;
};
