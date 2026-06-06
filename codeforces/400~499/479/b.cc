#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert({a[i], i+1});
  }
  vector<pair<int,int>> ans;
  for (int t = 0; t < k; ++t) {
    auto smallest = *s.begin();
    auto largest = *s.rbegin();
    if (smallest.second == largest.second) {
      break;
    }
    if (largest.first - smallest.first <= 1) {
      break;
    }
    s.erase(s.begin());
    s.erase(prev(s.end()));
    s.insert({smallest.first+1, smallest.second});
    s.insert({largest.first-1, largest.second});
    ans.push_back({largest.second, smallest.second});
  }

  auto smallest = *s.begin();
  auto largest = *s.rbegin();
  int diff = largest.first - smallest.first;
  cout << diff << " " << ans.size() << endl;
  for (auto [i1, i2] : ans) {
    cout << i1 << " " << i2 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
