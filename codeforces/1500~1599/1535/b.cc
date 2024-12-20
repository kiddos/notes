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
  sort(a.begin(), a.end(), [&](int x, int y) {
    if (x % 2 == y % 2) {
      return x > y;
    } else {
      return x % 2 < y % 2;
    }
  });
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      ans += n-i-1;
    } else {
      for (int j = i+1; j < n; ++j) {
        if (gcd(a[i], a[j] * 2) > 1) {
          ans++;
        }
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
