#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string ans;
  string other;
  for (char ch : s) {
    if (ch != 'T') {
      ans.push_back(ch);
    } else {
      other.push_back(ch);
    }
  }
  ans = other + ans;
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
