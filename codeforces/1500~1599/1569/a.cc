#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int l = 0; l < n; ++l) {
    int balance = 0;
    for (int r = l; r < n; ++r) {
      if (s[r] == 'a') {
        balance++;
      } else if (s[r] == 'b') {
        balance--;
      }

      if (balance == 0) {
        cout << l + 1 << " " << r + 1 << endl;
        return;
      }
    }
  }
  cout << "-1 -1" << endl;
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
