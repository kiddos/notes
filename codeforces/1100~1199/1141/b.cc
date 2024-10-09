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
  int len = 0;
  int max_len = 0;
  for (int i = 0; i < n * 2; ++i) {
    if (a[i % n]) {
      len++;
    } else {
      len = 0;
    }
    max_len = max(max_len, len);
  }
  int ans = min(max_len, n);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
