# Interviewer follow-ups

## Stage 1 — batch conflict semantics
Deduplicate exact replays; flag ID reuse with changed qty/price/symbol. Keep deterministic output independent of input order.

## Stage 2 — online bounded lateness
Records stream forever and can arrive up to `L` milliseconds late. Emit final canonical records as soon as a watermark proves no earlier event can arrive. Bound memory in terms of traffic rate and L.

## Stage 3 — corrections/cancels
A correction references an earlier trade ID and can itself arrive late. Decide whether downstream receives an append-only correction event or revised history. State implications for risk/PnL consumers.

## Stage 4 — exactly-once across restart
Persist progress. On crash/restart, replaying the input must not duplicate externally visible output. Coordinate checkpoint and sink semantics.

## Stage 5 — exceeds RAM
A historical backfill contains hundreds of GB. Implement/design external sort with run generation + k-way merge, preserving dedupe/conflict detection without loading all IDs into RAM. Discuss partitioning by symbol vs global ordering.
