#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> a(n+1);
  iota(a.begin(), a.end(), 0);
  vector<int> c(n+1);
  for (int i = 1, g = 1; i <= n; i += k, ++g) {
    int l = i, r = min(i + k - 1, n);
    for (int j = l; j <= r; ++j) {
      c[j] = g;
    }
    int mid = (l + r) / 2 + 1;
    reverse(a.begin() + l, a.begin() + mid);
    reverse(a.begin() + mid, a.begin() + r + 1);
  }

  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  cout << endl;
  cout << *max_element(c.begin(), c.end()) << endl;
  for (int i = 1; i <= n; ++i) cout << c[i] << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
