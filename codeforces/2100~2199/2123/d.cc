#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int ones = 0;
  for (char ch : s) {
    ones += ch == '1';
  }
  if (ones <= k) {
    cout << "Alice" << endl;
    return;
  }
  if (n-k <= k-1) {
    cout << "Alice" << endl;
    return;
  }
  cout << "Bob" << endl;
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
