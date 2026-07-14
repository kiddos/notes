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
  map<int, i64> even = {{0, 1}};
  i64 ans = 0;
  for (int i = 0, x = 0; i < n; ++i) {
    x ^= a[i];
    if (i % 2 == 1) {
      if (even.count(x)) {
        ans += even[x];
      }
      even[x]++;
    }
  }

  map<int, i64> odd = {{0, 1}};
  for (int i = 1, x = 0; i < n; ++i) {
    x ^= a[i];
    if (i % 2 == 0) {
      if (odd.count(x)) {
        ans += odd[x];
      }
      odd[x]++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
