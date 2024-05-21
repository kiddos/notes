#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 lcm(i64 x, i64 y) {
  i64 g = gcd(x, y);
  return x * y / g;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  constexpr int MAX_BIT = 20;
  vector<int> last(MAX_BIT);
  vector<int> max_dist(MAX_BIT, 1);
  for (int i = 1; i <= n; ++i) {
    for (int b = 0; b < MAX_BIT; ++b) {
      if (a[i] & (1 << b)) {
        int dist = i - last[b];
        max_dist[b] = max(max_dist[b], dist);

        last[b] = i;
      }
    }
  }
  for (int b = 0; b < MAX_BIT; ++b) {
    if (last[b]) {
      max_dist[b] = max(max_dist[b], n + 1 - last[b]);
    }
  }

  int l = 1;
  for (int b = 0; b < MAX_BIT; ++b) {
    l = max(l, max_dist[b]);
  }
  cout << l << endl;
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
