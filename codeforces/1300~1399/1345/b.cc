#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> sizes;

void precompute() {
  i64 base = 2;
  i64 total = base;
  sizes = {total};
  constexpr int MAX_N = 1000000000;
  while (total < MAX_N) {
    base += 3;
    total += base;
    sizes.push_back(total);
  }
}

void solve() {
  int n = 0;
  cin >> n;

  int ans = 0;
  while (true) {
    auto it = upper_bound(sizes.begin(), sizes.end(), n);
    if (it == sizes.begin()) {
      break;
    }
    --it;
    ans++;
    n -= *it;
  }
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
