#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  string T;
  cin >> T;

  vector<bool> remain(n+1);
  for (int i = 0; i < n; ++i) remain[i+1] = T[i] == '1';

  vector<int> cost(n+1);
  ll ans = 0;
  for (int i = n; i >= 1; --i) {
    for (int j = i; j <= n; j += i) {
      if (remain[j]) {
        break;
      }
      cost[j] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += cost[i];
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
