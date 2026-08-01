#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<i64> prefix = {0};
  vector<int> last_assign(n+1);
  for (int i = 0; i < m; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int v = 0;
      i64 x = 0;
      cin >> v >> x;
      a[v] = x;
      last_assign[v] = i;
      prefix.push_back(prefix.back());
    } else if (t == 2) {
      i64 y = 0;
      cin >> y;
      prefix.push_back(prefix.back() + y);
    } else if (t == 3) {
      int q = 0;
      cin >> q;
      i64 add = prefix.back() - prefix[last_assign[q]];
      prefix.push_back(prefix.back());
      i64 ans = a[q] + add;
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
