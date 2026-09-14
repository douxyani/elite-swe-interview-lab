#pragma once
#include <cstdint>
#include <list>
#include <map>
#include <optional>
#include <stdexcept>
#include <unordered_map>

struct Order { long id; char side; int price; int qty; };

class OrderBook {
    struct Loc { char side; int price; std::list<Order>::iterator it; };
    std::map<int,std::list<Order>,std::greater<int>> bids_;
    std::map<int,std::list<Order>> asks_;
    std::unordered_map<long,Loc> by_id_;
public:
    bool add(Order o) {
        if (o.qty<=0 || (o.side!='B' && o.side!='S') || by_id_.contains(o.id)) return false;
        if(o.side=='B') { auto &q=bids_[o.price]; q.push_back(o); by_id_[o.id]={'B',o.price,std::prev(q.end())}; }
        else { auto &q=asks_[o.price]; q.push_back(o); by_id_[o.id]={'S',o.price,std::prev(q.end())}; }
        return true;
    }
    bool cancel(long id) {
        auto f=by_id_.find(id); if(f==by_id_.end()) return false;
        auto loc=f->second;
        if(loc.side=='B'){ auto p=bids_.find(loc.price); p->second.erase(loc.it); if(p->second.empty()) bids_.erase(p); }
        else { auto p=asks_.find(loc.price); p->second.erase(loc.it); if(p->second.empty()) asks_.erase(p); }
        by_id_.erase(f); return true;
    }
    bool trade(long id, int qty) { (void)id; (void)qty; return false; /* TODO */ }
    std::optional<int> best_bid() const { if(bids_.empty()) return {}; return bids_.begin()->first; }
    std::optional<int> best_ask() const { if(asks_.empty()) return {}; return asks_.begin()->first; }
    std::optional<Order> find(long id) const { auto f=by_id_.find(id); if(f==by_id_.end()) return {}; return *f->second.it; }
};
