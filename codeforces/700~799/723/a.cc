#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> x(3);
  for (int i = 0; i < 3; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int ans = x[2] - x[0];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
