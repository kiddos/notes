#include <bits/stdc++.h>

using namespace std;

bool solve(int l, int r, int k) {
  int nums = r-l+1;
  if (nums == 1 && l > 1) return true;

  int odd = nums - (r / 2 - (l-1) / 2);
  return odd <= k;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int l = 0, r = 0, k = 0;
    cin >> l >> r >> k;
    bool ans = solve(l, r, k);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
