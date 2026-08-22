#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 total = accumulate(a.begin(), a.end(), 0LL);
 
  map<i64,int> p;
  p[0] = -1;
  i64 prefix = 0;
  for (int i = 0; i < n; ++i) {
    prefix += a[i];
    if (i == n-1) {
      auto it = p.begin();
      if (it->second == -1) {
        it = next(it);
      }
      i64 max_sum = prefix - it->first;
      if (max_sum >= total) {
        cout << "NO" << endl;
        return;
      }
    } else {
      i64 max_sum = prefix - p.begin()->first;
      if (max_sum >= total) {
        cout << "NO" << endl;
        return;
      }
    }
    p[prefix] = i;
  }
  cout << "YES" << endl;
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
