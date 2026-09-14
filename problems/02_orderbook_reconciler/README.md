# 02 — Order-book Reconciler

**Environment:** C++20. You inherit a tiny market-data book that understands ADD and CANCEL. The feed is append-only text for the exercise.

A trading process consumes exchange updates and keeps a local view of best bid/offer. A second process periodically receives exchange snapshots. Operations has seen rare divergence between the local book and the exchange after reconnects.

First, understand the starter's ownership and indexing. Add `TRADE order_id qty` semantics with partial fills; quantity can never become negative and a fully filled order disappears. Preserve price-time ordering within a level. Then make the code capable of detecting impossible messages instead of silently corrupting state.

### Example

```
ADD 10 B 10025 7
ADD 11 B 10025 4
TRADE 10 5
CANCEL 11
```

After this sequence, order 10 has quantity 2 at bid 10025.

### Provenance

A Dec-2025 Jane Street candidate report describes two onsite rounds centered on order books, including what messages need to pass between a trading system and an exchange: https://prachub.com/interview-experiences/jane-street-software-engineer-interview-experience-onsite-system-design-on-orderbooks-rejected-before-the-coding-round . This task is a new simulation, not a transcription. The brownfield architecture is informed by public C++ limit-order-book implementations such as https://github.com/brprojects/Limit-Order-Book, whose README documents price priority/FIFO, IDs, price levels, cancel/modify, and testing.
