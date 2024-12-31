#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<i64> bob(n);
  for (int i = n-1; i >= 0; --i) {
    if (i+1 < n) {
      bob[i] = bob[i+1];
    }
    if (s[i] == '1') {
      bob[i]++;
    } else {
      bob[i]--;
    }
  }

  bob[0] = 0;

  vector<i64> sorted = bob;
  sort(sorted.rbegin(), sorted.rend());
  i64 total_value = 0;
  for (int i = 0; i < n; ++i) {
    total_value += sorted[i];
    // cout << "total=" << total_value << ", i=" << i << endl;
    if (total_value >= k && i+2 <= n) {
      cout << i+2 << endl;
      return;
    }
  }
  cout << "-1" << endl;
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
