# 05 — SPSC Market-data Ring

**Environment:** C++20 atomics. One producer thread, one consumer thread. Fixed capacity.

A market-data decoder hands parsed updates to a strategy thread through this ring. The current implementation passes single-threaded tests but is not a sound concurrent queue. Fix it for **single producer / single consumer** without adding a mutex.

You must define what `head` and `tail` mean, how full vs empty are distinguished, and which cross-thread reads require acquire/release ordering. Do not begin with `memory_order_seq_cst` and call the problem solved; explain the weakest correct ordering you choose.

### Provenance

Jump candidate reports explicitly include threading and low-level C++ systems knowledge alongside coding: https://www.jointaro.com/interviews/companies/jump-trading/experiences/swe-intern-shanghai-shanghai-february-1-2024-no-offer-positive-d7371742/ . This exact ring is a style synthesis rather than a reported verbatim Jump prompt. Production references for later comparison include https://github.com/cameron314/concurrentqueue and https://github.com/max0x7ba/atomic_queue .
