#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  vector<string> t(5);
  cin >> s;
  for (int i = 0; i < 5; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < 5; ++i) {
    if (s[0] == t[i][0] || s[1] == t[i][1]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
