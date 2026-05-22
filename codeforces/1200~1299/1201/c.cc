#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto possible = [&](i64 x) -> bool {
    i64 require = 0;
    for (int i = n / 2; i < n; ++i) {
      if (a[i] < x) {
        require += x - a[i];
      }
    }
    return require <= k;
  };

  i64 median = a[n/2];
  i64 l = median, r = median + k;
  i64 ans = l;
  while (l <= r) {
    i64 x = l + (r-l) / 2;
    if (possible(x)) {
      ans = x;
      l = x+1;
    } else {
      r = x-1;
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
