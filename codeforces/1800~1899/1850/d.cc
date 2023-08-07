#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  int i = 0;
  int max_len = 0;
  while (i < n) {
    int j = i+1;
    while (j < n && a[j]-a[j-1] <= k) {
      j++;
    }

    int len = j-i;
    max_len = max(max_len, len);
    i = j;
  }

  int ans = n - max_len;
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
