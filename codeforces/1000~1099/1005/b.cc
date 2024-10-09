#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  int l1 = s.length(), l2 = t.length();
  int i = l1 -1, j = l2 - 1;
  while (i >= 0 && j >= 0 && s[i] == t[j]) {
    i--;
    j--;
  }
  int ans = i + 1 + j + 1;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
