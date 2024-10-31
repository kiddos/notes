#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<bool> top_k(n);
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] >= n-k+1) {
      top_k[i] = true;
      sum += p[i];
    }
  }
  int last = -1;
  i64 max_count = 1;
  constexpr int MOD = 998244353;
  for (int i = 0; i < n; ++i) {
    if (top_k[i]) {
      if (last >= 0) {
        int len = i-last-1;
        max_count *= (len+1);
        max_count %= MOD;
      }

      last = i;
    }
  }
  cout << sum << " " << max_count << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
