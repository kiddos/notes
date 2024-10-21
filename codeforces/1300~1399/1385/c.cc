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

  auto possible = [&](int remove) -> bool {
    int l = remove, r = n-1;
    vector<int> c;
    while (l <= r) {
      if (a[l] <= a[r]) {
        c.push_back(a[l++]);
      } else {
        c.push_back(a[r--]);
      }
    }

    for (int i = 1; i < (int)c.size(); ++i) {
      if (c[i-1] > c[i]) {
        return false;
      }
    }
    return true;
  };

  int l = 0, r = n - 1;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
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
