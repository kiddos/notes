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
  unordered_map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> c;
  for (auto [val, val_count] : count) {
    c.push_back(val_count);
  }
  sort(c.begin(), c.end());
  vector<int> p = {0};
  for (int i = 0; i < (int) c.size(); ++i) {
    p.push_back(p.back() + c[i]);
  }
  int ans = 0;
  for (int i = 0; i < (int)c.size(); ++i) {
    int remove_prefix = p[i];
    int trim_suffix = p[c.size()] - p[i] - (c[i] * (c.size()-i));
    int left = n - trim_suffix - remove_prefix;
    ans = max(ans, left);
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
