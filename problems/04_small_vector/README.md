# 04 — `SmallVector<T, N>`

**Environment:** C++20. No external library. The starter supports only trivially behaved `int`-like types safely.

Implement a vector-like container that stores its first `N` elements in storage owned directly by the object and spills to a contiguous heap allocation when it grows beyond `N`. You are not allowed to default-construct `N` `T` objects merely to reserve space; object lifetime must begin only for live elements.

Start with `push_back`, `size`, `capacity`, indexing, destruction, and growth. State the strong/basic exception guarantee you can provide for each operation.

### Provenance

A 2024 Jump Trading SWE intern report describes C++ questions covering smart pointers, `std::forward`, RAII, threading, TCP/UDP, heap vs stack, plus a coding task to implement a vector with inline storage for small N and heap storage beyond it: https://www.jointaro.com/interviews/companies/jump-trading/experiences/swe-intern-shanghai-shanghai-february-1-2024-no-offer-positive-d7371742/ . A Glassdoor result independently surfaces the same prompt: https://www.glassdoor.co.uk/Interview/Some-common-knowledges-about-cpp-such-as-smart-pointer-std-forward-RAII-And-some-basic-computer-science-knowledge-for-QTN_6930829.htm .

Production analogues: Abseil `InlinedVector` https://github.com/abseil/abseil-cpp/blob/master/absl/container/inlined_vector.h and LLVM `SmallVector` https://github.com/llvm/llvm-project/blob/main/llvm/include/llvm/ADT/SmallVector.h . Do not copy them; read them only after attempting the task if you want a code-review exercise.
