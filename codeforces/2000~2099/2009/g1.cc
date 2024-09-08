#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> d(n+1);
  for (int i = 1; i <= n; ++i) {
    d[i] = a[i] - i;
  }

  map<int,int> groups;
  set<pair<int,int>> g;

  auto add = [&](int d) {
    g.erase({groups[d], d});
    groups[d]++;
    g.insert({groups[d], d});
  };

  auto remove = [&](int d) {
    g.erase({groups[d], d});
    groups[d]--;
    g.insert({groups[d], d});
  };

  auto find_max = [&]() -> int {
    return g.rbegin()->first;
  };

  vector<int> max_sizes(n+1);
  for (int i = 1; i <= n; ++i) {
    add(d[i]);
    if (i > k) {
      remove(d[i-k]);
    }
    max_sizes[i] = find_max();
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << max_sizes[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    int max_size = max_sizes[r];
    int op = r - l + 1 - max_size;
    cout << op << endl;
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
