#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  string s;
  cin >> s;

  vector<pair<i64,i64>> ranges;
  for (int i = 0, p = 0, l = 0, r = 0; i < k; ++i) {
    if (s[i] == 'R') {
      p++;
    } else if (s[i] == 'L') {
      p--;
    }
    r = max(r, p);
    l = min(l, p);
    ranges.push_back({l, r});
  }

  sort(b.begin(), b.end());
  vector<int> alive;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    pair<i64,i64> bound;
    if (it == b.end()) {
      bound.second = 2e9;
    } else {
      bound.second = *it;
    }
    it = upper_bound(b.begin(), b.end(), a[i]);
    if (it == b.begin()) {
      bound.first = -2e9;
    } else {
      bound.first = *(--it);
    }

    int l = 0, r = k-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      auto [move_left, move_right] = ranges[mid];
      i64 x1 = move_left + a[i];
      i64 x2 = move_right + a[i];
      if (x1 > bound.first && x1 < bound.second && x2 > bound.first && x2 < bound.second) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    alive.push_back(idx+1);
  }

  vector<int> ans(k+1);
  for (int t : alive) {
    ans[t]--;
  }
  ans[0] += n;
  for (int i = 1; i < k; ++i) {
    ans[i] += ans[i-1];
  }
  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
