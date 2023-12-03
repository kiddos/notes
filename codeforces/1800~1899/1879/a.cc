#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> s(n), e(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> e[i];
  }

  for (int i = 1; i < n; ++i) {
    if (s[i] >= s[0] && e[i] >= e[0]) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << s[0] << endl;
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
