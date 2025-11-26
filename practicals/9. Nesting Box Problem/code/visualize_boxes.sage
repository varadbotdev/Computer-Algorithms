# visualize_boxes.sage
# Visualizes the nesting DAG and highlights the longest path

boxes = [
    (4, 6, 7),
    (1, 2, 3),
    (4, 5, 6),
    (10, 12, 32),
    (2, 3, 4)
]

# Normalize and sort
norm_boxes = [tuple(sorted(b)) for b in boxes]
norm_boxes.sort()
n = len(norm_boxes)

# Build DAG: edge i -> j if box i fits in box j
G = DiGraph()
for i in range(n):
    G.add_vertex(i, label=str(norm_boxes[i]))

for i in range(n):
    for j in range(n):
        if i != j and all(norm_boxes[i][k] < norm_boxes[j][k] for k in range(3)):
            G.add_edge(i, j)

# Recompute DP to get longest path (same as logic file)
dp = [1] * n
parent = [-1] * n
for i in range(n):
    for j in range(i):
        if all(norm_boxes[j][k] < norm_boxes[i][k] for k in range(3)):
            if dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                parent[i] = j

max_len = max(dp)
end_idx = dp.index(max_len)

# Reconstruct longest path
path_vertices = []
cur = end_idx
while cur != -1:
    path_vertices.append(cur)
    cur = parent[cur]
path_vertices.reverse()

# Highlight edges in the longest path
path_edges = [(path_vertices[i], path_vertices[i+1]) for i in range(len(path_vertices)-1)]

# Plot graph
P = G.plot(
    vertex_size=500,
    vertex_labels=True,
    edge_colors={'red': path_edges},  # Highlight longest path in red
    layout='acyclic'  # DAG-friendly layout
)
P.show()