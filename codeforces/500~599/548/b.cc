#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  auto max_consecutive = [&](int r) -> int {
    int c = 0;
    int ans = 0;
    while (c < m) {
      if (a[r][c] == 1) {
        int j = c;
        while (j+1 < m && a[r][j+1] == 1) {
          j++;
        }
        int len = j-c+1;
        ans = max(ans, len);
        c = j+1;
      } else {
        c++;
      }
    }
    return ans;
  };

  vector<int> maxs(n);
  for (int i = 0; i < n; ++i) {
    maxs[i] = max_consecutive(i);
  }

  for (int i = 0; i < q; ++i) {
    int r = 0, c = 0;
    cin >> r >> c;
    r--;
    c--;
    a[r][c] ^= 1;
    maxs[r] = max_consecutive(r);
    int result = *max_element(maxs.begin(), maxs.end());
    cout << result << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
