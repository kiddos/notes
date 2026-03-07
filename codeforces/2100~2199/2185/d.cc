#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, h = 0;
  cin >> n >> m >> h;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m), c(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> c[i];
  }
  vector<int> last_update(n+1, -1);
  int last_reset = -1;
  vector<int> a0 = a;
  for (int i = 0; i < m; ++i) {
    if (last_update[b[i]] < last_reset) {
      if (a0[b[i]] + c[i] > h) {
        last_reset = i;
        a[b[i]] = a0[b[i]];
      } else {
        a[b[i]] = a0[b[i]] + c[i];
      }
    } else {
      if (a[b[i]] + c[i] > h) {
        last_reset = i;
        a[b[i]] = a0[b[i]];
      } else {
        a[b[i]] = a[b[i]] + c[i];
      }
    }
    last_update[b[i]] = i;
  }

  for (int i = 1; i <= n; ++i) {
    if (last_update[i] < last_reset) {
      a[i] = a0[i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
