#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> b = a;
  sort(b.begin()+1, b.end());

  auto find_index = [&](int start, int x) -> int {
    for (int i = start; i <= n; ++i) {
      if (a[i] == x) {
        return i;
      }
    }
    return 0;
  };

  auto cyclic_shift = [&](int l, int r) {
    int x = a[r];
    for (int i = r; i > l; --i) {
      a[i] = a[i-1];
    }
    a[l] = x;
  };

  vector<array<int, 3>> ans;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == b[i]) {
      continue;
    }
    int idx = find_index(i, b[i]);
    cyclic_shift(i, idx);
    ans.push_back({i, idx, idx - i});
  }

  cout << ans.size() << endl;
  for (auto [l, r, d] : ans) {
    cout << l << " " << r << " " << d << endl;
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
