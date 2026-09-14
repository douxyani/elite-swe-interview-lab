# 01 — Adaptive Memo Cache

**Environment:** C++20. **Starting condition:** the existing memoizer is correct for a single thread but unbounded.

You are wrapping an expensive deterministic pricing calculation. Repeated inputs should avoid recomputation. The current implementation stores every result forever. Production has begun swapping under a broad input distribution.

Your first task is to add a configurable entry bound while preserving expected O(1) lookup and eviction. Do not change `ExpensiveFn` or the public `MemoCache::get(int)` call site. Existing behavior must remain correct for hits and misses.

Start by reading the code and writing down the invariant you want between the hash table and whatever eviction structure you introduce. Run the baseline tests before changing anything.

### Constraints

- keys/results are integers for the exercise; `ExpensiveFn` may be very slow.
- target operations should be O(1) expected time in the initial bounded-cache stage.
- capacity may be as small as 1.
- “correctness before cleverness”: a cache miss may compute, but a hit must return the exact stored result.

### Provenance

This is built directly around Jane Street's **official retired “Memo” interview**, which progresses from unbounded memoization to bounded FIFO and then LRU while discussing complexity: https://blog.janestreet.com/what-a-jane-street-dev-interview-is-like/ . Jane Street's official mock interview emphasizes clear/correct code and practicing in interview-like conditions: https://www.janestreet.com/mock-interview/ . Later stages here go beyond the published retired question into production cache semantics; they are additions, not claimed Jane Street prompts.
