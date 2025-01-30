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
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    count[a[i]%2]++;
  }
  int ans = 0;
  if (count[0]) {
    ans = count[1] + 1;
  } else {
    ans = max(count[1] - 1, 0);
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
