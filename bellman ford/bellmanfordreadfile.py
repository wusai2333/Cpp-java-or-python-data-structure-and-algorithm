import copy
import os


def calculate_least_adjacent_cost(adjacencyList, i, v, cache):
    adjacent_nodes = adjacencyList[v]

    least_adjacent_cost = float("inf")
    for node in adjacent_nodes:
        adjacent_cost = cache[node["from"] - 1] + node["weight"]
        if adjacent_cost < least_adjacent_cost:
            least_adjacent_cost = adjacent_cost
    return least_adjacent_cost


file = open(os.path.dirname(os.path.realpath(__file__)) + "/g_small2.txt")
vertices, edges = map(lambda x: int(
    x), file.readline().replace("\n", "").split(" "))

adjacencyList = [[] for k in range(vertices)]
for line in file.readlines():
    tail, head, weight = line.split(" ")
    adjacencyList[int(head) -
                  1].append({"from": int(tail), "weight": int(weight)})
s = 0
cache = [[0 for k in range(vertices + 1)] for j in range(vertices + 1)]
cache[0][s] = 0

for v in range(0, vertices):
    if v != s:
        cache[0][v] = float("inf")

for i in range(1, vertices):
    for v in range(0, vertices):
        least_adjacent_cost = calculate_least_adjacent_cost(
            adjacencyList, i, v, cache[i - 1])
        cache[i][v] = min(cache[i - 1][v], least_adjacent_cost)

# detecting negative cycles
for v in range(0, vertices):
    least_adjacent_cost = calculate_least_adjacent_cost(
        adjacencyList, i, v, cache[vertices - 1])
    cache[vertices][v] = min(cache[vertices - 1][v], least_adjacent_cost)

if (not cache[vertices] == cache[vertices - 1]):
    raise Exception("negative cycle detected")

shortest_path = min(cache[vertices - 1])
print("Shortest Path: " + str(shortest_path))
print(cache[vertices - 1])
