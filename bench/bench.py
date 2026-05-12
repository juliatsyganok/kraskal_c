import networkx as nx
import time
import random

start_nodes = 10
max_nodes = 1000
step = 50

print("Nodes;Edges;Python_Time")

for n in range(start_nodes, max_nodes, step):
    e = n * 2  
    G = nx.Graph()
    edges = []
    for _ in range(e):
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        w = random.randint(1, 100)
        edges.append((u, v, w))
    G.add_weighted_edges_from(edges)

    start = time.perf_counter()
    mst = nx.minimum_spanning_tree(G, algorithm='kruskal')
    end = time.perf_counter()

    print(f"{n};{e};{(end - start):.6f}")