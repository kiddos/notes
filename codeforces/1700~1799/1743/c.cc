#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
  int n = 0;
  cin >> n;
  string lids;
  cin >> lids;
 
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
 
  priority_queue<int, vector<int>, less<>> pq;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (lids[i] == '1') {
      pq.push(a[i]);
      ans += pq.top();
      pq.pop();
    } else {
      while (!pq.empty()) pq.pop();
      pq.push(a[i]);
    }
  }
  cout << ans << endl;
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
