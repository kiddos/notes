#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  map<int, vector<int>> arrive;
  for (int i = 0; i < n; ++i) {
    arrive[l[i]].push_back(i);
  }

  vector<int> ans(n);
  int current_t = 0;
  for (auto [tl, indices] : arrive) {
    current_t = max(current_t, tl);
    for (int idx : indices) {
      if (r[idx] >= current_t) {
        ans[idx] = current_t;
        current_t++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
