#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  multiset<int> s(b.begin(), b.end());
  vector<int> can_pair;
  for (int i = 0; i < n; ++i) {
    auto it = s.find(a[i]);
    if (it == s.end()) {
      can_pair.push_back(a[i]);
    } else {
      s.erase(it);
    }
  }

  sort(can_pair.begin(), can_pair.end());
  int require = s.size();
  int can_make = can_pair.size() / 2;
  if (require > can_make) {
    cout << "NO" << endl;
    return;
  }

  int size = can_pair.size();
  multiset<pair<int,int>> value_range;
  for (int i = 0; i < size / 2; ++i) {
    int j = i + (size+1) / 2;
    value_range.insert({can_pair[j], can_pair[i]});
  }

  for (int bj : s) {
    pair<int,int> key = {bj, -1};
    auto it = value_range.lower_bound(key);
    if (it == value_range.end()) {
      cout << "NO" << endl;
      return;
    }
    if (it->second > bj) {
      cout << "NO" << endl;
      return;
    }
    value_range.erase(it);
  }

  cout << "YES" << endl;
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
