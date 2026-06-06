#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int,int> last;
  for (int i = 0; i < n; ++i) {
    last[a[i]] = i;
  }

  pair<int,int> ans = {n, -1};
  for (auto [ai, idx] : last) {
    ans = min(ans, {idx, ai});
  }
  cout << ans.second << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
