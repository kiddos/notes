#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> total(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '1') {
        total[j]++;
      }
    }
  }

  for (int i = 0; i < n; ++i)  {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '1') {
        total[j]--;
      }
    }

    bool possible = true;
    for (int j = 0; j < m; ++j) {
      if (total[j] == 0) {
        possible = false;
        break;
      }
    }
    if (possible) {
      cout << "YES" << endl;
      return;
    }

    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '1') {
        total[j]++;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
