#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<i64> p2(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }

  auto find_left_subset = [&](int l, int r, int idx, int d) -> int {
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (x[idx] - x[mid] >= d) {
        l = mid+1;
        ans = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  auto find_right_subset = [&](int l, int r, int idx, int d) -> int {
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (x[mid] - x[idx] >= d) {
        r = mid-1;
        ans = n-mid;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  i64 ans = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l+1; r < n; ++r) {
      int d = x[r] - x[l];
      int left_count = find_left_subset(0, l-1, l, d+1);
      int right_count = find_right_subset(r+1, n-1, r, d);

      // cout << "d=" << d << endl;
      // cout << x[l] << "," << x[r] << ": left=" << left_count << ", right=" << right_count << endl;
      ans += p2[left_count] * p2[right_count];
      ans %= MOD;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
