#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  i64 ans = 0;
  do {
    i64 w = min(a[0], a[1]);
    i64 h = min(a[2], a[3]);
    i64 area = w * h;
    ans = max(ans, area);
  } while (next_permutation(a.begin(), a.end()));

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
