#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  set<pair<int,int>> used;
  vector<pair<int,int>> ans;
  for (int i = n; i > 1; --i) {
    for (int j = c[i]-1; j >= 1; --j) {
      pair<int,int> key = {c[i], j};
      if (!used.count(key)) {
        ans.push_back(key);
        used.insert(key);
      }
    }
    vector<int> o;
    for (int j = 1; j < i; ++j) {
      o.push_back(c[j]);
    }
    sort(o.begin(), o.end());
    for (int j : o) {
      pair<int,int> key = {j, c[i]};
      if (!used.count(key)) {
        ans.push_back(key);
        used.insert(key);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto [x, y]: ans) {
    cout << x << " " << y << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
