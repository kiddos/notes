#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_square(i64 x) {
  i64 s = sqrt(x);
  return s * s == x;
}

bool is_valid(vector<int>& ans) {
  int n = ans.size();
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += ans[i];
    if (is_square(sum)) {
      return false;
    }
  }
  return true;
}

void solve() {
  i64 n = 0;
  cin >> n;
  i64 sum = (1 + n) * n / 2;
  if (is_square(sum)) {
    cout << "-1" << endl;
    return;
  }

  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 1);
  auto rng = std::default_random_engine{};
  while (!is_valid(ans)) {
    shuffle(ans.begin(), ans.end(), rng);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
