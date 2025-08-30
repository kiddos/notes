#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int q = 0;
  cin >> q;

  int id = 1;
  set<pair<int,int>> ids;
  map<int,set<pair<int,int>>> s;
  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int m = 0;
      cin >> m;
      s[m].insert({id, m});
      ids.insert({id, m});
      id++;
    } else if (t == 2) {
      auto [to_serve, m] = *ids.begin();
      ids.erase(ids.begin());
      s[m].erase({to_serve, m});
      if (s[m].empty()) {
        s.erase(m);
      }
      ans.push_back(to_serve);
    } else if (t == 3) {
      set<pair<int,int>>& largest = s.rbegin()->second;
      auto [to_serve, m] = *largest.begin();
      largest.erase(largest.begin());
      if (largest.empty()) {
        s.erase(prev(s.end()));
      }
      ids.erase({to_serve, m});
      ans.push_back(to_serve);
    }
  }

  for (int served_id : ans) {
    cout << served_id << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
