#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> q(k);
  for (int i = 0; i < k; ++i) {
    cin >> q[i];
  }

  if (k == n) {
    cout << string(m, '1') << endl;
  } else if (k == n-1) {
    int dont_know = n;
    for (int i = 0; i < k; ++i) {
      if (q[i] != i + 1) {
        dont_know = i+1;
        break;
      }
    }
    string ans(m, '0');
    for (int i = 0; i < m; ++i) {
      if (a[i] == dont_know) {
        ans[i] = '1';
      }
    }
    cout << ans << endl;
  } else {
    cout << string(m, '0') << endl;
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
