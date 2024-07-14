#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  int max_index = max_element(a.begin(), a.end()) - a.begin();
  i64 ans = 0;
  for (int i = 0; i < k; ++i) {
    if (i != max_index) {
      int split = a[i] - 1;
      int merge = a[i];
      ans += split + merge;
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
