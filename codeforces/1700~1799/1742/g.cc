#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<bool> used(n);
  int o = 0;
  vector<int> ans;
  for (int i = 30; i >= 0; --i) {
    if (o & (1<<i)) {
      continue;
    }

    int max_o = o;
    int index = 0;
    for (int i = 0; i < n; ++i) if (!used[i]) {
      int o2 = o | a[i];
      if (o2 >= max_o) {
        index = i;
        max_o = o2;
      }
    }

    if (used[index]) continue;

    used[index] = true;
    ans.push_back(a[index]);
    o |= a[index];
  }

  for (int i = 0; i < n; ++i) if (!used[i]) {
    ans.push_back(a[i]);
  }
  
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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
