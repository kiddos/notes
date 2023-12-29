#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  array<int, 2> counts = {0, 0};
  for (int i = 0; i < n; ++i) {
    counts[s[i] - '0']++;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (counts[1] == 0) {
        cout << n-i << endl;
        return;
      } else {
        counts[1]--;
      }
    } else if (s[i] == '1') {
      if (counts[0] == 0) {
        cout << n-i << endl;
        return;
      } else {
        counts[0]--;
      }
    }
  }

  cout << "0" << endl;
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
