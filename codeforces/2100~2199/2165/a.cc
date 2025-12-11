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

  vector<int> max_vals = a;
  vector<int> next_idx(n);
  vector<bool> merged(n);
  set<array<int,2>> s;
  for (int i = 0; i < n; ++i) {
    int j = (i+1) % n;
    int val = max(a[i], a[j]);
    next_idx[i] = j;
    s.insert({val, i});
  }
  i64 ans = 0;
  while (!s.empty()) {
    auto [val, i1] = *s.begin();
    s.erase(s.begin());
    int i2 = next_idx[i1];
    if (merged[i1] || merged[i2]) {
      continue;
    }

    // cout << "merge " << i1 << ", " << i2 << endl;

    int i3 = next_idx[i2];
    max_vals[i1] = max_vals[i2] = val;
    merged[i2] = true;
    if (!merged[i3] && i3 != i1) {
      next_idx[i1] = next_idx[i2] = i3;
      s.insert({max(val, max_vals[i3]), i1});
    }
    ans += val;
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
