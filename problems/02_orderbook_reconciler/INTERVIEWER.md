# Interviewer follow-ups

## Stage 1 — partial fills and invariants
Implement TRADE and explicit rejection for duplicate ADD, unknown CANCEL/TRADE, zero/negative qty, and overfill. State whether rejection mutates anything.

## Stage 2 — sequence numbers
Every feed message receives a strictly increasing `seq`. Duplicates can be replayed after reconnect. Ignore exact duplicates, detect gaps, and do not apply seq N+2 before N+1.

## Stage 3 — bounded reorder buffer
Packets may arrive out of order within a small window. Buffer and drain contiguous sequence numbers. Set a hard memory bound. What happens when the missing message never comes?

## Stage 4 — snapshots + reconciliation
A snapshot contains `(seq, all live orders)`. Install it atomically relative to incremental processing, then replay buffered events newer than the snapshot. Produce a human-readable reconciliation diff without quadratic work.

## Stage 5 — business twist
Add CANCEL/REPLACE where increasing quantity loses time priority but decreasing quantity keeps it. Explain how your data structures encode that rule and what changes if one symbol has millions of orders.
