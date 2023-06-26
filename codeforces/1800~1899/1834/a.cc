#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int pos = 0, neg = 0;
  for (int i = 0; i < n; ++i) {
    pos += a[i] > 0;
    neg += a[i] < 0;
  }

  if (pos >= neg && neg % 2 == 0) {
    cout << "0" << endl;
    return;
  }

  int ans = 0;
  while (pos < neg || neg % 2 == 1) {
    pos++;
    neg--;
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
