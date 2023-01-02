#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& a, vector<int>& ans) {
  int n = a.size();
  vector<pair<int,int>> building;
  vector<int> offsets;
  int offset = 1;
  while (offsets.size() < n) {
    offsets.push_back(offset);
    if (offsets.size() < n) {
      offsets.push_back(-offset);
    }
    offset++;
  }

  for (int i = 0; i < n; ++i) {
    building.push_back({a[i], i});
  }

  ll total = 0;
  sort(building.rbegin(), building.rend());
  for (int i = 0; i < n; ++i) {
    ans[building[i].second+1] = offsets[i];
    total += (ll)abs(offsets[i]) * building[i].first * 2;
  }
  return total;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> ans(n+1);
    ll dist = solve(a, ans);
    cout << dist << '\n';
    for (int aa : ans) cout << aa << ' ';
    cout << '\n';
  }
  cout.flush();
  return 0;
}
