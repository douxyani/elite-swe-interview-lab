# Cognitive Drills With Engineering Transfer

The target is not a vague increase in “brain capacity.” A major meta-analysis of working-memory training found near-transfer to similar trained tasks but no convincing far transfer to intelligence or broad real-world abilities: https://pmc.ncbi.nlm.nih.gov/articles/PMC4968033/ . By contrast, spacing and retrieval practice have strong evidence as learning strategies: https://doi.org/10.1038/s44159-022-00089-1 .

So the drills here train the exact cognitive operations the interviews demand.

## One-pass brief recall

Use `python3 tools/brief_recall.py problems/03_batched_network_producer/README.md 75`. Read for the allotted time, then the screen clears. Before reopening anything, write down: the API, five hard constraints, three ambiguous points you would ask about, and two invariants your implementation must preserve. Score against the brief. This directly trains active listening/absorption rather than a generic memory game.

## Cold codebase map

Open one unfamiliar starter for 12 minutes. Close it. On paper, reconstruct the modules, data flow, ownership relationships, and the three functions most likely to contain correctness bugs. Reopen and mark false memories. Repeat on a different folder rather than memorizing the same tree.

## Requirement relay

Have a friend read one section of `INTERVIEWER.md` aloud **once**. You may only take five terse notes. Restate the requirement, identify what in the current design breaks, then implement. This is deliberately close to the “interviewer adds a twist verbally” failure mode.

## Invariant compression

After solving a stage, close the code and state its correctness in no more than five invariants. Examples: “Every live order ID appears in exactly one price level”; “head is the next unread slot; tail is the next unwritten slot”; “an ACKed job can never become visible again.” If you cannot compress the system, you probably do not yet own it mentally.

## Next-day retrieval, not rereading

Before reopening a completed task later, reconstruct the design and the hardest bug from memory, then compare. The purpose is retrieval effort; passive rereading feels fluent while hiding weak recall. Spacing/retrieval research is the reason this repository favors re-derivation and explanation over “brain game” scores.

## Curiosity / initiative drill

Before touching code, generate ten questions from the brief. At least four must be about production semantics rather than syntax: clocks, duplicate input, crash points, ownership, backpressure, consistency, overflow, adversarial input, observability, or rollout. Score yourself on whether later stages reveal an issue you had already anticipated.
