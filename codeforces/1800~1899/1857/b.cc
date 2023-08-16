#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string x;
  cin >> x;

  x = "0" + x;

  int n = x.length();
  int last_round_up = n;
  for (int i = n-1; i > 0; --i) {
    if (x[i] >= '5') {
      x[i-1]++;
      last_round_up = i;
    }
  }

  for (int j = last_round_up; j < n; ++j) {
    x[j] = '0';
  }

  int i = 0;
  while (x[i] == '0') i++;
  string ans = x.substr(i);

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
