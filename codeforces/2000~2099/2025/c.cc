#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  vector<pair<int,int>> c(count.begin(), count.end());
  int len = 0;
  int ans = 0;
  for (int i = 0, j = 0; i < (int)c.size(); ++i) {
    if (j <= i) {
      len = c[i].second;
      j = i;
    }
    while (j+1 < (int)c.size() && (j+2-i) <= k && c[j+1].first == c[j].first + 1) {
      j++;
      len += c[j].second;
    }
    ans = max(ans, len);
    len -= c[i].second;
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
