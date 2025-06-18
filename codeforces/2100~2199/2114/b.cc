#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int zeros = 0, ones = 0;
  for (char ch : s) {
    zeros += ch == '0';
    ones += ch == '1';
  }
  int different = (n - k * 2) / 2;

  if (zeros < different || ones < different) {
    cout << "NO" << endl;
    return;
  }
  zeros -= different;
  ones -= different;
  if (zeros % 2 != 0 || ones % 2 != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
