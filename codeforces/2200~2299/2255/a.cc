#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 00000111110  
// 00000111101  
//
// rbrbrb
// 101110
// 011110
// 011101
//
// rbrbrbrbrbrbrb
// 10011110101011
// 01011101010111

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = n*2;

  vector<bool> can_pass(m);
  for (int i = 0; i < m; ++i) {
    if (s[i] == '1' && s[(i+1)%m] == '0') {
      can_pass[i] = true;
    }
  }

  string s2 = s;
  for (int i = 0; i < m; ++i) {
    if (can_pass[i]) {
      s2[i] = '0';
      s2[(i+1)%m] = '1';
    }
  }

  int red = 0, blue = 0;
  for (int i = 0; i < m; ++i) {
    if (s2[i] == '1') {
      if (i % 2 == 0) {
        blue++;
      } else {
        red++;
      }
    }
  }
  cout << red << " " << blue << endl;
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
