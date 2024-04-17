#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [0, 0, 0, 0] -> [4, 4, 4, 4] how?
// [0, 1, 0, 0]
// -> [2, 2, 0, 0]
// -> [2, 2, 1, 0]
// -> [2, 3, 3, 3]
// -> [0, 3, 3, 3]
// -> [0, 0, 3, 3]
// -> [0, 0, 0, 3]
// -> [0, 1, 0, 3]
// -> [2, 2, 0, 3]
// -> [2, 0, 0, 3]
// -> [2, 1, 0, 3]
// -> [4, 4, 4, 4]

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> b = a;

  auto done = [&](int l, int r, int t) -> bool {
    for (int i = l; i <= r; ++i) {
      if (b[i] != t) {
        return false;
      }
    }
    return true;
  };

  vector<pair<int,int>> ans;
  function<void(int,int,int)> make = [&](int l, int r, int t) {
    if (done(l, r, t)) {
      return;
    }
    for (int i = l; i <= r; ++i) {
      if (b[i] != 0) {
        b[i] = 0;
        ans.emplace_back(i, i);
      }
    }

    for (int i = l, x = t; i <= r-1; ++i, --x) {
      make(i, r-1, x);
    }
    ans.emplace_back(l, r);
    for (int i = l; i <= r; ++i) {
      b[i] = t;
    }
  };

  int best = n * n;
  int best_mask = 0;
  int m = 1 << n;
  for (int mask = 0; mask < m; ++mask) {
    int j = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        total += a[i+1];
        int len = i - j;
        total += len * len;
        j = i+1;
      }
    }
    int len = n-j;
    total += len * len;

    if (total > best) {
      best = total;
      best_mask = mask;
    }
  }
  // cout << bitset<18>(best_mask) << endl;

  int j = 0;
  vector<pair<int,int>> changes;
  for (int i = 0; i < n; ++i) {
    if (best_mask & (1<<i)) {
      if (j < i) {
        changes.emplace_back(j, i-1);
      }
      j = i+1;
    }
  }
  if (j < n) {
    changes.emplace_back(j, n-1);
  }

  for (auto& [l, r] : changes) {
    // cout << "change = " << l+1 << " - " << r+1 << endl;
    make(l+1, r+1, r-l+1);
  }

  // for (int i = 1; i <= n; ++i) cout << b[i] << " ";
  // cout << endl;

  int total = accumulate(b.begin(), b.end(), 0);
  cout << total << " " << ans.size() << endl;
  for (auto& [l, r] : ans) {
    cout << l << " " << r << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
