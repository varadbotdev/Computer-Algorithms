# Critical Thinking Questions

After implementing arbitrage detection, consider:

1. Why do we use **-log(exchange_rate)** as edge weights instead of the raw rate? What would happen if we used positive logs or raw rates?

2. Bellman-Ford can detect *that* an arbitrage cycle exists—but not necessarily *which* currencies form it. How could you modify the algorithm to **recover the actual sequence** of profitable trades?

3. Suppose transaction fees are 0.1% per trade. How would you incorporate this into the graph model? or does arbitrage works only when the transaction fees are NULL.

