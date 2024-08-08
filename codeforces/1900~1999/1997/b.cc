#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(2);
  for (int i = 0; i < 2; ++i) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (s[0][i] == '.' && s[0][i-1] == 'x' && s[0][i+1] == 'x' && s[1][i-1] == '.' && s[1][i+1] == '.' && s[1][i] == '.') {
      ans++;
    } else if (s[1][i] == '.' && s[1][i-1] == 'x' && s[1][i+1] == 'x' && s[0][i-1] == '.' && s[0][i+1] == '.' && s[0][i] == '.') {
      ans++;
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
