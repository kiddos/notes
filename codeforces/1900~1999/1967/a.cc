#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto possible = [&](i64 x) -> bool {
    i64 buy = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < x) {
        buy += x - a[i];
      }
    }
    return buy <= k;
  };

  auto find_most = [&]() -> i64 {
    i64 l = *min_element(a.begin(), a.end());
    i64 r = *max_element(a.begin(), a.end()) + k;
    i64 ans = l;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      if (possible(mid)) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  i64 most = find_most();
  i64 left = k;
  for (int i = 0; i < n; ++i) {
    if (a[i] < most) {
      left -= (most - a[i]);
    }
  }

  i64 permutations = most * n - n + 1;
  int additional = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] > most) {
      additional++;
    }
  }

  // cout << "most=" << most << endl;
  // cout << "left=" << left << endl;
  i64 ans = permutations + additional + left;

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
