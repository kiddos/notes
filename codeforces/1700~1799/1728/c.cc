#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  priority_queue<int> pq1, pq2;
  for (int i = 0; i < n; ++i) {
    pq1.push(a[i]);
    pq2.push(b[i]);
  }

  auto f = [](int x) -> int {
    return to_string(x).length();
  };

  int ans = 0;
  while (!pq1.empty()) {
    int aa = pq1.top();
    int bb = pq2.top();
    if (aa == bb) {
      pq1.pop();
      pq2.pop();
    } else if (aa > bb) {
      pq1.pop();
      pq1.push(f(aa));
      ans++;
    } else {
      pq2.pop();
      pq2.push(f(bb));
      ans++;
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
