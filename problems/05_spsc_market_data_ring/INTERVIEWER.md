# Interviewer follow-ups

## Stage 1 — correct SPSC memory ordering
Make `try_push` / `try_pop` race-free for arbitrary trivially copyable payloads. Draw the happens-before relation that protects payload bytes.

## Stage 2 — non-trivial payload
Support movable non-trivial T using raw slots and explicit lifetime. The producer constructs, consumer destroys. Handle destruction with items still queued.

## Stage 3 — false sharing
Separate producer-owned and consumer-owned hot indices onto distinct cache lines. Measure, don't merely assert, improvement. Explain why padding can hurt footprint.

## Stage 4 — batch API
Add `try_push_bulk` / `try_pop_bulk` while amortizing atomic traffic and preserving wraparound correctness.

## Stage 5 — requirement attack
The upstream suddenly has two producers. Explain exactly why SPSC breaks and choose: MPSC queue, one queue per producer + merge, or external serialization. Discuss sequence ordering if messages represent one exchange stream.
