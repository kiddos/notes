#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void solve() {
  int n = 0;
  cin >> n;

  auto query = [&](int node) -> vector<int> {
    cout << "? " << node << endl;
    vector<int> dist(n+1);
    for (int i = 1; i <= n; ++i) {
      cin >> dist[i];
    }
    return dist;
  };

  auto create_edge = [&](int a, int b) -> pair<int,int>{
    return {min(a, b), max(a, b)};
  };

  set<pair<int,int>> edges;
  vector<int> dist1 = query(1);
  vector<int> sides(2);
  for (int i = 1; i <= n; ++i) {
    sides[dist1[i]%2]++;
    if (dist1[i] == 1) {
      edges.insert(create_edge(1, i));
    }
  }

  vector<bool> visited(n+1);
  visited[1] = true;

  queue<int> q;
  if (sides[0] <= sides[1]) {
    for (int i = 1; i <= n; ++i) {
      if (dist1[i] == 2) {
        q.push(i);
        visited[i] = true;
      }
    }
  } else {
    // find a node from the other side
    for (int i = 1; i <= n; ++i) {
      if (dist1[i] % 2 == 1) {
        q.push(i);
        visited[i] = true;
        break;
      }
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      vector<int> dist = query(node);
      for (int i = 1; i <= n; ++i) {
        if (dist[i] == 1) {
          edges.insert(create_edge(i, node));
        } else if (dist[i] == 2) {
          if (!visited[i]) {
            visited[i] = true;
            q.push(i);
          }
        }
      }
    }
  }

  cout << "!" << endl;
  for (auto [a, b] : edges) {
    cout << a << " " << b << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
