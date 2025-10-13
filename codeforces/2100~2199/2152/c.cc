#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  vector<vector<int>> count(2, vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    int p = b[i]%2;
    count[p][i]++;
    count[0][i] += count[0][i-1];
    count[1][i] += count[1][i-1];
  }
  vector<int> alternating(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    if (b[i] != b[i-1]) {
      alternating[i] = alternating[i-1]+1;
    }
  }

  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    int len = r - l + 1;
    if (len % 3 != 0) {
      ans[i] = -1;
      continue;
    }

    int one = count[1][r] - count[1][l-1];
    if (one % 3 != 0) {
      ans[i] = -1;
      continue;
    }

    int alt = alternating[r] - alternating[l] + (b[l] != b[l+1]);
    if (alt == len) {
      ans[i] = len / 3 + 1;
    } else{
      ans[i] = len / 3;
    }
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
