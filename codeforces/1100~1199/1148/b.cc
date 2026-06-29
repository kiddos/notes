#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 ta = 0, tb = 0;
  int k = 0;
  cin >> n >> m >> ta >> tb >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  if (n <= k || m <= k) {
    cout << "-1" << endl;
    return;
  }

  vector<int> possible;
  for (int i = 0; i <= k; ++i) {
    auto it = lower_bound(b.begin(), b.end(), a[i] + ta);
    int cancel_b = k-i;
    int start_index = (it-b.begin()) + cancel_b;
    if (start_index < m) {
      possible.push_back(b[start_index] + tb);
    } else {
      cout << "-1" << endl;
      return;
    }
  }

  if (possible.empty()) {
    cout << "-1" << endl;
    return;
  }

  i64 ans = *max_element(possible.begin(), possible.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
