#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  int ans = 0;
  while (i < n) {
    int j = i;
    while (j+1 < n && s[j+1] == s[i]) {
      j++;
    }
    int len = j-i+1;
    i = j+1;
    ans = max(ans, len);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
