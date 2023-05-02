#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto possible = [&](ll sum) -> int {
    ll current = sum;
    int ans = 0;
    int size = 0;
    for (int i = 0; i < n; ++i) {
      if (current - a[i] < 0) return -1;

      if (current - a[i] == 0) {
        current = sum;
        ans = max(ans, ++size);
        size = 0;
      } else {
        current -= a[i];
        ans = max(ans, ++size);
      }
    }
    
    if (current == sum) {
      return ans;
    }
    return -1;
  };

  ll prefix = 0;
  int ans = n;
  for (int i = 0; i < n; ++i) {
    prefix += a[i];
    int result = possible(prefix);
    if (result >= 0) {
      ans = min(ans, result);
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
