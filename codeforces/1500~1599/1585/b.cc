#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> s;
  vector<int> prev(n, -1);
  for (int i = n-1; i >= 0; --i) {
    while (!s.empty() && a[i] > a[s.back()]) {
      prev[s.back()] = i;
      s.pop_back();
    }
    s.push_back(i);
  }

  int idx = n-1;
  int ans = 0;
  while (true) {
    idx = prev[idx];
    if (idx == -1) {
      break;
    }
    ans++;
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
