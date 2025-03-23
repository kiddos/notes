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
  vector<int> c(3);
  for (int i = 0; i < n; ++i) {
    c[a[i]%3]++;
  }

  int ans = 0;
  int size = n/3;
  for (int t = 0; t < 3; ++t) {
    for (int k = 0; k < 3; ++k) {
      if (c[k] > size) {
        int extra = c[k]-size;
        c[k] -= extra;
        c[(k+1)%3] += extra;
        ans += extra;
      }
    }
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
