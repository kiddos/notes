#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  string s;
  cin >> n >> s;

  ll total_zeros = 0, total_ones = 0;
  ll ans = 0;
  for (int i = 0, j = 0, k = 0; i < n; ++i) {
    j = max(j, i);
    k = max(k, i);

    if (s[i] == '1') {
      while (j < n && s[j] == '1') j++;
      ll len = j-i;
      ans = max(ans, len*len);
      total_ones++;
    } else if (s[i] == '0') {
      while (k < n && s[k] == '0') k++;
      ll len = k-i;
      ans = max(ans, len*len);
      total_zeros++;
    }
  }
  ans = max(ans, total_ones * total_zeros);
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
