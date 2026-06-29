#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1 1  1  1   1   1
// 1 2  3  4   5   6
// 1 3  6 10  15  21
// 1 4 10 20  35  56
// 1 5 15 35  70 126
// 1 6 21 56 126 252

// 1 1  1  1   1   1
// 1 2  3  4   5   6
// 1 3  6 10  15  21
// 1 4 10 20  35  56
// 1 5 15 35   X  56
// 1 6 21 56  56 112

// 1 1  1  1   1   1
// 1 2  3  4   5   6
// 1 3  6 10  15  21
// 1 4 10 20  35  56
// 1 5  0 20  55 111
// 1 6  6 26  81 192

// 1 1  1  1   1   1
// 1 2  3  4   5   6
// 1 3  6 10  15  21
// 1 4 10 20  35  56
// 1 5  0 20   0  56
// 1 6  6 26  26  82


constexpr int MOD = 1e9 + 7;
void mod_sub(i64& x, i64 y) {
  x += MOD - y;
  x %= MOD;
}

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    n >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}

void solve() {
  int h = 0, w = 0, n = 0;
  cin >> h >> w >> n;
  vector<int> r(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i] >> c[i];
    r[i]--;
    c[i]--;
  }

  for (int i = 0; i < n; ++i) {
    if (r[i] == h-1 && c[i] == w-1) {
      cout << "0" << endl;
      return;
    }
  }

  vector<pair<int,int>> coords;
  for (int i = 0; i < n; ++i) {
    coords.push_back({r[i], c[i]});
  }
  coords.push_back({h-1, w-1});
  sort(coords.begin(), coords.end(), [&](auto& c1, auto& c2) {
    int h1 = c1.first + c1.second;
    int h2 = c2.first + c2.second;
    return h1 < h2;
  });

  int max_n = w + h;
  vector<i64> f(max_n+1, 1);
  for (int i = 2; i <= max_n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<i64> inv_f(max_n+1, 1);
  inv_f[max_n] = power(f[max_n], MOD-2);
  for (int i = max_n-1; i > 1; --i) {
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

  vector<i64> values(n+1);
  for (int i = 0; i <= n; ++i) {
    auto [ri, ci] = coords[i];
    int N = ri+ci;
    int K = N - ri;
    values[i] = C(N, K);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (coords[j].first >= coords[i].first && coords[j].second >= coords[i].second) {
        int dy = coords[j].first - coords[i].first;
        int dx = coords[j].second - coords[i].second;
        int N = dy + dx;
        int K = N - dy;
        // cout << "C(" << N << "," << K << ")=" << C(N, K) << endl;
        i64 remove = (values[i] * C(N, K)) % MOD;
        // cout << "remove " << remove << " from " << coords[j].first << "," << coords[j].second << endl;
        mod_sub(values[j], remove);
      }
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << coords[i].first << "," << coords[i].second << " value=" << values[i] << endl;
  // }

  i64 ans = values.back();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
