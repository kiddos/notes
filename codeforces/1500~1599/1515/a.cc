#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  sort(w.begin(), w.end());

  vector<int> p = w;
  for (int i = 1; i < n; ++i) {
    p[i] += p[i-1];
  }
  if (p.back() == x) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (p[i] == x) {
      swap(w[i], w[n-1]);
      break;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << w[i] << " ";
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
