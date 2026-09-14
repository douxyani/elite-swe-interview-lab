# 12 — Streaming Trade Canonicalizer

**Environment:** C++20.

A downstream risk system needs a deterministic canonical sequence of trade executions. Batch records have `(event_ts, symbol, trade_id, qty, price)`. For the first stage, sort by `(event_ts, symbol, trade_id)` and deduplicate identical `trade_id`s. If two records reuse an ID with different economics, report a conflict rather than silently picking one.

The existing implementation uses `std::sort` but has no duplicate policy. Make the policy explicit and test it.

### Provenance

A Dec-2025 candidate report describes a Jane Street coding round as a trading-system “sort trade” problem and says the setup felt closer to implementing a trading-system feature than a generic algorithm question: https://prachub.com/interview-experiences/jane-street-software-engineer-interview-experience-onsite-system-design-on-orderbooks-rejected-before-the-coding-round . Exact details in public aggregations vary, so only the broad canonicalization setup is treated as evidence; later streaming stages are new.

For production-scale sorting/storage ideas, inspect DuckDB after attempting the external-memory stage: https://github.com/duckdb/duckdb .
