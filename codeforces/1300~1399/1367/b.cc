#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> incorrect(2);
  for (int i = 0; i < n; ++i) {
    if (i % 2 != a[i] % 2) {
      incorrect[i % 2]++;
    }
  }
  if (incorrect[0] != incorrect[1]) {
    cout << "-1" << endl;
    return;
  }
  cout << incorrect[0] << endl;
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
