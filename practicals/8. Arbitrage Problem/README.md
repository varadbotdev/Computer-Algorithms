# Currency Arbitrage Detection

## What is the Currency Arbitrage Problem?

Currency arbitrage occurs when a sequence of currency exchanges results in a net profit—starting and ending with the same currency, but ending up with more than you began with. For example:  
USD → EUR → GBP → USD, and you end with **more USD** than you started.

This is possible due to slight inconsistencies in real-world exchange rates across markets.

## What does this program do?

Given a set of currencies and exchange rates, the program:
- Models currencies as **nodes** and exchange rates as **edges** in a graph  
- Transforms the problem into detecting a **negative-weight cycle** (using logarithms)  
- Uses the **Bellman-Ford algorithm** to find such a cycle  
- Reports whether arbitrage is possible

## How does it work?

1. **Graph Construction**:  
   - Each currency is a vertex.  
   - Each exchange rate \( r \) from currency A to B becomes a directed edge with weight \( -\log(r) \).

2. **Why log?**  
So using the following mathematical equations
a * b * c > 1
=> log(a * b * c) > log(1)
=> loga + logb + logc > 0, since log1 = 0
now the solution reduces to, if the logarithm of the multiplication of the exchange rates of certain currencies that form a cycle is greater than ZERO, then we have an arbitrage.

3. **Algorithm**:  
   - Run Bellman-Ford from a source node.  
   - If it can still relax edges on the \( V \)-th iteration, a negative cycle exists → **arbitrage is possible**.

This approach turns a financial insight into a classic graph problem.