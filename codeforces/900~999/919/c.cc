#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  i64 ans = 0;
  if (k == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans += s[i][j] == '.';
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      int len = 0;
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '.') {
          len++;
        } else {
          len = 0;
        }

        if (len >= k) {
          ans++;
        }
      }
    }

    for (int j = 0; j < m; ++j) {
      int len = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i][j] == '.') {
          len++;
        } else {
          len = 0;
        }

        if (len >= k) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
