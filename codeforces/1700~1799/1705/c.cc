#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
void solve() {
  int n = 0, c = 0, q = 0;
  cin >> n >> c >> q;
  string s;
  cin >> s;
 
  vector<pair<ll,ll>> interval = {{1, n}};
  vector<pair<ll,ll>> copy;
  for (int i = 0; i < c; ++i) {
    ll l = 0, r = 0;
    cin >> l >> r;
    copy.push_back({l, r});
 
    ll a = interval.back().second + 1;
    ll b = a + r-l;
    interval.push_back({a, b});
  }
 
  // for (auto& [a, b] : interval) {
  //   cout << a << " ," << b << endl;
  // }
 
  function<char(ll)> find = [&](ll k) {
    if (k <= n) {
      return s[k-1];
    }
 
    int l = 0, r = interval.size()-1;
    int index = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (interval[mid].first <= k) {
        index = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    ll offset = k - interval[index].first;
    ll k2 = copy[index-1].first + offset;
    // cout << "copy: " << copy[index-1].first << ", " << copy[index-1].second << endl;
    // cout << "offset=" << offset << endl;
    // cout << "index=" << index << endl;
    // cout << "k2=" << k2 << endl;
    return find(k2);
  };
 
  while (q-- > 0) {
    ll k = 0;
    cin >> k;
 
    char ans = find(k);
    cout << ans << endl;
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
