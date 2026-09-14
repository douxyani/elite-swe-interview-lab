# 09 — Legacy Risk Engine Refactor

**Environment:** C++20. This is intentionally not a blank-slate algorithm problem.

The starter parses a CSV-ish trade string and computes a crude USD notional limit using globals. A new requirement arrives: different desks have different limits, FX rates are injectable, and the decision logic must be unit-testable without mutating process-global state.

**Do not add the feature immediately.** First add characterization tests for existing behavior. Then refactor just enough to create seams for parsing, market data, and policy. Preserve behavior while refactoring; make the feature change afterward.

### Provenance

G-Research's official Quant Platform interview article explicitly describes a **Refactoring Test**: a small existing codebase in a full IDE, a feature request that is hard to test under the current design, and assessment of how the candidate refactors for testability and improves the code: https://www.gresearch.com/news/what-to-expect-from-a-quant-platform-software-engineering-interview/ . Its updated article also describes a design round with changing requirements and hard algorithm questions: https://www.gresearch.com/news/what-to-expect-from-a-quant-platform-software-engineering-interview-updated/ .

Domain references for after the attempt: QuantLib https://github.com/lballabio/QuantLib and QuickFIX https://github.com/quickfix/quickfix .
