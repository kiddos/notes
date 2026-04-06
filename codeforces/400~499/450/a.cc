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
  deque<pair<int,int>> d;
  for (int i = 0; i < n; ++i) {
    d.push_back({a[i], i});
  }
  int ans = 0;
  while (!d.empty()) {
    auto [ai, i] = d.front();
    d.pop_front();
    if (ai > m) {
      d.push_back({ai-m, i});
    }
    ans = i;
  }
  cout << ans+1 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
