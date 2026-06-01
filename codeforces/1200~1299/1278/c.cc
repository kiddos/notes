#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int diff = 0;
  for (int i = 0; i < m; ++i) {
    if (a[i] == 1) {
      diff++;
    } else if (a[i] == 2) {
      diff--;
    }
  }

  if (diff == 0) {
    cout << "0" << endl;
    return;
  }

  int ans = m;
  map<int,int> count;
  count[0] = 0;
  for (int i = n-1, d = 0; i >= 0; --i) {
    if (a[i] == 1) {
      d++;
    } else if (a[i] == 2) {
      d--;
    }
    if (!count.count(d)) {
      count[d] = n-i;
    }
    if (d == diff) {
      ans = min(ans, n-i);
    }
  }

  for (int i = n, d = 0; i < m; ++i) {
    if (a[i] == 1) {
      d++;
    } else if (a[i] == 2) {
      d--;
    }
    if (count.count(diff - d)) {
      int total_remove = i-n+1 + count[diff - d];
      ans = min(ans, total_remove);
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
