#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 get_value(vector<int>& a) {
  int n = a.size();
  int min_val = a[0];
  i64 ans = min_val;
  for (int i = 1; i < n; ++i) {
    min_val = min(min_val, a[i]);
    ans += min_val;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> possible = {{0, 1}, {0, 2}, {1, 2}};
  i64 ans = get_value(a);
  for (auto [i, j] : possible) {
    if (j < n) {
      vector<int> b = a;
      b[i] += b[j];
      b[j] = 0;
      ans = min(ans, get_value(b));
    }
  }
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
