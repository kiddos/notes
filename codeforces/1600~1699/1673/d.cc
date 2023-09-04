#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> get_factors(i64 r) {
  i64 s = sqrt(r);
  vector<i64> f;
  for (int d = 1; d <= s; ++d) {
    if (r % d == 0) {
      f.push_back(r / d);
      f.push_back(d);
    }
  }
  sort(f.begin(), f.end());
  f.erase(unique(f.begin(), f.end()), f.end());
  return f;
}

void solve() {
  i64 b = 0, q = 0, y = 0;
  cin >> b >> q >> y;
  i64 c = 0, r = 0, z = 0;
  cin >> c >> r >> z;

  if (r % q != 0) {
    cout << "0" << endl;
    return;
  }

  i64 b_min = b, b_max = b + q * (y-1);
  i64 c_min = c, c_max = c + r * (z-1);

  // C not in B
  if (abs(c_min - b_min) % q != 0) {
    cout << "0" << endl;
    return;
  }

  // C has to be within the range of B
  if (c_min < b_min || c_max > b_max) {
    cout << "0" << endl;
    return;
  }

  // [0, 2, 4, 6, 8, 10, 12, 14, 16]
  // [2, 6, 10]
  // cout << c_min << " " << b_min << " " << c_max << " " << b_max << endl;
  if (b_min > c_min - r || b_max < c_max + r) {
    cout << "-1" << endl;
    return;
  }

  constexpr int MOD = 1e9 + 7;
  vector<i64> factors = get_factors(r);
  i64 ans = 0;
  for (i64 p : factors) {
    if (lcm(p, q) == r) {
      ans += (r / p) * (r / p);
      ans %= MOD;
    }
  }
  // cout << "dont know yet" << endl;
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
