#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n), p(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> p[i];
  }
  int k = 0;
  cin >> k;
  vector<int> r(k);
  for (int i = 0; i < k; ++i) {
    cin >> r[i];
  }

  multiset<array<int,2>> tables;
  for (int i = 0; i < k; ++i) {
    tables.insert({r[i], i});
  }
  vector<array<int,3>> visits;
  for (int i = 0; i < n; ++i) {
    visits.push_back({p[i], c[i], i});
  }

  int s = 0;
  vector<pair<int,int>> assignment;
  sort(visits.rbegin(), visits.rend());
  for (auto [pi, ci, idx] : visits) {
    auto it = tables.lower_bound({ci, 0});
    if (it != tables.end()) {
      auto [ri, table_idx] = *it;
      s += pi;
      assignment.push_back({idx+1, table_idx + 1});
      tables.erase(it);
    }
  }
  cout << assignment.size() << " " << s << endl;
  for (auto [i1, i2] : assignment) {
    cout << i1 << " " << i2 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
