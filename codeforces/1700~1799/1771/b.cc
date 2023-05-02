#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int n, vector<pair<int,int>>& pairs) {
  vector<int> can_reach(n+1);
  for (auto& [a, b] : pairs) {
    int c = min(a, b), d = max(a, b);
    can_reach[d] = max(can_reach[d], c+1);
  }
  ll ans = 0;
  int last = 1;
  for (int p = 1; p <= n; ++p) {
    if (can_reach[p]) {
      last = max(last, can_reach[p]);
    }
    ans += p - last + 1;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int,int>> pairs(m);
    for (int i = 0; i < m; ++i) {
      cin >> pairs[i].first >> pairs[i].second;
    }
    solve(n, pairs);
  }
  return 0;
}
