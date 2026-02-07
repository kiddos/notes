#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, a = 0, b = 0;
  cin >> n >> m >> a >> b;
  int ans = n * a;
  int greedy = n / m;
  int left = n - greedy * m;
  ans = min(ans, greedy * b + left * a);
  ans = min(ans, (greedy + 1) * b);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
