#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  int n = a.size();
  map<int, vector<int>> index;
  for (int i = 0; i < n; ++i) {
    index[a[i]].push_back(i);
  }
  multiset<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
    s.insert(i);
  }

  vector<pair<int,int>> ans(n);
  // insert the larger one first
  for (auto it = index.rbegin(); it != index.rend(); ++it) {
    for (int idx : it->second) {
      auto p = s.find(it->first);
      if (p == s.end()) {
        cout << "NO" << endl;
        return;
      }
      ans[idx].first = it->first;
      s.erase(p);
    }
  }

  // fill in the second larger
  for (auto it = index.begin(); it != index.end(); ++it) {
    for (int idx : it->second) {
      auto p = s.upper_bound(it->first);
      if (p == s.begin()) {
        cout << "NO" << endl;
        return;
      }
      auto p2 = prev(p);
      ans[idx].second = *p2;
      s.erase(p2);
    }
  }

  vector<bool> first_contains(n+1);
  for (int i = 0; i < n; ++i) {
    if (first_contains[ans[i].first]) {
      swap(ans[i].first, ans[i].second);
    }
    first_contains[ans[i].first] = true;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i].first << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i].second << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a);
  }
  return 0;
}
