#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  string s;
  cin >> s;
  int n = s.length();
  vector<int> count(26);
  for (int i = 0; i < n ; ++i) {
    count[s[i]-'a']++;
  }
  string part;
  for (int c = 0; c < 26; ++c) {
    if (count[c] % k != 0) {
      cout << "-1" << endl;
      return;
    }
    part += string(count[c] / k, c + 'a');
  }
  string ans;
  for (int t = 0; t < k; ++t) {
    ans += part;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
