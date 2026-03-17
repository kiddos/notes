#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  int m = 1 << n;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> b(q), c(q);
  for (int i = 0; i < q; ++i) {
    cin >> b[i] >> c[i];
    b[i]--;
  }

  vector<vector<int>> rounds(n+1, vector<int>(m));
  rounds[0] = a;
  for (int r = 1; r <= n; ++r) {
    int step = 1 << r;
    for (int i = 0; i < m; i += step) {
      int j = i + (1<<(r-1));
      rounds[r][i] = rounds[r-1][i] ^ rounds[r-1][j];
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << rounds[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int idx = b[i];
    int current_skill = c[i];
    int top = 0;
    for (int r = 0; r < n; ++r) {
      int idx2 = idx ^ (1<<r);
      int opponent_skill = rounds[r][idx2];

      if (idx & (1<<r)) {
        // current is right fighting left
        if (opponent_skill >= current_skill) {
          top += (1<<r);
        }
        idx = idx2;
      } else {
        // current is left fighting right
        if (opponent_skill > current_skill) {
          top += (1<<r);
        }
      }
      current_skill ^= opponent_skill;
    }
    ans.push_back(top);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
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
