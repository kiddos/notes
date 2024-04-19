#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 3 -> [1, 2]
// 4 -> [1, 2, 1]

void solve() {
  int n = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  auto compute_ans = [&](int max_h) -> i64 {
    i64 count1 = 0, count2 = 0;
    for (int i = 0; i < n; ++i) {
      i64 days = max_h - h[i];
      count1 += days % 2;
      count2 += days / 2;
    }
    // move until c1 + x * 2 >= (c2 - x)
    // 3 * x >= c2 - c1
    i64 diff = max(0LL, count2 - count1 - 1);
    if (diff) {
      i64 change2 = (diff + 2) / 3;
      // cout << "change=" << change2 << endl;
      count2 -= change2;
      count1 += change2 * 2;
    }
    // cout << "count1=" << count1 << ", count2=" << count2 << endl;
    return max(count2 * 2, count1 * 2 - 1);
  };

  int max_h = *max_element(h.begin(), h.end());
  i64 ans = compute_ans(max_h);
  ans = min(ans, compute_ans(max_h+1));
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
