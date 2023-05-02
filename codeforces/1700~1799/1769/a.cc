#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = a[i] - (i+1);
    if (i > 0) ans[i] = max(ans[i], ans[i-1]+1);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
