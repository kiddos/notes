#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  int n = x + y;
  vector<int> count;
  if (n % 2 == 0) {
    count = {1, n-1};
  } else {
    count = {0, n};
  }

  vector<int> parents(n+1, 1);
  for (int node = 2; node+1 <= n && count[0] < x; node += 2) {
    parents[node] = node+1;
    count[0]++;
    count[1]--;
  }

  if (count[0] != x || count[1] != y) {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  for (int node = 2; node <= n; ++node) {
    ans.push_back({parents[node], node});
  }

  cout << "YES" << endl;
  for (auto [u, v] : ans) {
    cout << u << " " << v << endl;
  }
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
