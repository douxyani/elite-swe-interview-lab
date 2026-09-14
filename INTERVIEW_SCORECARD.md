# Technical Interview Scorecard

Use this after a cold attempt. Score 0–3 on each dimension; do not score speed in isolation.

| Dimension | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| Brief absorption | misses core contract | repeatedly rereads basics | captures contract, misses edge cases | restates constraints/invariants and spots ambiguities unaided |
| Existing-code comprehension | rewrites blindly | partial map, breaks behavior | preserves main invariants | rapidly maps ownership/data flow and predicts failure points |
| Correctness | major bugs | happy path only | handles stated edge cases | actively attacks own solution with adversarial cases |
| Data structures / algorithms | unsuitable | works but wrong asymptotics | appropriate | adapts structure cleanly when requirement changes |
| C++ systems skill (where relevant) | UB/lifetime confusion | manual ownership fragile | RAII/lifetime/concurrency sound | exception safety, memory ordering, layout and performance reasoning precise |
| Business semantics | ignores domain | reacts to explicit examples | models duplicates/failures/time | anticipates idempotency, replay, clocks, backpressure, consistency |
| Testing | none | examples only | boundary + failure tests | characterization/property/stress tests target invariants |
| Complexity communication | cannot justify | big-O only | time + memory | includes constants/contention/I/O/worst-case and invalidating assumptions |
| Design under follow-up | starts over | patches conditionals | local refactor | identifies abstraction boundary that changed and evolves design coherently |
| Debugging | random edits | print-driven only | isolates hypotheses | forms ranked hypotheses, designs discriminating experiments, explains root cause |

A strong attempt is not “finished every stage.” It is one where the code remains understandable and the reasoning improves as the interviewer makes the problem nastier.
