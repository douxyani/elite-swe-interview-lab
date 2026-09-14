# 07 — Durable Work Queue

**Environment:** Python 3. The starter is an in-memory FIFO with destructive `pop`.

Turn it into a queue suitable for jobs that may outlive a worker process. Workers should **reserve** a job for a lease duration, then `ack` it on success or `nack` it on recoverable failure. If a worker dies, the lease eventually expires and the job becomes available again.

Begin with a deterministic injected clock so tests do not sleep. Define the state machine before writing code.

### Provenance

This is a synthesis of practical infrastructure interview patterns, not presented as a verbatim firm prompt. It is included because AI-lab SWE screens increasingly use progressive, code-first state machines and because failure semantics reveal engineering judgment quickly. As a production reference, Celery documents acknowledgement, redelivery after worker failure, idempotency, retry, and backoff: https://github.com/celery/celery/blob/main/docs/userguide/tasks.rst . OpenAI's official guide confirms pair coding/take-home/technical-test formats vary by team: https://openai.com/interview-guide/ .
