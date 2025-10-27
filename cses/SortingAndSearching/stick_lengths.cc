#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  vector<i64> prefix = {0};
  for (int i = 0; i < n; ++i) {
    prefix.push_back(p[i] + prefix.back());
  }

  i64 ans = numeric_limits<i64>::max();
  for (int i = 0; i < n; ++i) {
    i64 pre = (p[i] * (i+1)) -  prefix[i+1];
    i64 suf = (prefix[n] - prefix[i]) - (p[i] * (n-i));
    ans = min(ans, pre + suf);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
