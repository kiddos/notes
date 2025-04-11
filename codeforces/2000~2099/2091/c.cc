#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> p(n);
  int offset = 0;
  for (int i = 0; i < n; ++i) {
    p[(i+offset) % n] = i+1;
    offset++;
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
  }
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
