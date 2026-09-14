# 11 — GPU Credit Ledger

**Environment:** Python 3. Treat credits as integer GPU-seconds; floating point is forbidden.

Organizations receive grants with `(amount, valid_from, valid_until)`. A usage event at time `t` consumes available credits that are valid at `t`; expired grants cannot be spent. Implement grants, balance-at-time, and spend. Your implementation must be deterministic about which grants are consumed first.

The starter keeps a single balance and therefore cannot model validity windows.

### Provenance

This is deliberately marked **synthesis**. Public OpenAI interview-prep reports have described resource-credit/ledger-like progressive exercises, but OpenAI's first-party material only commits to team-varying skills assessments, not this specific prompt: https://openai.com/interview-guide/ . The task is retained because temporal accounting + retries creates exactly the business-logic twists that separate a simple data-structure answer from robust systems reasoning.

Production accounting/idempotency reference: TigerBeetle https://github.com/tigerbeetle/tigerbeetle ; its client documentation discusses retry-proof transfers and end-to-end idempotency.
