#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  i64 right = 0;
  for (int i = 0; i < n; ++i) {
    right += s[i] == 'Q';
  }
  i64 left = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'Q') {
      right--;
      left++;
    } else if (s[i] == 'A') {
      ans += left * right;
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
