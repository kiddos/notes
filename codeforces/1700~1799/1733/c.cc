#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  bool good = true;
  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      good = false;
      break;
    }
  }

  if (good) {
    cout << "0" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  if (a[0] != a.back()) {
    ans.push_back({1, n});
    if ((a[0] + a.back()) % 2 == 0) {
      a[0] = a.back();
    } else {
      a.back() = a[0];
    }
  }

  for (int i = 1; i < n-1; ++i) {
    if ((a[0] + a[i]) % 2 == 1) {
      a[i] = a[0];
      ans.push_back({1, i+1});
    } else {
      a[i] = a.back();
      ans.push_back({i+1, n});
    }
  }

  cout << ans.size() << endl;
  for (auto& [l, r] : ans) {
    cout << l << " " << r << endl;
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
