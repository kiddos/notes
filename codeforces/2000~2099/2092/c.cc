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

  int even_count = 0;
  for (int i = 0; i < n; ++i) {
    even_count += a[i] % 2 == 0;
  }

  if (even_count == n || even_count == 0) {
    i64 ans = *max_element(a.begin(), a.end());
    cout << ans << endl;
    return;
  }

  i64 to_even = 0, even_sum = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {
      to_even += a[i]-1;
    } else {
      even_sum += a[i];
    }
  }
  i64 ans = to_even + even_sum + 1;
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
