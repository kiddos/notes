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
  bool find_pos = a[0] > 0;
  int i = 0;
  i64 ans = 0;
  while (i < n) {
    int j = i;
    int max_val = a[i];
    if (find_pos) {
      while (j+1 < n && a[j+1] > 0) {
        max_val = max(max_val, a[++j]);
      }
    } else {
      while (j+1 < n && a[j+1] < 0) {
        max_val = max(max_val, a[++j]);
      }
    }

    ans += max_val;
    find_pos = !find_pos;
    i = j+1;
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
