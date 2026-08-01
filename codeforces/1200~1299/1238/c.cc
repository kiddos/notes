#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, n = 0;
  cin >> h >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  int current = h;
  int idx = 0;
  int ans = 0;
  while (idx < n) {
    if (current == p[idx]) {
      if (idx+1 < n) {
        // 8,5,...
        // it will eventually be 6,5,....
        // so go to 5-1
        current = p[idx+1]-1;
        idx += 2;
      } else {
        // ...,x
        // this can go all the way to 0
        current = 0;
        idx++;
      }
    } else {
      // 6,....
      // but current is higher
      // need to create a platform at current position
      // and eventually reach 6+1, we can reach 6-1
      ans++;
      current = p[idx] - 1;
      idx++;
    }
  }

  if (current > 0) {
    ans++;
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
