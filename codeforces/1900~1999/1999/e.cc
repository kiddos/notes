#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;

vector<int> ops(MAX_N+1);
vector<int> p(MAX_N+1);

void precompute() {
  auto get_ops = [&](int x) -> int {
    int op = 0;
    while (x > 0) {
      op += 1;
      x /= 3;
    }
    return op;
  };

  for (int i = 1; i <= MAX_N; ++i) {
    ops[i] = get_ops(i);
    p[i] = p[i-1] + ops[i];
  }
}

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;

  i64 ans = p[r] - p[l-1] + ops[l];
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
