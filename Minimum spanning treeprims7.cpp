

# Number of offices
n = 5

# Connections: (Office1, Office2, Cost)
edges = [
    (0, 1, 2),
    (0, 3, 6),
    (1, 2, 3),
    (1, 3, 8),
    (1, 4, 5),
    (2, 4, 7),
    (3, 4, 9)
]


# Prim's Algorithm
def prim():
    visited = [False] * n
    visited[0] = True
    mst = []
    cost = 0

    while len(mst) < n - 1:
        minimum = float('inf')
        edge = None

        for u, v, w in edges:
            if visited[u] != visited[v] and w < minimum:
                minimum = w
                edge = (u, v, w)

        if edge is None:
            print("Graph is not connected!")
            return

        u, v, w = edge
        visited[u] = True
        visited[v] = True
        mst.append(edge)
        cost += w

    print("\nPrim's MST:")
    for u, v, w in mst:
        print(u, "-", v, "Cost:", w)

    print("Prim's Total Cost:", cost)


# Kruskal's Algorithm
def kruskal():
    parent = list(range(n))
    mst = []
    cost = 0

    def find(x):
        while parent[x] != x:
            x = parent[x]
        return x

    for u, v, w in sorted(edges, key=lambda e: e[2]):
        a = find(u)
        b = find(v)

        if a != b:
            mst.append((u, v, w))
            cost += w
            parent[a] = b

        if len(mst) == n - 1:
            break

    if len(mst) != n - 1:
        print("\nGraph is not connected!")
        return

    print("\nKruskal's MST:")
    for u, v, w in mst:
        print(u, "-", v, "Cost:", w)

    print("Total cost using Kruskal's:", cost)


if n > 0:
    prim()
    kruskal()
else:
    print("Number of offices must be positive!")
