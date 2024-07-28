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

  int i = 0;
  int ans = 0;
  while (i < n) {
    if (a[i] > 4) {
      ans++;
      i++;
    } else if (a[i] > 0 && a[i] <= 2) {
      if (i+1 < n && a[i+1] > 0 && a[i+1] <= 2) {
        // use 2x2
        ans++;
        i += 2;
      } else if (i+1 < n) {
        i++;
        int c = 0;
        while (i+1 < n && a[i] > 2 && a[i] <= 4 && a[i+1] > 2 && a[i+1] <= 4) {
          i += 2;
          c++;
        }
        ans += c * 2 + 1;
        if (i < n && a[i] > 2) {
          ans++;
        }
        i++;
      } else {
        ans++;
        i++;
      }
    } else {
      if (a[i] > 0) {
        ans++;
      }
      i++;
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
