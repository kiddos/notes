#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 100000 -> o
// 11000
// 1110
// 100
// 11
// 0
//
// 11111 -> o
// 001
// 11
// 0
//
// 111 -> x
// 10
//
// 10100 -> o
// 1011
// 100
// 11
// 0
//
// 10011 -> o
// 1111
// 00
// 1
//
// 1001 -> x
// 111
// 10
//
// 1110 -> o
// 100
// 11
// 0
//
// 10101 -> x
//
//
// f(s) = number of 1s - number of 0s
// merging does not change f(s) % 3
//
// we are looking for f(s) % 3 != 0
// but here we included extra
// for example:
// when s = 10101 this f(s) = 1, but this should not be beautiful
// so we need to remove this kind


void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> mods(3);
  mods[0] = 1;
  vector<int> target = {1, 2};
  i64 ans = 0;
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      p++;
    } else if (s[i] == '0') {
      p += 2;
    }
    p %= 3;
    ans += mods[0] + mods[1] + mods[2] - mods[p];
    mods[p]++;
  }

  int idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] != s[j]) {
      j++;
    }
    int len = j-idx+1;
    for (int l = 3; l <= len; ++l) {
      ans -= (l-1) / 2;
    }

    idx = j+1;
  }

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
