#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, vector<int>& b, int k) {
  int n = a.size();
  vector<pair<int, int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], b[i]});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    if (k >= p[i].first) {
      k += p[i].second;
    }
  }
  return k;
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int ans = solve(a, b, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
