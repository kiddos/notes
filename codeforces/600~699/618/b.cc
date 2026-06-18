#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> ans(n);
  for (int x = 1; x < n; ++x) {
    vector<int> row_count(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == x) {
          row_count[i]++;
        }
      }
    }
    int idx = max_element(row_count.begin(), row_count.end()) - row_count.begin();
    ans[idx] = x;
  }

  for (int i = 0; i < n; ++i) {
    if (!ans[i]) {
      ans[i] = n;
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
