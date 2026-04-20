#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int first = -1, last = -1;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      last = i;
      if (first < 0) {
        first = i;
      }
      count++;
    }
  }

  if (first < 0) {
    cout << "0" << endl;
  } else {
    int total_len = last - first + 1;
    int ans = total_len - count;
    cout << ans << endl;
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
