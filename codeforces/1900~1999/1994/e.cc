#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;

  vector<int> sizes;
  for (int i = 0; i < k; ++i) {
    int n = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
      int p = 0;
      cin >> p;
    }
    sizes.push_back(n);
  }

  sort(sizes.rbegin(), sizes.rend());
  int ans = sizes[0];
  for (int i = 1; i < (int)sizes.size(); ++i) {
    int next_ans = 0;
    for (int s = sizes[i]; s >= 1; --s) {
      next_ans = max(next_ans, ans | s);
    }
    ans = next_ans;
  }
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
