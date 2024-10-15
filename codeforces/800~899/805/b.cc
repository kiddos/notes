#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string ans;
  for (int i = 0; i < n; i += 4) {
    ans += "aabb";
  }
  while ((int) ans.size() > n) {
    ans.pop_back();
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
