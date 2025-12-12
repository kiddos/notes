#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, q = 0;
  cin >> n >> k >> q;
  vector<array<int,2>> mexs;
  vector<array<int,2>> mins;
  for (int i = 0; i < q; ++i) {
    int c = 0, l = 0, r = 0;
    cin >> c >> l >> r;
    l--;
    r--;
    if (c == 1) {
      mins.push_back({l, r});
    } else if (c == 2) {
      mexs.push_back({l, r});
    }
  }

  sort(mexs.begin(), mexs.end());

  vector<int> should_be_mex(n);
  for (auto [l, r] : mexs) {
    for (int i = l; i <= r; ++i) {
      should_be_mex[i] = true;
    }
  }
  vector<int> ans(n, -1);
  for (auto [l, r] : mins) {
    for (int i = l; i <= r; ++i) {
      if (should_be_mex[i]) {
        ans[i] = k+1;
      }
    }
  }

  for (auto [l, r] : mexs) {
    set<int> missing;
    for (int i = 0; i < k; ++i) {
      missing.insert(i);
    }
    for (int i = l; i <= r; ++i) {
      if (ans[i] >= 0) {
        missing.erase(ans[i]);
      }
    }
    for (int i = l; i <= r; ++i) {
      if (ans[i] < 0) {
        if (!missing.empty()) {
          ans[i] = *missing.begin();
          missing.erase(missing.begin());
        }
      }
    }
  }

  for (auto [l, r] : mins) {
    for (int i = l; i <= r; ++i) {
      if (ans[i] < 0) {
        ans[i] = k;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ans[i] < 0) {
      ans[i] = k+1;
    }
  }

  for (int i = 0; i < n; ++i) {
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
