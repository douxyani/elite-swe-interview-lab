# LeetCode+, not just LeetCode

Solve the stock problem cleanly first. Then add the twist in the right-hand column **without starting over**. That second part is the interview-relevant exercise.

| LeetCode | Base problem | Production / business follow-up |
|---|---|---|
| 146 | LRU Cache | TTL + weighted capacity + resize + single-flight concurrent miss |
| 460 | LFU Cache | aging/decay so ancient hot keys do not live forever; concurrent snapshots |
| 981 | Time Based Key-Value Store | out-of-order timestamps, tombstones, WAL, compaction |
| 1146 | Snapshot Array | many sparse keys, snapshot retention and compaction |
| 432 | All O`one Data Structure | atomic multi-key increment and consistent top-k snapshot |
| 1206 | Design Skiplist | lock-free/read-mostly discussion; memory reclamation |
| 715 | Range Module | deletes, max overlap, persistence, event-time corrections |
| 352 | Data Stream as Disjoint Intervals | out-of-order event ingestion + bounded memory |
| 2276 | Count Integers in Intervals | deletion + kth covered element + concurrent queries |
| 729/731/732 | My Calendar I/II/III | cancellations, multi-resource booking, fairness, recurring reservations |
| 2034 | Stock Price Fluctuation | multi-symbol stream, corrections, VWAP and stale-event policy |
| 1801 | Number of Orders in Backlog | price-time priority, order IDs, cancel/replace, partial fills |
| 295 | Find Median from Data Stream | sliding window + deletion + sharded ingestion |
| 480 | Sliding Window Median | event-time windows and late arrivals |
| 1825 | Finding MK Average | correction of previously published values |
| 239 | Sliding Window Maximum | millions of streams; memory budget and backpressure |
| 126 | Word Ladder II | very large dictionary, multi-query preprocessing, shortest paths with explanations |
| 332 | Reconstruct Itinerary | duplicate events, deterministic replay after partial failure |
| 588 | Design In-Memory File System | symlinks, normalization, snapshot/restore, permissions |
| 2296 | Design a Text Editor | code folding, incremental edits, cursor snapshots |
| 631 | Design Excel Sum Formula | dependency graph, invalidation, cycles, incremental recompute |
| 355 | Design Twitter | fanout strategy, hot users, bounded queues, idempotent delivery |
| 1242 | Web Crawler Multithreaded | per-host rate limits, retries, dedupe across workers |
| 1188 | Design Bounded Blocking Queue | shutdown semantics, timeouts, fairness, batch push/pop |
| 1226 | Dining Philosophers | starvation freedom, cancellation and bounded wait |
| 1117 | Building H2O | abort/restart and reusable barriers |
| 1279 | Traffic Light Controlled Intersection | multiple lanes, priority classes, starvation avoidance |
| 2502 | Design Memory Allocator | alignment, fragmentation, coalescing, thread-local caches |
| 2642 | Design Graph With Shortest Path Calculator | dynamic edge updates, cache invalidation, negative-edge policy |
| 381 | Insert Delete GetRandom O(1) - Duplicates | weighted random sampling + deterministic replay |
| 895 | Maximum Frequency Stack | snapshot/restore + bounded memory |
| 1172 | Dinner Plate Stacks | concurrent producers/consumers + hole reclamation |
| 1235 | Maximum Profit in Job Scheduling | machines with capacities, preemption, online arrivals |
| 502 | IPO | online project arrivals, risk budget, dependency constraints |
| 218 | The Skyline Problem | streaming inserts/deletes; query current envelope |
| 2392 | Build a Matrix With Conditions | incremental constraints and explain cycle provenance |
| 212 | Word Search II | mutable dictionary + memory locality + cancellation |
| 224 | Basic Calculator | streaming parser, overflow, diagnostics, arbitrary precision policy |
| 76 | Minimum Window Substring | byte vs Unicode semantics; streaming chunks |
| 297 | Serialize/Deserialize Binary Tree | versioned format, corruption detection, backward compatibility |

## A harder rule

For every solution, be able to answer, without looking at the code: **invariants, ownership/lifetime, asymptotic costs, worst-case memory, failure behavior, and the first requirement change that would invalidate your design.** That is the gap these simulations target.
