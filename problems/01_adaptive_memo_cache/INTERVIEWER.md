# Interviewer follow-ups — open one at a time

## Stage 1 — bounded FIFO
Implement a hard entry bound. Evict oldest inserted entries. Expected O(1) hit/insert/evict.

## Stage 2 — LRU
Traffic is skewed and FIFO destroys hot entries. Change policy to true LRU, still O(1) expected. Explain the exact list/map invariant before coding.

## Stage 3 — weighted capacity + TTL
Each result now has a byte weight and expiration deadline. Bound **total weight**, not item count. An expired entry behaves as absent. Use an injected monotonic clock; do not scatter calls to wall-clock time through the cache.

## Stage 4 — concurrent single-flight
Many threads may ask for the same missing key. The expensive function must execute at most once for a key at a time; other callers wait for that result. Calls for unrelated keys should not serialize behind the computation. Define behavior if computation throws.

## Stage 5 — observability / adversarial reasoning
Expose hit/miss/eviction counters without putting one global contended atomic on the hottest path if you can avoid it. Explain resize-to-zero, reentrant compute, integer overflow in total weight, and destruction while waiters exist.
