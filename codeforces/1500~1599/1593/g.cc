#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  s = " " + s;
  vector<int> even(n+1), odd(n+1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '[' || s[i] == ']') {
      if (i % 2 == 0) {
        even[i]++;
      } else {
        odd[i]++;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    even[i] += even[i-1];
    odd[i] += odd[i-1];
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    int e = even[r] - even[l-1];
    int o = odd[r] - odd[l-1];
    int ans = abs(e - o);
    cout << ans << endl;
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
