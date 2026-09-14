# Interviewer follow-ups

## Stage 1 — non-trivial T
Pass tests with a type that counts constructors/destructors and is not default-constructible.

## Stage 2 — Rule of Five
Copy/move construct and assign. A move from inline storage cannot simply steal a pointer. A move from heap storage often can. Define moved-from invariants.

## Stage 3 — exception safety
A type throws on the kth copy/move. `reserve` must not leak or double-destroy. Explain `std::move_if_noexcept`-style reasoning.

## Stage 4 — perfect forwarding
Add `emplace_back(Args&&...)`. Explain why `std::forward` is correct here and what goes wrong if every argument is unconditionally moved.

## Stage 5 — layout/performance
Discuss object size, alignment, growth factor, cache locality, iterator invalidation, `N=0`, over-aligned T, and whether spilling should ever move back inline after erase.
