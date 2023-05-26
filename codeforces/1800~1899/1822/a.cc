#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int index = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i]+i > t) continue;
    if (index < 0 || b[i] > b[index]) {
      index = i;
    }
  }
  if (index < 0) {
    cout << "-1" << endl;
  } else {
    cout << index+1 << endl;
  }
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
