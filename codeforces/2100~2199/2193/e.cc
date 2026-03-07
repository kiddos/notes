#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 1; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(x / d);
      f.push_back(d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  constexpr int inf = 1e9;
  vector<int> ans(n+1, inf);
  for (int i = 0; i < n; ++i) {
    ans[a[i]] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    vector<int> factors = get_factors(i);
    for (int f : factors) {
      int f2 = i / f;
      if (ans[f] < inf && ans[f2] < inf) {
        ans[i] = min(ans[i], ans[f] + ans[f2]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (ans[i] < inf) {
      cout << ans[i] << " ";
    } else {
      cout << "-1 ";
    }
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
