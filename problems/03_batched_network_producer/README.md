# 03 — Batched Network Producer

**Environment:** C++20. The `Endpoint` abstraction is synchronous and may be slow.

You inherit a producer that batches messages by count. Product requirements say each instance has both a maximum batch count and a maximum amount of time any accepted message may remain unsent. `send_message()` is called by application threads; the producer should reduce network calls without violating either bound.

Implement the time bound. Be precise about what “accepted” means, which clock is used, and whether a low-traffic producer can flush when no new call arrives.

### Provenance

A public Citadel SWE interview report from Feb 2020 describes a producer class that sends to a predefined network endpoint, caches/batches messages, accepts a maximum message count and maximum hold time, and may be shared: https://leetcode.com/discuss/post/619324/citadel-software-engineer-nyc-feb-2020/ . This starter and follow-ups are independently authored; later retry/backpressure stages are extensions.

For high-performance queue design ideas—not code to copy—see https://github.com/cameron314/concurrentqueue .
