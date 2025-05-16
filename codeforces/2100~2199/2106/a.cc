#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int total = 0;
  for (char ch : s) {
    if (ch == '1') total++;
  }

  int ans = 0;
  for (char ch : s) {
    if (ch == '1') {
      ans += total-1;
    } else {
      ans += total+1;
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
