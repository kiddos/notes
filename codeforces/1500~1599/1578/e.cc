#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, p = 0;
  cin >> h >> p;

  i64 k = 0;
  while (k+1 < h && (1LL << (k+1)) <= p) {
    k++;
  }
 
  i64 total = (1LL << h) - 1;
  i64 rest = total - (1LL << (k+1)) + 1;
  i64 ans = k+1 + (rest + p - 1) / p;
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
