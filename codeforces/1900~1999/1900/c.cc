#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  s = " " + s;

  vector<int> left(n+1);
  vector<int> right(n+1);
  vector<bool> is_leaf(n+1, true);
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    if (l > 0) {
      left[i] = l;
      is_leaf[i] = false;
    }
    if (r > 0) {
      right[i] = r;
      is_leaf[i] = false;
    }
  }

  constexpr int INF = numeric_limits<int>::max();
  int ans = INF;
  function<void(int,int)> dfs = [&](int node, int diff) {
    if (is_leaf[node]) {
      ans = min(ans, diff);
    } else {
      if (left[node]) {
        dfs(left[node], diff + (s[node] != 'L'));
      }
      if (right[node]) {
        dfs(right[node], diff + (s[node] != 'R'));
      }
    }
  };

  dfs(1, 0);
  cout << ans << endl;
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
