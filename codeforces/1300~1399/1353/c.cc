#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 500000;
vector<i64> ans(MAX_N+2);

void precompute() {
  ans[1] = 0;
  for (i64 r = 1; r <= MAX_N / 2; ++r) {
    i64 w = r * 2 + 1;
    ans[w] = ((r * 2 - 1) * 4 + 4) * r;
  }
  for (i64 x = 3; x < MAX_N; ++x) {
    ans[x] += ans[x-2];
  }
}

void solve() {
  int n = 0;
  cin >> n;
  cout << ans[n] << endl;
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
