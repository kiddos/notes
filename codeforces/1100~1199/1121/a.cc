#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> s(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  vector<int> c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  vector<int> max_power(m+1);
  for (int i = 1; i <= n; ++i) {
    max_power[s[i]] = max(max_power[s[i]], p[i]);
  }

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    int id = c[i];
    if (max_power[s[id]] != p[id]) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
