#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  auto can_invert = [&](int k) -> bool {
    int x = 0;
    deque<int> d;
    for (int i = 0; i < n; ++i) {
      while (!d.empty() && d.front() <= i-k) {
        d.pop_front();
        x ^= 1;
      }
      int b = (s[i] == '1' ? 1 : 0) ^ x;
      if (!b) {
        if (i <= n-k) {
          x ^= 1;
          d.push_back(i);
        } else {
          return false;
        }
      }
    }
    return true;
  };

  for (int k = n; k >= 1; --k) {
    if (can_invert(k)) {
      cout << k << endl;
      return;
    }
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
