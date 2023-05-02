#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  if (n == 2) {
    cout << "2 1" << endl;
    return;
  }
  if (n == 3) {
    cout << "-1" << endl;
    return;
  }

  cout << n << " " << n-1 << " ";
  for (int i = 1; i < n-1; ++i) cout << i << " ";
  cout << endl;
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
