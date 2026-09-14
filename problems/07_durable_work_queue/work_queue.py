from collections import deque

class WorkQueue:
    def __init__(self): self._q=deque(); self._next=1
    def enqueue(self, payload):
        jid=self._next; self._next+=1; self._q.append((jid,payload)); return jid
    def pop(self):
        return self._q.popleft() if self._q else None
    def reserve(self, now, lease_seconds):
        raise NotImplementedError
    def ack(self, lease_token):
        raise NotImplementedError
