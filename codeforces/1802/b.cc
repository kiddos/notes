#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int female = 0, male = 0, unknown = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 1) {
      unknown++;
    } else if (b[i] == 2) {
      int total = female + male + unknown;
      if (total) {
        female = total - 1;
        male = 1;
      } else {
        female = male = 0;
      }
      unknown = 0;
    }
    // cout << "female: " << female << ", male: "<< male << endl;

    int require = (female + 1) / 2 + (male+1) / 2 + unknown;
    ans = max(ans, require);
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
