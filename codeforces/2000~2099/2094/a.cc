#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> s(3);
  for (int i = 0; i < 3; ++i) {
    cin >> s[i];
  }
  string ans;
  for (string& w : s) {
    ans.push_back(w[0]);
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
