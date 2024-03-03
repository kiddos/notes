#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 5 0 1 2 3 4
// 4 5 0 1 2 3
// 3 4 5 0 1 2

int mex(vector<int>& a) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < (int)b.size(); ++i) {
    if (b[i] != i) {
      return i;
    }
  }
  return b.size();
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> ans(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    int x = 0;
    int s = m == 1 ? 0 : (i % (m-1) + 1);
    for (int j = s; j < m; ++j, ++x) {
      ans[i][j] = x;
    }
    for (int j = 0; j < s; ++j, ++x) {
      ans[i][j] = x;
    }
  }
  
  vector<int> v;
  for (int j = 0; j < m; ++j) {
    vector<int> col;
    for (int i = 0; i < n; ++i) {
      col.push_back(ans[i][j]);
    }
    v.push_back(mex(col));
  }


  int s = mex(v);
  cout << s << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
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
