#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    cin >> x;
    a[i] = {x, i};
  }

  sort(a.rbegin(), a.rend());
  vector<int> ans(n);
  for (int i = 0, p = 1; i < n; ++i, ++p) {
    ans[a[i].second] = p;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
