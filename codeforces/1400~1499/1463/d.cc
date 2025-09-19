#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  set<int> s;
  for (int i = 1; i <= n * 2; ++i) {
    s.insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    s.erase(b[i]);
  }

  vector<int> other(s.begin(), s.end());


  auto check_min_pair = [&](int x) -> bool {
    for (int i = 1, j = n-x; i <= x; ++i, ++j) {
      // cout << "j=" << j << ", i=" << i << endl;
      if (other[j] < b[i]) {
        return false;
      }
    }
    return true;
  };


  auto find_max_x = [&]() -> int {
    int l = 0, r = n;
    int ans = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (check_min_pair(mid)) {
        l = mid+1;
        ans = mid;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  auto check_max_pair = [&](int x) -> bool {
    for (int i = n, j = n-x-1; i > x; --i, --j) {
      // cout << "j=" << j << ", i=" << i << endl;
      if (other[j] > b[i]) {
        return false;
      }
    }
    return true;
  };

  auto find_min_x = [&]() -> int {
    int l = 0, r = n;
    int ans = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (check_max_pair(mid)) {
        r = mid-1;
        ans = mid;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };


  int max_x = find_max_x();
  int min_x = find_min_x();
  // cout << "max_x=" << max_x << ", min_x=" << min_x << endl;
  int ans = max_x - min_x + 1;

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
