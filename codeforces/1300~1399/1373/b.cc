#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> c(2);
  for (char ch : s) {
    c[ch-'0']++;
  }
  int moves = min(c[0], c[1]);
  if (moves % 2 == 1) {
    cout << "DA" << endl;
  } else {
    cout << "NET" << endl;
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
