#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll l = 0, r = 0;
  cin >> l >> r;

  auto get_set_size = [&](int start, int p) -> int {
    int count = 1;
    while (true) {
      if (start * p > r) break;
      start *= p;
      count++;
    }
    return count;
  };

  int max_size = get_set_size(l, 2);

  const int MOD = 998244353;
  ll max_count = 0;
  int k = r / (pow(2, max_size-1));
  if (k >= l) {
    max_count += k-l+1;
  }
  if (max_size >= 2) {
    int k = r / (pow(2, max_size-2) * 3);
    if (k >= l) {
      max_count += (k-l+1) * (max_size-1);
      max_count %= MOD;
    }
  }
  cout << max_size << " " << max_count << endl;
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
