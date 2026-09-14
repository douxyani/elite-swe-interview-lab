# Interviewer follow-ups

## Stage 1 — latency bound vs utilization
No request may wait more than `max_wait_ms`. Explain timer behavior when no new request arrives.

## Stage 2 — token budget + bucketing
GPU memory constrains total tokens, and padding to the longest request wastes compute. Batch by compatible lengths without starving outliers.

## Stage 3 — multiple GPUs
GPUs have independent queues/capacity. Route batches while avoiding a central hot lock. A request may require a particular model version loaded on only some GPUs.

## Stage 4 — continuous batching
The runtime can admit new decode requests between token steps. Redesign around prefill/decode state rather than fixed whole-request batches.

## Stage 5 — failure / fairness
A GPU can die after work started. Retry without duplicating externally visible streamed tokens. Add tenant weights and prove a high-volume tenant cannot starve another indefinitely.
