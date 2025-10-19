#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p5 = {1};
  for (int i = 0; i < 20; ++i) {
    p5.push_back(p5.back() * 5);
  }
  i64 ans = 0;
  for (int p = 1; p < (int)p5.size(); ++p) {
    ans += n / p5[p];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
