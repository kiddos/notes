#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_VAL = 2e5;
constexpr int BITS = 19;

int solve(int l, int r, vector<vector<int>>& prefix_sum) {
  vector<int> bits(BITS);
  for (int b = 0; b < BITS; ++b) {
    bits[b] = prefix_sum[r][b] - prefix_sum[l-1][b];
  }
  int most = *max_element(bits.begin(), bits.end());
  return r-l+1 - most;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> prefix_sum(MAX_VAL+1, vector<int>(BITS));
  for (int i = 1; i <= MAX_VAL; ++i) {
    for (int b = 0; b < BITS; ++b) {
      if (i & (1<<b)) {
        prefix_sum[i][b] = prefix_sum[i-1][b]+1;
      } else {
        prefix_sum[i][b] = prefix_sum[i-1][b];
      }
    }
  }

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int l = 0, r = 0;
    cin >> l >> r;
    int ans = solve(l, r, prefix_sum);
    cout << ans <<  '\n';
  }
  cout.flush();
  return 0;
}
