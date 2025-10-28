#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  map<int,int> last_seen;
  int last = -1;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (last_seen.count(x[i])) {
      last = max(last, last_seen[x[i]]);
    }
    int len = i - last;
    ans += len;

    last_seen[x[i]] = i;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
