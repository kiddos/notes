#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  string a, b;
  cin >> a >> b;

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int c1 = a[i] - '0';
    int c2 = b[i] - '0';
    if (c1 != 1-c2) {
      ok = false;
    }
  }

  if (!ok && a != b) {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  if (a[0] != b[0]) {
    ans.push_back({1, n});
    a = b;
  }

  vector<int> ops(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      if (i == 0) {
        ans.push_back({1, n});
        ans.push_back({2, n});
      } else {
        ops[i]++;
        ops[i-1]++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ops[i] % 2 == 1) {
      ans.push_back({1, i+1});
    }
  }

  cout << "YES" << endl;
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
