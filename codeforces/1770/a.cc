#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      cin >> a;
      pq.push(a);
    }

    for (int i = 0; i < m; ++i) {
      int b = 0;
      cin >> b;
      pq.pop();
      pq.push(b);
    }

    ll ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    cout << ans << endl;
  }
  return 0;
}
