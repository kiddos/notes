#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;

vector<i64> result = {0, 1};
void precompute() {
  while (result.back() < MAX_N) {
    i64 new_size = (result.back() + 1) * 2;
    result.push_back(new_size);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  int ans = lower_bound(result.begin(), result.end(), n) - result.begin();
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
