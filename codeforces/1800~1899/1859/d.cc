#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int, 4>> portals;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0, a = 0, b = 0;
    cin >> l >> r >> a >> b;
    portals.push_back({l, r, a, b});
  }

  int q = 0;
  cin >> q;
  vector<int> ans(q);
  vector<int> query;
  for (int i = 0; i < q; ++i) {
    int x = 0;
    cin >> x;
    query.push_back(x);
    ans[i] = x;
  }

  vector<array<int, 3>> events;
  vector<int> can_reach(n);
  for (int i = 0; i < n; ++i) {
    auto [l, r, a, b] = portals[i];
    events.push_back({l, 0, i});
    events.push_back({b, 2, i});
    can_reach[i] = max(l, b);
  }
  for (int i = 0; i < q; ++i) {
    events.push_back({query[i], 1, i});
  }

  sort(events.rbegin(), events.rend());

  multiset<int> s;
  for (int i = 0; i < events.size(); ++i) {
    auto [pos, type, index] = events[i];
    // cout << "pos=" << pos << endl;
    if (type == 2) {
      // enter
      if (!s.empty()) {
        can_reach[index] = max(can_reach[index], *s.rbegin());
        // cout << "can reach=" << can_reach[index];
      }
      s.insert(can_reach[index]);
    } else if (type == 0) {
      // leave
      s.erase(s.find(can_reach[index]));
    } else if (type == 1) {
      if (!s.empty()) {
        ans[index] = max(ans[index], *s.rbegin());
      }
    }
  }
  
  for (int i = 0; i < q; ++i) {
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
