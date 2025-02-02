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

  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() ^ a[i]);
  }

  auto query_xor = [&](int l, int r) {
    return p[r+1] ^ p[l];
  };

  vector<map<int,bool>> memo(n);
  function<bool(int,int)> dfs = [&](int i, int x) -> bool {
    if (i >= n) {
      return false;
    }
    if (memo[i].count(x)) {
      return memo[i][x];
    }

    int suffix = query_xor(i, n-1);
    if (suffix == x) {
      return true;
    }
    bool ans = false;
    int y = 0;
    for (int j = i; j < n; ++j) {
      y ^= a[j];
      if (y == x && dfs(j+1, x)) {
        ans = true;
        break;
      }
    }
    return memo[i][x] = ans;
  };

  int x = 0;
  for (int i = 0; i < n; ++i) {
    x ^= a[i];
    if (dfs(i+1, x)) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
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
