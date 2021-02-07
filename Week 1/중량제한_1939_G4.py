# 시간제한 1초 -> 2000만번 연산 수행 가능
# 메모리제한 128MB
# 2<=N<=10000, 1<=M<=100000
# 다익스트라 구현시 O(NM)으로 시간초과,
from collections import deque

n, m = map(int, input().split(' '))
islands = dict()
for _ in range(1,n+1):
    islands[_] = []
for _ in range(m):
    n1, n2, w = map(int, input().split(' '))

    islands[n1].append((n2, w))
    islands[n2].append((n1, w))

start, end = map(int,input().split(' '))

q = deque()
searched = set()
weights = [0 for _ in range(n+1)]
q += [start]
while q:
    nodes = q.popleft()
    if type(nodes) == int:
        nodes = [nodes]
    nodelist = set()
    for node in nodes:
        for neighbor_node_info in islands[node]:
            neighbor_node = neighbor_node_info[0]
            max_weight =  neighbor_node_info[1]
            if neighbor_node not in searched:
                weights[neighbor_node] = max(weights[neighbor_node], max_weight)
                nodelist.add(neighbor_node)
    for node in nodes:
        searched.add(node)
    q += nodelist

print(weights[end])


