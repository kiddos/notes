#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 min_ops(vector<int>& x) {
  sort(x.begin(), x.end());
  int size = x.size();
  int mid = size / 2;
  i64 ops = 0;
  for (int i = 0; i < size; ++i) {
    ops += abs(x[i] - x[mid]);
  }
  return ops;
}

i64 find_min_ops(vector<int>& a) {
  int n = a.size();
  constexpr i64 inf = 1e18;
  vector<vector<i64>> make_same(n, vector<i64>(4, inf));
  for (int i = 0; i < n; ++i) {
    vector<int> x = {a[i]};
    for (int offset = 2; offset <= 3; ++offset) {
      int j = (i + offset - 1 + n) % n;
      x.push_back(a[j]);
      make_same[i][offset] = min_ops(x);
    }
  }

  vector<i64> memo1(n, -1);
  auto dp1 = [&](const auto& self, int i) -> i64 {
    if (i == n) {
      return 0;
    }
    if (i == n-1) {
      return inf;
    }
    if (memo1[i] >= 0) {
      return memo1[i];
    }
    i64 ans = self(self, i+2) + make_same[i][2];
    if (i+3 <= n) {
      ans = min(ans, self(self, i+3) + make_same[i][3]);
    }
    return memo1[i] = ans;
  };
  return dp1(dp1, 0);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ans = find_min_ops(a);
  for (int i = 1; i <= 2; ++i) {
    int first = a[0];
    a.erase(a.begin());
    a.push_back(first);
    ans = min(ans, find_min_ops(a));
  }
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
