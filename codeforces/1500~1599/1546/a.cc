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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> add, sub;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      add.push_back(i);
    } else if (a[i] > b[i]) {
      sub.push_back(i);
    }
  }

  vector<pair<int,int>> ans;
  while (!add.empty() && !sub.empty()) {
    int i = sub.back();
    int j = add.back();
    ans.emplace_back(i+1, j+1);
    if (--a[i] == b[i]) sub.pop_back();
    if (++a[j] == b[j]) add.pop_back();
  }
  if (!add.empty() || !sub.empty()) {
    cout << "-1" << endl;
    return;
  }
  cout << ans.size() << endl;
  for (auto [i, j] : ans) {
    cout << i << " " << j << endl;
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
