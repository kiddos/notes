#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;

  if (t == "a") {
    cout << "1" << endl;
    return;
  }
  
  if (t.find('a') != string::npos) {
    cout << "-1" << endl;
    return;
  }

  i64 ans = 1LL << (s.length());
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
