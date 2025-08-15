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

  auto possible = [&](int x, pair<int,int>& result) -> bool {
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) {
        b.push_back(1);
      } else {
        b.push_back(-1);
      }
    }
    vector<int> p = b;
    for (int i = 1; i < n; ++i) {
      p[i] += p[i-1];
    }
    deque<pair<int,int>> min_vals;
    min_vals.push_back({0, -1});
    for (int i = k-1; i < n; ++i) {
      if (p[i] - min_vals.front().first >= 0) {
        result.first = min_vals.front().second + 1;
        result.second = i;
        return true;
      }
      int can_use = p[i-k+1];
      while (!min_vals.empty() && min_vals.back().first > can_use) {
        min_vals.pop_back();
      }
      min_vals.push_back({can_use, i-k+1});
    }
    return false;
  };

  int l = *min_element(a.begin(), a.end());
  int r = *max_element(a.begin(), a.end());
  int ans = -1;
  pair<int,int> result;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid, result)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  cout << ans << " " << result.first+1 << " " << result.second+1 << endl;
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
