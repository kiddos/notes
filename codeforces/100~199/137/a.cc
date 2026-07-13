#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  int idx = 0;
  int ans = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }

    int len = j-idx+1;
    ans += (len + 4) / 5;
    idx = j+1;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
