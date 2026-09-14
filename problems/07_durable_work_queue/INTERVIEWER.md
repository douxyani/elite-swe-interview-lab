# Interviewer follow-ups

## Stage 1 — reserve/ack/nack
A reservation returns `(job, lease_token)`. Only the current token can ack/nack. Expired tokens are rejected.

## Stage 2 — retries + dead-letter queue
Recoverable failures use exponential backoff with max attempts; permanent failures go directly to DLQ. Clarify whether attempt count increments on reserve or failure.

## Stage 3 — idempotency
A client may retry `enqueue` after an ambiguous timeout. Add a client-supplied idempotency key with bounded retention.

## Stage 4 — crash recovery
Persist transitions to an append-only WAL. Recover queue state after process restart. A crash can occur between any two writes. Avoid resurrecting ACKed jobs.

## Stage 5 — fairness / scheduling
Add priority and scheduled-at time without starving old low-priority jobs. Then discuss sharding across machines while preserving per-key ordering for selected job families.
