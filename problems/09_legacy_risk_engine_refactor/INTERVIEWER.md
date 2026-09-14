# Interviewer follow-ups

## Stage 1 — refactor for testability
Characterize old behavior, then separate parsing, FX lookup, and risk policy. No global mutable test fixtures.

## Stage 2 — desk limits + currencies
Trades carry desk and currency. Convert notional at an injected FX snapshot, then apply desk-specific limit. Define missing FX behavior.

## Stage 3 — incremental positions
Decision now depends on current per-desk/per-symbol exposure, not just one trade. Accept/commit must be atomic with respect to the exposure state.

## Stage 4 — concurrent readers
Risk dashboards continuously read snapshots while trading threads update positions. Provide consistent snapshots without one giant stop-the-world lock if possible.

## Stage 5 — changing requirement
Limits can change during the day with an effective timestamp and can be applied prospectively or retroactively depending on rule type. Revisit the domain model rather than adding more `if` statements.
