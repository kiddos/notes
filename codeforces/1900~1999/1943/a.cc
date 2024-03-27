#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> counts(n+1);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0 && a[i] <= n) {
      counts[a[i]]++;
    }
  }
  int appear_once = 0;
  for (int x = 0; x <= n; ++x) {
    if (counts[x] == 0) {
      cout << x << endl;
      return;
    } else if (counts[x] == 1) {
      if (appear_once) {
        cout << x << endl;
        return;
      } else {
        appear_once++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}