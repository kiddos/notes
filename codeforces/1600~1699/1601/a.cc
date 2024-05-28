#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int zero = 0;
  for (int i = 0; i < n; ++i) {
    zero += a[i] == 0;
  }

  if (zero == n) {
    for (int k = 1; k <= n; ++k) {
      cout << k << " ";
    }
    cout << endl;
    return;
  }

  constexpr int MAX_BIT = 30;
  vector<int> counts(MAX_BIT);
  for (int b = 0; b < MAX_BIT; ++b) {
    for (int i = 0; i < n; ++i) {
      if (a[i] & (1<< b)) {
        counts[b]++;
      }
    }
  }

  auto compute_factor = [&](int x) -> vector<int> {
    vector<int> f;
    for (int d = 1; d*d <= x; ++d) {
      if (x % d == 0) {
        f.push_back(d);
        f.push_back(x / d);
      }
    }
    sort(f.begin(), f.end());
    f.resize(unique(f.begin(), f.end()) - f.begin());
    return f;
  };

  int total = 0;
  map<int, int> f_count;
  for (int b = 0; b < MAX_BIT; ++b) {
    if (counts[b] == 0) continue;
    vector<int> factors = compute_factor(counts[b]);
    for (int f : factors) {
      f_count[f]++;
    }
    total++;
  }

  vector<int> ans;
  for (auto& [f, count] : f_count) {
    if (count == total) {
      ans.push_back(f);
    }
  }

  for (int k : ans) {
    cout << k << " ";
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
