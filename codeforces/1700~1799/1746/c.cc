#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) {
    index[a[i]] = i;
  }

  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (index[i] == n) {
      ans.push_back(1);
    } else {
      ans.push_back(index[i]+1);
    }
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
}

// [5 4 3 2 1]
// [5 6 5 4 3]

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
