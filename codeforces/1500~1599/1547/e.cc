#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  vector<i64> t(k);
  for (int i = 0; i < k; ++i) {
    cin >> t[i];
  }

  priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<>> pq;
  constexpr i64 inf = numeric_limits<i64>::max();
  vector<i64> temp(n+1, inf);
  for (int i = 0; i < k; ++i) {
    pq.push({t[i], a[i]});
    temp[a[i]] = t[i];
  }

  while (!pq.empty()) {
    auto [t, idx] = pq.top();
    pq.pop();
    if (idx > 1) {
      i64 t2 = t + 1;
      int i2 = idx-1;
      if (t2 < temp[i2]) {
        temp[i2] = t2;
        pq.push({t2, i2});
      }
    }
    if (idx + 1 <= n) {
      i64 t2 = t + 1;
      int i2 = idx+1;
      if (t2 < temp[i2]) {
        temp[i2] = t2;
        pq.push({t2, i2});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << temp[i] << " ";
  }
  cout << endl;
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
