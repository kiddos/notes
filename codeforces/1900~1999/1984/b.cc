#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> d;
  for (int i = 0; i < n; ++i) {
    d.push_back(s[i] - '0');
  }

  if (d[0] != 1) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 1; i < n; ++i) {
    int sum = 10 + d[i];
    if (i == n-1) {
      if (sum / 2 < 5) {
        cout << "NO" << endl;
        return;
      }
      if (d[i] == 9) {
        cout << "NO" << endl;
        return;
      }
    } else {
      if ((sum-1) / 2 < 5) {
        cout << "NO" << endl;
        return;
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
