#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (s[i] == 'x') {
      int j = i;
      while (j+1 < n && s[j+1] == 'x') {
        j++;
      }
      int len = j-i+1;
      if (len >= 3) {
        ans += len-2;
      }
      i = j+1;
    } else {
      i++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
