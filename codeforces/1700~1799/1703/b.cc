#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> count(26);
  for (int i = 0; i < n; ++i) {
    count[s[i]-'A']++;
  }

  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (count[i]) {
      ans += count[i] +1;
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
