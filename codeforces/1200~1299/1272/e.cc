#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n+1);
  queue<int> q;
  vector<int> ans(n+1, -1);
  for (int i = 1; i <= n; ++i) {
    int p = a[i] % 2;
    bool left = i-a[i] >= 1 && a[i-a[i]] % 2 != p;
    bool right = i+a[i] <= n && a[i+a[i]] % 2 != p;
    if (left || right) {
      q.push(i);
      ans[i] = 1;
    }

    if (i-a[i] >= 1) {
      adj[i-a[i]].push_back(i);
    }
    if (i+a[i] <= n) {
      adj[i+a[i]].push_back(i);
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int index = q.front();
      q.pop();
      for (int prev_index : adj[index]) {
        if (ans[prev_index] > 0) {
          continue;
        }
        ans[prev_index] = ans[index] + 1;
        q.push(prev_index);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
