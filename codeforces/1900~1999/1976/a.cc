#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  auto is_valid = [&](char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
  };

  auto check = [&]() -> bool {
    for (int i = 0; i < n; ++i) {
      if (!is_valid(s[i])) {
        return false;
      }
    }
    for (int i = 1; i < n; ++i) {
      if (s[i-1] > s[i]) {
        return false;
      }
    }
    return true;
  };

  if (!check()) {
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
