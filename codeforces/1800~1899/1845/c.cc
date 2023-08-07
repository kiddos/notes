#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int m = 0;
  cin >> m;
  string L, R;
  cin >> L >> R;

  vector<int> occur(10, n);
  vector<vector<int>> next_occur(n+1);
  next_occur.back() = occur;
  for (int i = n-1; i >= 0; --i) {
    int d = s[i] - '0';
    occur[d] = i;
    next_occur[i] = occur;
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << "next occur at " <<i << ": " << endl;
  //   for (int d = 0; d < 10; ++d) cout << next_occur[i][d] << " ";
  //   cout << endl;
  // }

  vector<vector<int>> memo(m, vector<int>(n+1, -1));
  function<bool(int,int)> dp = [&](int i, int j) -> bool {
    // cout << "i=" << i << ", j=" << j << endl;
    if (j >= n) return true;
    if (i == m-1) {
      for (char c = L[i]; c <= R[i]; ++c) {
        int d = c - '0';
        int j2 = next_occur[j][d];
        if (j2 >= n) return true;
      }
      return false;
    }

    if (memo[i][j] >= 0) return memo[i][j] == 1;
    
    bool ans = false;
    for (char c = L[i]; c <= R[i]; ++c) {
      int d = c - '0';
      int j2 = next_occur[j][d];
      if (dp(i+1, j2+1)) {
        ans = true;
        break;
      }
    }
    memo[i][j] = ans ? 1 : 0;
    return ans;
  };

  bool ans = dp(0, 0);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
