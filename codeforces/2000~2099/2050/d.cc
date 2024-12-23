#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  auto shift = [&](int l, int r) {
    for (int i = r; i > l; --i) {
      s[i] = s[i-1];
    }
  };

  for (int i = 0; i < n; ++i) {
    char c = s[i];
    int found = -1;
    for (int k = 1; k <= 9 && i+k < n; ++k) {
      if (s[i+k]-k > c) {
        found = k;
        c = s[i+k]-k;
      }
    }
    if (found >= 0) {
      char new_c = s[i+found] - found;
      shift(i, i+found);
      s[i] = new_c;
    }
  }
  cout << s << endl;
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
