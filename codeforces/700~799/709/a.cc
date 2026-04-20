#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, b = 0, d = 0;
  cin >> n >> b >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 current_size = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b) {
      continue;
    }
    if (current_size + a[i] > d) {
      current_size = 0;
      ans++;
    } else {
      current_size += a[i];
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
