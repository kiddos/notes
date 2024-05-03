#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// xi = ai % ai-1
// => ai = xi + ai-1 * n
// a1 can be x2 + 1

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n+1);
  for (int i = 2; i <= n; ++i) cin >> x[i];

  constexpr int shift = 10000;
  vector<int> a(n+1);
  a[1] = shift;
  for (int i = 2; i <= n; ++i) {
    a[i] = a[i-1] + x[i];
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
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
