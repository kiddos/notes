#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();
  vector<int> row_ones(n);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      total += a[i][j];
      row_ones[i] += a[i][j];
    }
  }

  if (total % n != 0) {
    cout << -1 << endl;
    return;
  }

  vector<array<int, 3>> ans;
  int require_ones = total / n;
  vector<int> more, less;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (row_ones[i] > require_ones && a[i][j]) {
        more.push_back(i);
      } else if (row_ones[i] < require_ones && !a[i][j]) {
        less.push_back(i);
      }
    }

    int k = min(less.size(), more.size());
    for (int i = 0; i < k; ++i) {
      row_ones[more[i]]--;
      row_ones[less[i]]++;
      ans.push_back({more[i]+1, less[i]+1, j+1});
    }

    more.clear();
    less.clear();
  }

  cout << ans.size() << endl;
  for (auto& [x, y, z] : ans) {
    cout << x << " " << y << " " << z << endl;
  }
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }

    solve(a);
  }
  return 0;
}
