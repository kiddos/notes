#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k > 0) {
    if (n == 1) {
      if (s[0] != '0') {
        s[0] = '0';
        k--;
      }
    } else {
      if (s[0] != '1') {
        s[0] = '1';
        k--;
      }
    }
  }
  for (int i = 1; i < n && k > 0; ++i) {
    if (s[i] != '0') {
      s[i] = '0';
      k--;
    }
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
