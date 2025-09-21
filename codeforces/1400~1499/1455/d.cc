#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n-1; ++i) {
    if (a[i] > a[i+1]) {
      // find the last x > a[j-1] && a[j] > x to start
      int start = -1;
      for (int j = i; j >= 0; --j) {
        int prev = j == 0 ? numeric_limits<int>::min() : a[j-1];
        if (a[j] > x && x >= prev) {
          start = j;
          break;
        }
      }

      if (start < 0) {
        cout << "-1" << endl;
        return;
      }
      // cout << start << "~" << i << endl;
      for (int j = start; j <= i; ++j) {
        swap(x, a[j]);
        if (x != a[j]) {
          ans++;
        }
      }
    }
  }

  if (n >= 2 && a[n-1] < a[n-2]) {
    if (x >= a[n-2] && a[n-1] > x) {
      swap(a[n-1], x);
      ans++;
    } else {
      cout << "-1" << endl;
      return;
    }
  }

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

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
