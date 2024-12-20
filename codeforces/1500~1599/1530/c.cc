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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  auto can_be_ge = [&](int add) {
    int k = n + add;
    int keep = k - k / 4;
    vector<int> c = a, d = b;
    for (int j = 0; j < add; ++j) {
      c.push_back(100);
      d.push_back(0);
    }
    sort(c.rbegin(), c.rend());
    sort(d.rbegin(), d.rend());
    i64 total1 = 0, total2 = 0;
    for (int i = 0; i < keep; ++i) {
      total1 += c[i];
      total2 += d[i];
    }
    return total1 >= total2;
  };

  int l = 0, r = n;
  int ans = n;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (can_be_ge(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
