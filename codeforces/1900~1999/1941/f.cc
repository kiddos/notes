#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> d(m);
  for (int i = 0; i < m; ++i) cin >> d[i];
  vector<int> f(k);
  for (int i = 0; i < k; ++i) cin >> f[i];

  sort(d.begin(), d.end());
  sort(f.begin(), f.end());

  vector<int> diffs = {0};
  for (int i = 1; i < n; ++i) {
    int diff = a[i] - a[i-1];
    diffs.push_back(diff);
  }
  sort(diffs.begin(), diffs.end());

  // 2 max interval
  if (diffs.back() == diffs[n-2]) {
    cout << diffs.back() << endl;
    return;
  }

  pair<i64,i64> interval;
  for (int i = 1; i < n; ++i) {
    int diff = a[i] - a[i-1];
    if (diff == diffs.back()) {
      interval = {a[i-1], a[i]};
      break;
    }
  }

  int ans = diffs.back();

  auto update_answer = [&](i64 x) {
    if (x >= interval.first && x <= interval.second) {
      int diff1 = x - interval.first;
      int diff2 = interval.second - x;
      int diff3 = diffs[n-2];
      ans = min(ans, max({diff1, diff2, diff3}));
    }
  };

  i64 middle = (interval.first + interval.second) / 2;
  for (int i = 0; i < m; ++i) {
    auto it1 = upper_bound(f.begin(), f.end(), middle-d[i]);
    if (it1 != f.begin()) {
      it1--;
      update_answer(d[i] + *it1);
    }

    auto it2 = lower_bound(f.begin(), f.end(), middle-d[i]);
    if (it2 != f.end()) {
      update_answer(d[i] + *it2);
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}