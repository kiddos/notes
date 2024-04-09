#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int one = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '1' && s[i-1] == '1') {
      one++;
      i++;
    }
  }
  int total = 0;
  for (int i = 0; i < n; ++i) total += s[i] == '1';

  if (total % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  if (one == 1 && total == 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
