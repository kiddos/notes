#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;

  string ans;
  if (a >= b) {
    while (a > 0 && b > 0) {
      ans.push_back('0');
      ans.push_back('1');
      a--;
      b--;
    }
    ans += string(a, '0');
  } else {
    while (a > 0 && b > 0) {
      ans.push_back('1');
      ans.push_back('0');
      b--;
      a--;
    }
    ans += string(b, '1');
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
