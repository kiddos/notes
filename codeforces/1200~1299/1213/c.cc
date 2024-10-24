#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> rounds = {
  0, 10, 5, 10, 5, 2, 5, 10, 5, 10
};

vector<i64> sum_per_round = {
  0, 45, 20, 45, 20, 5, 20, 45, 20, 45,
};

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  int last_digit = m % 10;
  if (last_digit == 0) {
    cout << "0" << endl;
    return;
  }

  i64 divisable_count = n / m;
  // cout << "divisable count: " << divisable_count <<endl;
  // cout << last_divisable << endl;
  i64 r = rounds[last_digit];
  i64 ans = divisable_count / r * sum_per_round[last_digit];
  // cout << "ans=" << ans << endl;
  // cout << "x=" << divisable_count / r * r * m << endl;
  for (i64 x = divisable_count / r * r * m; x <= n; x += m) {
    ans += x % 10;
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
