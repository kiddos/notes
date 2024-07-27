#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<pair<i64,i64>> flowers;
  for (int i = 0; i < n; ++i) {
    flowers.emplace_back(a[i], c[i]);
  }
  sort(flowers.begin(), flowers.end());

  auto one = [&](i64 ai, i64 ci) -> i64 {
    i64 count = min(m / ai, ci);
    return ai * count;
  };

  auto two = [&](i64 a1, i64 c1, i64 a2, i64 c2) -> i64 {
    i64 count1 = min(m / a1, c1);
    i64 sum1 = a1 * count1;
    i64 m2 = m - sum1;
    i64 count2 = min(m2 / a2, c2);
    i64 sum2 = a2 * count2;
    i64 ans1 = sum1 + sum2;
    i64 left = m - ans1;
    ans1 += min({c2 - count2, count1, left});

    count2 = min(m / a2, c2);
    sum2 = a2 * count2;
    i64 m1 = m - sum2;
    count1 = min(m1 / a1, c1);
    sum1 = a1 * count1;
    i64 ans2 = sum1 + sum2;
    return max(ans1, ans2);
  };

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [a1, c1] = flowers[i];
    ans = max(ans, one(a1, c1));
    if (i-1 >= 0) {
      auto [a0, c0] = flowers[i-1];
      if (a1 == a0+1) {
        ans = max(ans, two(a0, c0, a1, c1));
      }
    }
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
