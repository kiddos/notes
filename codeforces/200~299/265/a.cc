#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  int i = 0;
  for (char ch : t) {
    if (i < (int)s.length() && s[i] == ch) {
      i++;
    }
  }
  int ans = i+1;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
