#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) {
    index[p[i]] = i;
  }

  int r = index[0], l = index[0];
  i64 ans = 1;
  for (int len = 2; len <= n; ++len) {
    int mid = (len-1) / 2;
    l = min(l, min(index[mid], n-len+1));
    r = max(r, max(index[mid], len));
    int add = max(len-(r-l), 0);
    ans += add;
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
