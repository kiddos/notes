#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> reversed_pair(n+1);
  for (int b = 1; b <= n; ++b) {
    for (int d = b+1; d <= n; ++d) {
      if (p[d] < p[b]) {
        reversed_pair[b]++;
      }
    }
  }

  i64 ans = 0;
  vector<int> prefix(n+1);
  for (int c = 2; c <= n; ++c) {
    for (int b = 1; b < c; ++b) {
      if (p[b] > p[c]) reversed_pair[b]--;
    }
    for (int i = 1; i <= c; ++i) {
      prefix[i] = prefix[i-1] + reversed_pair[i];
    }
    for (int a = 1; a < c; ++a) {
      if (p[a] < p[c]) {
        ans += prefix[c-1] - prefix[a];
      }
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
