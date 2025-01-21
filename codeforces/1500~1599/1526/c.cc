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
  priority_queue<i64, vector<i64>, greater<>> pq;
  i64 neg = 0, pos = 0;
  int drinked = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) {
      pos += a[i];
      drinked++;
    } else {
      neg += a[i];
      pq.push(a[i]);
      while (-neg > pos) {
        neg -= pq.top();
        pq.pop();
      }
    }
    ans = max(ans, drinked + (int)pq.size());
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
