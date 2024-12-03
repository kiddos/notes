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
  if (n % 2 == 1) {
    cout << "-1" << endl;
    return;
  }
  vector<pair<int,int>> ans;
  for (int i = 0; i < n; i += 2) {
    if (a[i] == a[i+1]) {
      ans.emplace_back(i, i+1);
    } else {
      ans.emplace_back(i, i);
      ans.emplace_back(i+1, i+1);
    }
  }

  cout << ans.size() << endl;
  for (auto [l, r] : ans) {
    cout << l+1 << " " << r+1 << endl;
  }
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
