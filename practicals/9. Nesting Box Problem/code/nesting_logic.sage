# nesting_logic.sage
# Computes the longest nesting sequence of boxes using DP

# Define boxes as (l, w, h)
boxes = [
    (4, 6, 7),
    (1, 2, 3),
    (4, 5, 6),
    (10, 12, 32),
    (2, 3, 4)
]

# Step 1: Normalize each box (sort dimensions)
normalized = [tuple(sorted(b)) for b in boxes]
n = len(normalized)

# Step 2: Sort all boxes lexicographically
normalized.sort()
print("Normalized & sorted boxes:", normalized)

# Step 3: DP to find longest chain
dp = [1] * n
parent = [-1] * n

for i in range(n):
    for j in range(i):
        # Check if box j fits in box i (strictly smaller in all dims)
        if all(normalized[j][k] < normalized[i][k] for k in range(3)):
            if dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                parent[i] = j

# Step 4: Find the index with max dp
max_len = max(dp)
idx = dp.index(max_len)

# Step 5: Reconstruct the sequence
sequence = []
while idx != -1:
    sequence.append(normalized[idx])
    idx = parent[idx]
sequence.reverse()

print("Maximum nesting depth:", max_len)
print("Longest nesting sequence:", sequence)