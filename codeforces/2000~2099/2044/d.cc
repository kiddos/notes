#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> pool;
  for (int i = 1; i <= n; ++i) {
    pool.insert(i);
  }

  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (pool.count(a[i])) {
      b.push_back(a[i]);
      pool.erase(a[i]);
    } else {
      b.push_back(*pool.begin());
      pool.erase(pool.begin());
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
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
