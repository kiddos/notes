#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }

  map<int, int> last_seen;
  int left = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (last_seen.count(k[i])) {
      left = max(left, last_seen[k[i]]);
    }
    ans = max(ans, i - left);

    last_seen[k[i]] = i;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
