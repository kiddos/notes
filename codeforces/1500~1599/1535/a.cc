#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> s(4);
  for (int i = 0; i < 4; ++i) {
    cin >> s[i];
  }
  if (min(s[0], s[1]) > max(s[2], s[3]) ||
      min(s[2], s[3]) > max(s[0], s[1])) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
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
