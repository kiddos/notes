#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  int max_val = *max_element(b.begin(), b.end());
  vector<int> b_count(max_val+1);
  for (int i = 0; i < m; ++i) {
    b_count[b[i]]++;
  }

  int ans = 0;
  int c = 0;
  vector<int> a_count(max_val+1);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0 && a[i] <= max_val) {
      int x = a[i];
      if (a_count[x] < b_count[x]) {
        c++;
      }
      a_count[x]++;
    }

    if (i >= m) {
      int x = a[i-m];
      if (x >= 0 && x <= max_val) {
        a_count[x]--;
        if (a_count[x] < b_count[x]) {
          c--;
        }
      }
    }

    if (i >= m-1) {
      if (c >= k) {
        ans++;
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
