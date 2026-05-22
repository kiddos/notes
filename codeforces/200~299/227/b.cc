#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) {
    index[a[i]] = i;
  }

  int m = 0;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  i64 ans1 = 0, ans2 = 0;
  for (int i = 0; i < m; ++i) {
    ans1 += index[b[i]];
    ans2 += n - index[b[i]] + 1;
  }
  cout << ans1 << " " << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
