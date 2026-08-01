#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  int x = 0, y = 0;
  cin >> x >> y;
  int total = accumulate(c.begin(), c.end(), 0);
  for (int k = 1, prefix = 0; k <= n-1; ++k) {
    prefix += c[k];
    int suffix = total - prefix;
    if (prefix >= x && prefix <= y && suffix >= x && suffix <= y) {
      cout << k+1 << endl;
      return;
    }
  }
  cout << "0" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
