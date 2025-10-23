#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }
  for (int l = 0; l < n-2; ++l) {
    for (int r = l+1; r < n-1; ++r) {
      int prefix = p[l+1] % 3;
      int middle = (p[r+1] - p[l+1]) % 3;
      int suffix = (p[n] - p[r+1]) % 3;
      set<int> s = {prefix, middle, suffix};
      if (s.size() == 1 || s.size() == 3) {
        cout << l+1 << " " << r +1 << endl;
        return;
      }
    }
  }
  cout << "0 0" << endl;
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
