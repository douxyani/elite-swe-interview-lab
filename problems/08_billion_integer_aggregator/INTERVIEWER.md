# Interviewer follow-ups

## Stage 1 — robust streaming parser
Avoid per-token heap allocation. Detect malformed input and integer overflow. Explain whether partial output is allowed after an error.

## Stage 2 — wider/exact sum
Input values are signed 64-bit and the mathematical total may exceed 64-bit. Choose `__int128`, checked big integer, or an explicit overflow contract and justify portability.

## Stage 3 — parallel file processing
Use multiple threads. Partition byte ranges without losing or double-counting a token crossing a boundary. Avoid every thread contending on one accumulator.

## Stage 4 — mmap vs read
Implement or design both. Discuss page faults, readahead, NUMA, file-system cache, and why mmap is not automatically faster.

## Stage 5 — streaming statistics
In one pass also produce count/min/max and a deterministic checksum. Then accept gzip input: which bottleneck moves and how does the architecture change?
