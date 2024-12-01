#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> count(26);
  for (char ch : s) {
    count[ch-'a']++;
  }

  int ans = 0, rest = 0;
  for (int c = 0; c < 26; ++c) {
    if (count[c] >= 2) {
      ans++;
    } else {
      rest += count[c];
    }
  }
  ans += rest / 2;
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
