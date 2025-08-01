#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> regular, important;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1) {
      regular.push_back(a[i]);
    } else if (b[i] == 2) {
      important.push_back(a[i]);
    }
  }

  sort(regular.rbegin(), regular.rend());
  sort(important.rbegin(), important.rend());
  vector<i64> prefix = {0};
  for (int i = 0; i < (int)important.size(); ++i) {
    prefix.push_back(prefix.back() + important[i]);
  }

  i64 r = 0;
  int ans = numeric_limits<int>::max();
  auto it = lower_bound(prefix.begin(), prefix.end(), m);
  if (it != prefix.end()) {
    int count = it - prefix.begin();
    ans = min(ans, count * 2);
  }
  for (int i = 0; i < (int)regular.size(); ++i) {
    r += regular[i];
    it = lower_bound(prefix.begin(), prefix.end(), m - r);
    if (it != prefix.end()) {
      int count = it - prefix.begin();
      int total_points = count * 2 + i+1;
      ans = min(ans, total_points);
    }
  }
  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
