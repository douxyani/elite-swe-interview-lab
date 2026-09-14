from dataclasses import dataclass
from collections import deque
@dataclass(frozen=True)
class Request:
    id: str; arrival_ms: int; input_tokens: int; max_output_tokens: int; priority: int=0
class Scheduler:
    def __init__(self, max_batch=100, max_wait_ms=20): self.max_batch=max_batch; self.max_wait_ms=max_wait_ms; self.waiting=deque()
    def submit(self, r: Request): self.waiting.append(r)
    def schedule(self, now_ms: int):
        # Brownfield: latency bound ignored. Returns either full batch or nothing.
        if len(self.waiting) < self.max_batch: return []
        return [self.waiting.popleft() for _ in range(self.max_batch)]
