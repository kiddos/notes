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
  int need_larger = n / 2;
  int need_smaller = n - need_larger - 1;

  auto possible = [&](int x) -> bool {
    int less = 0, greater = 0;
    for (int i = 1; i < n; ++i) {
      int y = abs(a[i]);
      if (-y > x) {
        greater++;
      } else if (y < x){
        less++;
      }
    }
    return greater <= need_larger && less <= need_smaller;
  };

  bool ans = possible(a[0]) || possible(-a[0]);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
