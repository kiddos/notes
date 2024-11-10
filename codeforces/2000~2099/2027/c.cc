#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  // ai = size + 1 - i
  // size = ai - 1 + i
  i64 n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  map<i64, vector<int>> indices;
  for (int i = 1; i <= n; ++i) {
    indices[a[i] - 1 + i].push_back(i);
  }

  set<i64> visited;
  queue<i64> q;
  q.push(n);
  visited.insert(n);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      i64 current_size = q.front();
      q.pop();
      if (indices.count(current_size)) {
        for (int idx : indices[current_size]) {
          i64 new_size = current_size + idx - 1;
          if (visited.count(new_size)) {
            continue;
          }
          visited.insert(new_size);
          q.push(new_size);
        }
      }
    }
  }

  i64 ans = *visited.rbegin();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
