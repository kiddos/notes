#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  multiset<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert({a[i], i+1});
  }
  if (s.begin()->first == 1 && s.rbegin()->first != 1) {
    cout << "-1" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  while (s.begin()->first != s.rbegin()->first) {
    auto largest = *s.rbegin();
    auto smallest = *s.begin();
    int new_val = (largest.first + smallest.first - 1) / smallest.first;
    s.erase(prev(s.end()));
    ans.push_back({largest.second, smallest.second});
    s.insert({new_val, largest.second});
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
