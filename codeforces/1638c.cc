#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& p) {
  int n = p.size();
  vector<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    s.push_back({p[i], p[i]});

    while (s.size() > 1 && s[s.size()-2].second > s.back().first) {
      s[s.size()-2].first = min(s[s.size()-2].first, s.back().first);
      s[s.size()-2].second = max(s[s.size()-2].second, s.back().second);
      s.pop_back();
    }
  }
  return s.size();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    int ans = solve(p);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
