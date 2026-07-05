#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 C(int n, int k) {
  if (k < 0 || k > n) return 0;
  if (k == 0 || k == n) return 1;
  if (k > n / 2) k = n - k;
  i64 res = 1;
  for (int i = 1; i <= k; ++i) {
    res = res * (n - i + 1) / i;
  }
  return res;
}

void solve() {
  int n = 0;
  cin >> n;
  i64 ans = C(n, 5) + C(n, 6) + C(n, 7);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
