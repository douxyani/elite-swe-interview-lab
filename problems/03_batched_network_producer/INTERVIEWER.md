# Interviewer follow-ups

## Stage 1 — timer-driven flush
Guarantee the oldest accepted message is handed to `Endpoint::send_batch` by its deadline even if traffic stops. Avoid wall-clock jumps.

## Stage 2 — thread safety
Multiple threads call `send_message`. No duplicates, loss, data races, or a network call while unnecessarily holding the producer's internal lock. Explain the race between count-triggered and timer-triggered flush.

## Stage 3 — bounded backpressure
`Endpoint` can stall for seconds. Total queued + in-flight memory must remain bounded. Choose block/reject/drop policy explicitly and make shutdown semantics testable.

## Stage 4 — retry and idempotency
Endpoint can return an ambiguous timeout: the remote side may have accepted the batch. Give each message an ID; add retry with backoff while preventing logical double-application downstream. Separate transport retry from application idempotency.

## Stage 5 — process boundary design
The original candidate report mentions sharing beyond one caller context. Discuss what changes if producers are truly in multiple OS processes: shared memory vs broker process vs durable log; ownership after a process dies; clock and lock choices.
