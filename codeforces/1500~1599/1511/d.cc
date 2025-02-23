#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  string base;
  for (int c1 = 0; c1 < k; ++c1) {
    for (int c2 = k-1; c2 > c1; --c2) {
      base.push_back(c2 + 'a');
      base.push_back(c1 + 'a');
    }
    base.push_back(c1 + 'a');
  }

  string ans;
  int i = 0;
  while ((int)ans.length() < n) {
    ans.push_back(base[i%base.length()]);
    i++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
