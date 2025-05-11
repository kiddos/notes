#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// a^2 = 1 + 2b
// c = 1 + b
vector<i64> cs;

constexpr i64 MAX_N = 3e9;

void precompute() {
  for (i64 a = 3; a*a <= MAX_N; a += 2) {
    i64 b = (a * a - 1) / 2;
    cs.push_back(b+1);
  }
}

void solve() {
  i64 n = 0;
  cin >> n;
  auto it = upper_bound(cs.begin(), cs.end(), n);
  int ans = it - cs.begin();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
