#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1, 1);
  int start = n % 2 == 0 ? 1 : 2;
  for (int i = start; i <= n; i += 2) {
    p[i] = i+1;
    p[i+1] = i;
  }

  for (int i = 1; i <= n; ++i) cout << p[i] << " ";
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
