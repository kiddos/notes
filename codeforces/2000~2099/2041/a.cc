#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  int ans = 15 - accumulate(a.begin(), a.end(), 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
