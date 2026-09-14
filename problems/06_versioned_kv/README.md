# 06 — Versioned Key-Value Store

**Environment:** Python 3 standard library. Existing code supports latest-value `set/get/delete` only.

Add historical reads: `get_at(key, timestamp)` returns the value whose version has the largest timestamp `<= timestamp`, or `None` if no value existed. Writes can arrive **out of timestamp order** and a delete must create a tombstone rather than erase history.

Target up to 1,000,000 operations. Explain your insertion/query complexity and why the representation still works if one key receives most writes.

### Provenance

OpenAI's official interview guide says team-specific assessments may include pair coding, take-home projects, and technical tests, and that “high potential” includes quickly ramping in a new domain: https://openai.com/interview-guide/ . Versioned key-value stores are repeatedly reported in public OpenAI interview-prep/candidate aggregations, e.g. https://igotanoffer.com/en/advice/openai-software-engineer-interview and https://prachub.com/coding-questions/implement-kv-store-and-plan-type-conversions . Those are secondary sources, so this is not labeled an official OpenAI question.

Storage-system reference: LevelDB https://github.com/google/leveldb .
