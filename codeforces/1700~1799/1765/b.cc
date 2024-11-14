#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int k = 0, i = 0;
  while (i < n) {
    if (k % 2 == 0) {
      i++;
      k++;
    } else {
      if (i+1 >= n || s[i] != s[i+1]) {
        cout << "NO" << endl;
        return;
      } else {
        i += 2;
        k++;
      }
    }
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
