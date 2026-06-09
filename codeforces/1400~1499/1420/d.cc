#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = (x * x);
    x %= MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<i64> inv_f(n+1, 1);
  inv_f[n] = power(f[n], MOD-2);
  for (int i = n-1; i > 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int N, int K) -> i64 {
    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= MOD;
    ans *= inv_f[N-K];
    ans %= MOD;
    return ans;
  };

  vector<int> points;
  vector<array<int,3>> events;
  for (int i = 0; i < n; ++i) {
    events.push_back({l[i], 1, i});
    events.push_back({r[i]+1, -1, i});
    points.push_back(l[i]);
    points.push_back(r[i]);
    points.push_back(r[i]+1);
  }
  sort(events.begin(), events.end());
  sort(points.begin(), points.end());
  points.resize(unique(points.begin(), points.end()) - points.begin());
  int size = points.size();
  set<int> on;
  i64 ans = 0;
  for (int i = 0, j = 0; i < size; ++i) {
    while (j < (int)events.size() && events[j][0] <= points[i]) {
      auto [p, e, idx] = events[j];
      j++;
      if (e > 0) {
        int current_size = on.size();
        if (current_size >= k-1) {
          ans += C(current_size, k-1);
          ans %= MOD;
        }
        on.insert(idx);
      } else {
        on.erase(idx);
      }
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
