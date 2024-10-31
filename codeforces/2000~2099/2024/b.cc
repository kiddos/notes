#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto count_can_drop = [&](int round) -> i64 {
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += min(a[i], round);
    }
    return ans;
  };

  int l = 0, r = *max_element(a.begin(), a.end());
  int round = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    i64 total = count_can_drop(mid);
    if (total >= k) {
      round = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  // cout << "round=" << round << endl;

  i64 total = count_can_drop(round);
  i64 extra_can = total - k;
  i64 button_press = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= round) {
      button_press += round;
    } else {
      button_press += a[i] + 1;
    }
  }
  button_press -= extra_can;
  cout << button_press << endl;
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
