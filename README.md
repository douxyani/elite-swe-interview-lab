# Elite SWE Interview Lab

A deliberately hard, brownfield-heavy interview practice repository for elite quantitative trading, big-tech, and AI-infrastructure software engineering interviews.

This is **not** a collection of copied interview questions or a generic LeetCode plan. Each folder is an independently authored simulation built from public evidence about real interview formats/questions and from public production codebases that exercise the same engineering muscles. The goal is to force the transition from “competitive programmer” to “engineer who can absorb an unfamiliar system, discover invariants, ask business-relevant questions, and make correct changes under pressure.”

## How to use it

Pick a folder without reading `INTERVIEWER.md`. Read only its `README.md` and the starter code. Treat the existing code as code you inherited five minutes ago. Run the baseline tests, make a short map of the system from memory, then begin. Only open `INTERVIEWER.md` when you want the next follow-up. The follow-ups are intentionally requirement-breaking: a data structure that was fine at stage 1 should often become inadequate at stage 2.

For C++ folders, use C++20. Most are dependency-free and build with CMake. Python folders use only the standard library. `tools/brief_recall.py` can be used to train one-shot brief absorption before coding.

## Problem index

| # | Folder | Core signal | Evidence level |
|---|---|---|---|
| 01 | `adaptive_memo_cache` | cache design, O(1) invariants, concurrency | **A**: official Jane Street retired interview |
| 02 | `orderbook_reconciler` | trading-domain state machine, replay, reconciliation | **B**: candidate-reported Jane Street order-book rounds + public LOB code |
| 03 | `batched_network_producer` | batching, time bounds, concurrency, shutdown | **B**: detailed historical Citadel candidate report |
| 04 | `small_vector` | object lifetime, RAII, move/copy, inline storage | **B**: Jump candidate reports; OSS analogues |
| 05 | `spsc_market_data_ring` | atomics, memory ordering, cache layout | **B/C**: Jump low-level interview reports + OSS queues |
| 06 | `versioned_kv` | progressive coding, temporal data, persistence | **B/C**: reported OpenAI-style question + LevelDB |
| 07 | `durable_work_queue` | leases, retries, idempotency, crash semantics | **C**: reported AI-infra style + Celery semantics |
| 08 | `billion_integer_aggregator` | I/O, overflow, parsing, parallel boundaries | **B**: Marshall Wace candidate report |
| 09 | `legacy_risk_engine_refactor` | brownfield refactor + changing requirements | **A**: official G-Research interview description |
| 10 | `gpu_batch_scheduler` | latency/utilization tradeoffs, fairness, failures | **B**: Anthropic candidate reports + vLLM |
| 11 | `gpu_credit_ledger` | temporal credits, idempotent accounting | **C**: reported OpenAI-style prompt + TigerBeetle concepts |
| 12 | `streaming_trade_canonicalizer` | ordering, dedupe, bounded lateness, external memory | **B/C**: Jane Street candidate report + production sorting ideas |

### Evidence legend

- **A — first-party:** the firm itself describes the exercise or interview behavior.
- **B — first-hand / direct candidate report:** a public candidate account gives a concrete prompt or round description. This is useful evidence, not a guarantee that the firm still asks it.
- **C — synthesis:** multiple weaker reports or role signals plus a real open-source system. It is designed to train the same failure modes, not represented as a verbatim question.

No task claims that a currently active confidential interview question will repeat. Interview processes change.

## What makes these harder than LeetCode

The principal difficulty is **requirement evolution**. A clean `unordered_map` answer becomes a bounded cache, then an LRU, then a concurrent single-flight cache. A FIFO queue becomes leases and crash recovery. A batch sorter becomes an event-time stream with corrections. You need to preserve invariants while the abstraction shifts underneath you.

The second difficulty is **existing code**. Some starters are intentionally awkward, coupled, or subtly unsafe. Do not rewrite everything unless you can justify it. In several elite-firm interviews, understanding and improving an existing codebase is itself the test.

The third difficulty is **business semantics**: duplicate exchange messages, partial fills, stale snapshots, idempotent retries, GPU starvation, credit expiry, and p99 latency matter as much as asymptotic complexity.

## Extra material

- `LEETCODE_PLUS.md` — a curated list of algorithm/data-structure problems with the production twist you should add after solving the stock problem.
- `JANE_STREET_PUZZLES.md` — selected official Jane Street puzzles for creative problem-solving, explicitly separate from Jane Street SWE interview prep.
- `COGNITIVE_DRILLS.md` — high-transfer drills embedded in realistic engineering tasks, plus why generic “brain training” is a poor bet.
- `SOURCE_MATRIX.md` — provenance for every simulation.
- `PUSH_TO_GITHUB.md` — how to put this folder into a blank GitHub repository.
