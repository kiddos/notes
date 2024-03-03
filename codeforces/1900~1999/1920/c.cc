#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> sizes;
  for (int s = 1; s*s <= n; ++s) {
    if (n % s == 0) {
      sizes.push_back(s);
      if (n/s != s) sizes.push_back(n/s);
    }
  }
  sort(sizes.begin(), sizes.end());

  auto gcd_diff = [&](int i, int k) -> int {
    int min_val = numeric_limits<int>::max();
    for (int j = i; j < n; j += k) {
      min_val = min(min_val, a[j]);
    }
    int g = 0;
    for (int j = i; j < n; j += k) {
      int d = a[j] - min_val;
      g = gcd(g, d);
    }
    return g;
  };

  auto try_partition = [&](int k) -> bool {
    int g1 = 0;
    //cout << "k=" << k << endl;
    for (int i = 0; i < k; ++i) {
      int g2 = gcd_diff(i, k);
      g1 = gcd(g1, g2);
      //cout << g2 << " ";
    }
    //cout << endl;
    return g1 != 1;
  };

  int ans = 0;
  for (int k : sizes) {
    if (try_partition(k)) {
      ans++;
    }
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
