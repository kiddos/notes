#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> bits_count(31);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 31; ++j) {
      if (a[i] & (1<<j)) {
        bits_count[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    if (bits_count[i] == n) {
      ans |= (1<<i);
    } else if (k >= (n - bits_count[i])) {
      k -= n - bits_count[i];
      ans |= (1<<i);
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
