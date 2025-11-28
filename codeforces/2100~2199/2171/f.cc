#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  int i1 = 0;
  vector<pair<int,int>> groups;
  vector<pair<int,int>> edges;
  while (i1 < n) {
    int j1 = i1;
    pair<int,int> g = {p[i1], p[i1]};
    while (j1+1 < n && p[j1+1] >= p[j1]) {
      j1++;
      edges.emplace_back(p[j1-1], p[j1]);
      g.second = max(g.second, p[j1]);
    }
    groups.push_back(g);
    i1 = j1+1;
  }

  int size = groups.size();
  stack<int> st;
  for (int i = 0; i < size; ++i) {
    int min_val = groups[i].first;
    while (!st.empty() && st.top() < groups[i].second) {
      edges.emplace_back(st.top(), groups[i].second);
      min_val = min(min_val, st.top());
      st.pop();
    }
    st.push(min_val);
  }

  if (st.size() == 1) {
    cout << "YES" << endl;
    for (auto [u, v] : edges) {
      cout << u << " " << v << endl;
    }
  } else {
    cout << "NO" << endl;
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
