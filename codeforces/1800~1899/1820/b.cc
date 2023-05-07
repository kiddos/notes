#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;
  ll n = s.length();

  if (s == string(n, '1')) {
    cout << n*n << endl;
    return;
  }

  ll max_len = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == '0') {
      i++;
    } else {
      int j = i+1;
      while (j < 2*n && s[j%n] == '1') {
        j++;
      }
      ll len = j-i;
      max_len = max(max_len, len);
      i = j;
    }
  }

  ll ans = 0;
  for (ll p = 1, q = max_len; p <= max_len; ++p, q--) {
    ans = max(ans, q * p);
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
