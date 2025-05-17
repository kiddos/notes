#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int x = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] != -1) {
      x = a[i] + b[i];
      break;
    }
  }

  if (x < 0) {
    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    int max_x = min_a + k;
    int min_x = max_a;
    int ans = max(max_x - min_x + 1, 0);
    cout << ans << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      if (b[i] == -1) {
        int bi = x - a[i];
        if (bi < 0 || bi > k) {
          cout << "0" << endl;
          return;
        }
      } else {
        if (b[i] + a[i] != x) {
          cout << "0" << endl;
          return;
        }
      }
    }
    cout << "1" << endl;
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
