#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    bool left = false;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        left = true;
      } else if (a[i][j] == 0) {
        if (left) {
          ans++;
        }
      }
    }
    bool right = false;
    for (int j = m-1; j >= 0; --j) {
      if (a[i][j] == 1) {
        right = true;
      } else if (a[i][j] == 0) {
        if (right) {
          ans++;
        }
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    bool top = false;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == 1) {
        top = true;
      } else if (a[i][j] == 0) {
        if (top) {
          ans++;
        }
      }
    }
    bool bot = false;
    for (int i = n-1; i >= 0; --i) {
      if (a[i][j] == 1) {
        bot = true;
      } else if (a[i][j] == 0) {
        if (bot) {
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
