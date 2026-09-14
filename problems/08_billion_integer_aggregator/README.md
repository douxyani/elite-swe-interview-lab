# 08 — Billion Integer Aggregator

**Environment:** C++20, Linux-friendly but first stage should be portable.

You are given a text file containing signed decimal integers separated by whitespace. It may contain **one billion numbers** and be much larger than RAM. Compute an exact sum or report overflow under the stated accumulator policy. The starter uses formatted `operator>>` into `long long`.

First improve correctness and throughput without assuming the whole file fits in memory. Specify accepted syntax (leading sign, whitespace, malformed token), accumulator width, and error reporting. Benchmark with generated data before reaching for concurrency.

### Provenance

A Marshall Wace London SWE internship candidate report (Nov 2025) says the last round included low-level systems topics such as threads, memory and number types, and asks: “How would you efficiently find the sum of a file that had a billion numbers”: https://www.glassdoor.com/Interview/Marshall-Wace-Interview-Questions-E269459.htm?filter.jobTitleExact=Software+Engineer%28Internship%29 .

For real optimized parsing code after your own attempt, inspect `scnlib` (including integer parsing and benchmarks against streams/from_chars): https://github.com/eliaskosunen/scnlib . `fast_float` is also useful for studying `from_chars`-style parsing machinery: https://github.com/fastfloat/fast_float .
