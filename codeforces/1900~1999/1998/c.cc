#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  // take the largest a with b = 0
  // and find the largest median of c
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 0) {
      if (idx < 0 || a[i] > a[idx]) {
        idx = i;
      }
    }
  }

  auto find_max_median = [&](vector<pair<i64, int>> &c, int k) -> i64 {
    sort(c.rbegin(), c.rend());
    i64 max_val = c[0].first;
    i64 min_val = c.back().first;
    i64 l = min_val, r = max_val + k;

    auto possible = [&](int med, int quota) -> bool  {
      int require_size = c.size() / 2 + 1;
      int count = 0;
      for (int i = 0; i < (int)c.size(); ++i) {
        if (c[i].first >= med) {
          count++;
        } else if (c[i].second) {
          i64 missing = med - c[i].first;
          if (quota >= missing) {
            quota -= missing;
            count++;
          }
        }
      }
      return count >= require_size;
    };

    i64 ans = l;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      if (possible(mid, k)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  };

  i64 ans = 0;
  if (idx >= 0) {
    vector<pair<i64,int>> c;
    for (int i = 0; i < n; ++i) {
      if (i != idx) {
        c.emplace_back(a[i], b[i]);
      }
    }

    i64 max_median = find_max_median(c, k);
    ans = max(ans, max_median + a[idx]);
    // cout << "max median = " << max_median << endl;
  }

  // take the largest a with b = 1
  // put k all to that number
  // find the medium to c
  idx = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1) {
      if (idx < 0 || a[i] > a[idx]) {
        idx = i;
      }
    }
  }

  if (idx >= 0) {
    vector<pair<i64,int>> c;
    for (int i = 0; i < n; ++i) {
      if (i != idx) {
        c.emplace_back(a[i], b[i]);
      }
    }

    i64 median = find_max_median(c, 0);
    ans = max(ans, median + a[idx] + k);
    // cout << "median = " << median << endl;
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
