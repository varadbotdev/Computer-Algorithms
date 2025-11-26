# arbitrage.sage
# Detect currency arbitrage using SageMath

# Step 1: Define currencies and exchange rates
# rates[i][j] = how much of currency j you get for 1 unit of currency i
currencies = ['USD', 'EUR', 'GBP']
n = len(currencies)

# Example rates (may or may not contain arbitrage)
rate_matrix = [
    [1.0,   0.9,   0.8],   # USD
    [1.1,   1.0,   0.9],   # EUR
    [1.2,   1.1,   1.0]    # GBP
]

# Step 2: Build a directed graph with -log(rate) as edge weights
G = DiGraph()

# Add vertices
for cur in currencies:
    G.add_vertex(cur)

# Add weighted edges
for i in range(n):
    for j in range(n):
        if i != j and rate_matrix[i][j] > 0:
            weight = -log(rate_matrix[i][j])
            G.add_edge(currencies[i], currencies[j], weight)

# Step 3: Use Bellman-Ford (via shortest_path_lengths) to detect negative cycle
# SageMath raises an error if a negative cycle is found
try:
    dist = G.shortest_path_lengths(currencies[0], by_weight=True)
    print("No arbitrage opportunity detected.")
except ValueError as e:
    if "negative cycle" in str(e).lower():
        print("Arbitrage opportunity detected!")
    else:
        print("Error:", e)