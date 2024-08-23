import random


def gen_tree(n):
  added = [1]
  edges = []
  for i in range(2, n+1):
    idx = random.randint(0, len(added)-1)
    edges.append([added[idx], i])
    added.append(i)
  return edges


def compute_dist(adj, start):
  n = len(adj)
  dist = [0 for _ in range(n)]

  def dfs(node, p):
    for next_node in adj[node]:
      if next_node == p:
        continue

      dist[next_node] = dist[node] + 1
      dfs(next_node, node)

  dfs(start, 0)
  return dist


def main():
  n = 6
  edges = gen_tree(n)
  adj = [[] for _ in range(n+1)]
  for edge in edges:
    u = edge[0]
    v = edge[1]
    adj[u].append(v)
    adj[v].append(u)

  print(edges)
  while True:
    inputs = input().split(' ')
    if inputs[0] == '?':
      a = int(inputs[1])
      b = int(inputs[2])

      d1 = compute_dist(adj, a)
      d2 = compute_dist(adj, b)
      x = a
      dists = []
      for node in range(1, n+1):
        d = abs(d1[node] - d2[node])
        dists.append([d, d1[node], node])
      dists = sorted(dists)
      print(dists)
      x = dists[0][-1]
      print(x)
    elif inputs[0] == '!':
      break




if __name__ == '__main__':
  main()
