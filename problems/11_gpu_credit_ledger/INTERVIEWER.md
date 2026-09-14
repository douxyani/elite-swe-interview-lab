# Interviewer follow-ups

## Stage 1 — validity windows
Spend earliest-expiring eligible credits first. What is the complexity with 1M grants and many point-in-time balance queries?

## Stage 2 — reserve / commit / release
Jobs reserve estimated GPU-seconds before running and commit actual usage later. Reservation must prevent double-spend but unused amount is released.

## Stage 3 — idempotency
Every mutation carries a unique operation ID. Retrying the same operation returns the original result; reusing an ID with different arguments is rejected.

## Stage 4 — hierarchy
Credits can be granted at org, project, or user scope with fallback rules and per-project caps. Make the policy explicit rather than burying it in iteration order.

## Stage 5 — event sourcing
Persist an append-only ledger, build snapshots, and replay after crash. Define the invariant that allows an auditor to recompute every historical balance exactly.
