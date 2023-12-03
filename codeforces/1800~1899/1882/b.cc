#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> S;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    cin >> k;
    i64 bits = 0;
    for (int j = 0 ; j < k; ++j) {
      i64 s = 0;
      cin >> s;
      bits |= (1LL << s);
    }
    S.push_back(bits);
  }

  i64 all_bits = 0;
  for (int i = 0; i < n; ++i) all_bits |= S[i];

  int ans = 0;
  vector<i64> dp = {0};
  for (int b = 0; b <= 50; ++b) if (all_bits & (1LL << b)) {
    i64 mask = 0;
    for (int i = 0; i < n; ++i) {
      if ((S[i] & (1LL << b)) == 0) {
        mask |= S[i];
      }
    }
    if (mask != all_bits) {
      ans = max(ans, (int) bitset<64>(mask).count());
    }
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
