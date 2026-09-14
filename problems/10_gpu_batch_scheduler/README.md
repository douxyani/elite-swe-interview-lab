# 10 — GPU Batch Scheduler

**Environment:** Python 3 simulation; no ML framework required.

Requests arrive with `(id, arrival_ms, input_tokens, max_output_tokens, priority)`. One GPU can execute a batch of up to 100 requests, but batch runtime is approximately dominated by the longest sequence in the batch. Users are synchronous: queueing latency matters.

The starter greedily emits a batch only when it reaches 100. Design `schedule(now_ms)` so low traffic does not wait forever while high traffic still achieves good utilization. Produce deterministic tests using simulated time.

### Provenance

Anthropic's official careers page says technical roles use live-coding tools such as Colab and CodeSignal: https://www.anthropic.com/careers . A May-2025 Staff Infrastructure candidate account reports a system-design question to batch many LLM queries onto GPUs with a batch size up to 100, then asks how to decide when to flush and which GPU has capacity: https://www.tryexponent.com/courses/ai-company-interview-experiences/anthropic-infra-swe-may-2025 . This simulation adds implementation detail and later requirements.

Production reference: vLLM scheduler https://github.com/vllm-project/vllm/blob/main/vllm/v1/core/sched/scheduler.py .
