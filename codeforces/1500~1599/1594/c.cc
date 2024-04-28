#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// choose 2 -> [1, 3, 5, 7, 9, 11, 13, ...]
// choose 3 -> [1, 2, 4, 5, 7, 8, 10, 11]

void solve() {
  int n = 0;
  char c = 0;
  cin >> n >> c;
  string s;
  cin >> s;

  if (s == string(n, c)) {
    cout << "0" << endl;
    return;
  }

  s = " " + s;

  for (int i = 2; i <= n; ++i) {
    bool all_same = true;
    for (int j = i; j <= n; j += i) {
      if (s[j] != c) {
        all_same = false;
      }
    }
    if (all_same) {
      cout << "1" << endl;
      cout << i << endl;
      return;
    }
  }
  cout << "2" << endl;
  cout << n-1 << " " << n << endl;
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
