#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int zeros = 0;
  for (char ch : s) {
    zeros += ch == '0';
  }
  if (zeros == 0) {
    cout << "DRAW" << endl;
    return;
  }

  if (n % 2 == 1 && s[n/2] == '0' && zeros > 1) {
    cout << "ALICE" << endl;
  } else {
    cout << "BOB" << endl;
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
