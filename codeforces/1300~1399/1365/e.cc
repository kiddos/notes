#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ans = *max_element(a.begin(), a.end());

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ans = max(ans, a[i] | a[j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      for (int k = j+1; k < n; ++k) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
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
