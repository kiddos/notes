#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> p(n+1, vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int val = s[i-1][j-1] == '*';
      p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + val;
    }
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int y1 = 0, x1 = 0, y2 = 0, x2 = 0;
    cin >> y1 >> x1 >> y2 >> x2;
    int result = p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1];
    ans.push_back(result);
  }

  for (int val : ans) {
    cout << val << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
