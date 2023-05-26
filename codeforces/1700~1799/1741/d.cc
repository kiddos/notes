#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  bool not_possible = false;
  function<pair<int,int>(int,int)> divide_conq = [&](int l, int r) -> pair<int,int> {
    if (l == r) {
      return {a[l], a[l]};
    }

    int m = l + (r-l) / 2;
    auto left = divide_conq(l, m);
    auto right = divide_conq(m+1, r);
    if (left.second < right.first) {
      return {left.first, right.second};
    } else if (right.second < left.first) {
      ans++;
      return {right.first, left.second};
    } else {
      not_possible = true;
      return {min(left.first, right.first), max(left.second, right.second)};
    }
  };

  divide_conq(0, n-1);

  if (not_possible) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
