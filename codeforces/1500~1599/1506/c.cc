#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  int len_a = a.length(), len_b = b.length();
  int max_match = 0;
  for (int i = 0; i < len_b; ++i) {
    for (int j = 0; j < len_a; ++j) {
      int p = i, q = j;
      int match = 0;
      while (p < len_b && q < len_a && b[p] == a[q]) {
        p++;
        q++;
        match++;
      }
      max_match = max(max_match, match);
    }
  }

  int ans = len_a - max_match + len_b - max_match;
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
