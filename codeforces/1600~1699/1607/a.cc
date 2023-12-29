#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string keyboard;
  string s;
  cin >> keyboard >> s;
  vector<int> index(26);
  for (int i = 0; i < (int)keyboard.length(); ++i) {
    index[keyboard[i]-'a'] = i;
  }
  int ans = 0;
  for (int i = 1; i < (int)s.length(); ++i) {
    ans += abs(index[s[i-1]-'a'] - index[s[i]-'a']);
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
