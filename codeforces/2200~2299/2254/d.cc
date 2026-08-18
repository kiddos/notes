#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  map<i64,vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[b[i]].push_back(i);
  }

  if (indices.size() == 1 && !indices.count(0)) {
    cout << "-1" << endl;
    return;
  }

  vector<i64> ans(n);
  i64 known = 0;
  i64 max_so_far = 0;
  for (auto it = next(indices.begin()); it != indices.end(); ++it) {
    i64 sum = it->first;
    auto it1 = prev(it);
    int unknown_count = it1->second.size();
    i64 unknown = sum - known;
    if (unknown % unknown_count != 0) {
      cout << "-1" << endl;
      return;
    }
    i64 val = unknown / unknown_count;

    if (val <= max_so_far) {
      cout << "-1" << endl;
      return;
    }
    max_so_far = val;

    for (int i2 : it1->second) {
      ans[i2] = val;
    }
    known += unknown;
  }

  i64 current_max = *max_element(ans.begin(), ans.end());
  for (int i : prev(indices.end())->second) {
    ans[i] = current_max+1;
  }

  i64 sum = 0;
  for (auto it = indices.begin(); it != indices.end(); ++it) {
    if (sum != it->first) {
      cout << "-1" << endl;
      return;
    }
    for (int i : it->second) {
      sum += ans[i];
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
