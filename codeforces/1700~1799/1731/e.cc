#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;

  // euler's totient function
  vector<i64> phi(n+1);
  iota(phi.begin(), phi.end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }

  vector<i64> p = phi;
  for (int i = 2; i <= n; ++i) {
    p[i] += p[i-1];
  }

  i64 ans = 0;
  for (int k1 = n; k1 >= 2; --k1) {
    i64 edge_count = p[n/k1] - p[1];
    i64 k = k1-1;
    i64 cost = k1;
    if (m >= k) {
      i64 pack = min(edge_count / k, m / k);
      m -= pack * k;
      ans += cost * pack;
    }
    // cout << "k=" << k << ", edge_count=" << edge_count << endl;
  }

  // cout << "m=" << m << endl;
  if (m == 0) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
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
