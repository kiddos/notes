#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> t0(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t0[i];
  }

  int L = 30;
  vector<vector<int>> t(L, vector<int>(n+1));
  t[0] = t0;
  for (int l = 1; l < L; ++l) {
    for (int i = 1; i <= n; ++i) {
      t[l][i] = t[l-1][t[l-1][i]];
    }
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int x = 0, k = 0;
    cin >> x >> k;

    for (int l = L-1; l >= 0; --l) {
      if (k & (1<<l)) {
        x = t[l][x];
      }
    }
    ans.push_back(x);
  }

  for (int node : ans) {
    cout << node << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
