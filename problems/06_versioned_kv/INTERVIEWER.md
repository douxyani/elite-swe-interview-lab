# Interviewer follow-ups

## Stage 1 — out-of-order history + tombstones
Duplicate `(key,timestamp)` overwrites that exact version. Delete at t means `get_at` after t returns None until a later set.

## Stage 2 — range scan
`history(key, start, end)` returns versions in timestamp order. Avoid sorting the whole history per query.

## Stage 3 — WAL + recovery
Before a mutation becomes visible, append a length-delimited/checksummed record to a write-ahead log. Recover after a torn final record without accepting silent corruption in the middle.

## Stage 4 — snapshots + compaction
Create a snapshot at a logical sequence point and compact versions older than a retention horizon without changing any still-supported historical read.

## Stage 5 — concurrency
Many readers, fewer writers. Choose lock granularity and define whether `get_at` is linearizable, snapshot-consistent, or merely race-free. Benchmark a hot key.
