#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, h = 0, m = 0;
  cin >> n >> h >> m;
  vector<int> l(m), r(m), x(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> x[i];
  }

  vector<array<int,3>> events;
  for (int i = 0; i < m; ++i) {
    events.push_back({l[i], 1, x[i]});
    events.push_back({r[i]+1, 0, x[i]});
  }
  sort(events.begin(), events.end());
  multiset<int> limits;
  i64 ans = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < (int)events.size() && events[j][0] <= i) {
      if (events[j][1]) {
        limits.insert(events[j][2]);
      } else {
        limits.erase(limits.find(events[j][2]));
      }
      j++;
    }
    i64 height = limits.empty() ? h : *limits.begin();
    ans += height * height;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
