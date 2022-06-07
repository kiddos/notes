#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll solve(vector<ll>& appear, vector<ll>& health) {
  int n = appear.size();
  vector<pair<ll, ll>> intervals;
  for (int i = 0; i < n; ++i) {
    ll start = appear[i] - health[i] + 1;
    ll end = appear[i];
    intervals.emplace_back(start, end);
  }
  sort(intervals.begin(), intervals.end(), [&](auto& i1, auto& i2) {
    return i1.first == i2.first ? i1.second > i2.second : i1.first < i2.first;
  });

  vector<pair<ll, ll>> merged;
  for (int i = 0; i < n; ++i) {
    if (merged.empty() || merged.back().second < intervals[i].first) {
      merged.push_back(intervals[i]);
    } else {
      merged.back().second = max(merged.back().second, intervals[i].second);
    }
  }

  ll ans = 0;
  for (auto& [start, end] : merged) {
    ll len = end - start + 1;
    ans += len * (len + 1) / 2;
  }
  return ans;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<ll> appear(n);
    vector<ll> health(n);
    for (int i = 0; i < n; ++i) {
      cin >> appear[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> health[i];
    }
 
    ll ans = solve(appear, health);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
